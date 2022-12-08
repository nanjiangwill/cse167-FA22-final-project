#include "RayTracer.h"
using namespace RayTracer;
using namespace std;
using namespace glm;
void RayTracer::Raytrace(Camera cam, RTScene rtscene, Image &image)
{
    int Width = image.width;
    int Height = image.height;
    for (int j = 0; j < Height; j++)
    {
        for (int i = 0; i < Width; i++)
        {
            Ray ray = RayThruPixel(cam, i, j, Width, Height);
            // cout << "ray start point is : " << ray.p0[0] << endl;
            Intersection hit = Intersect(ray, &rtscene);
            // cout << "test hit for intersection " << hit.dist << endl;
            image.pixels[j * Width + i] = FindColor(hit, &rtscene, 3);
            cout << (j * Width + i) << endl;

        }
    }
}

Ray RayTracer::RayThruPixel(Camera cam, int i, int j, int width, int height)
{
    Ray ray;
    vec3 CamEye = cam.eye;
    vec3 CamTarget = cam.target;
    vec3 CamUp = cam.up;
    float alpha = 2 * (i + 0.5) / width - 1;
    float beta = 1 - 2 * (j + 0.5) / height;
    float Aspect = cam.aspect;
    float Fovy = cam.fovy;
    vec3 w = glm::normalize(CamEye - CamTarget);
    vec3 u = glm::normalize(cross(CamUp, w));
    vec3 v = glm::cross(w, u);
    vec3 d = glm::normalize(-alpha * Aspect * tan(Fovy / 2) * u + beta * tan(Fovy / 2) * v - w);

    ray.p0 = CamEye;
    ray.dir = d;
    return ray;
}
Intersection RayTracer::Intersect(Ray ray, Triangle *triangle)
{
    Intersection intersection;
    intersection.triangle = triangle;
    glm::vec4 rayPosition = glm::vec4(ray.p0, 1);
    glm::mat4 RayTran;
    RayTran[0] = glm::vec4(triangle->P[0], 1);
    RayTran[1] = glm::vec4(triangle->P[1], 1);
    RayTran[2] = glm::vec4(triangle->P[2], 1);
    RayTran[3] = glm::vec4(-ray.dir, 0);

    glm::vec4 lambda = glm::inverse(RayTran) * rayPosition;

    // If all lambdas and are greater than zero then we have an intersection

    if (lambda.x >= 0 && lambda.y >= 0 && lambda.z >= 0 && lambda.w >= 0)
    {
        glm::vec3 q = (lambda.x) * triangle->P[0] + (lambda.y) * triangle->P[1] + (lambda.z) * triangle->P[2];
        glm::vec3 n = glm::normalize((lambda.x) * triangle->N[0] + (lambda.y) * triangle->N[1] + (lambda.z) * triangle->N[2]);
        intersection.P = q;
        intersection.N = n;
        intersection.V = -ray.dir;
        intersection.dist = lambda.w;
    }
    else
    {
        intersection.dist = INFINITY;
    }
    return intersection;
}
Intersection RayTracer::Intersect(Ray ray, RTScene *scene)
{
    float minDist = INFINITY;
    Intersection hit;
    hit.dist = minDist;
    std::vector<Triangle> triangleList = scene->triangle_soup;
    Triangle *triangle;
    // cout << "triangele size is " << triangleList.size() << endl;
    for (int i = 0; i < triangleList.size(); i++)
    { // Find closest intersection; test all objects

        triangle = &(triangleList[i]);
        Intersection hit_temp = Intersect(ray, triangle);
        if (hit_temp.dist < minDist)
        { // closer than previous hit
            minDist = hit_temp.dist;
            hit = hit_temp;
        }
    }
    return hit;
}
glm::vec3 RayTracer::FindColor(Intersection hit, RTScene* scene, int recursion_depth)
{ 
    glm::vec4 color;         
    if (hit.dist == INFINITY)
    {
        return glm::vec3(0.0f);
    }
    else
    {
        glm::vec3 color;
        Material *m;
        std::map<std::string, Light *> light = scene->light;
        std::vector<glm::vec4> lightPositions;
        std::vector<glm::vec4> lightColors;

        for (std::pair<std::string, Light *> element : light)
        {
            lightPositions.push_back((element.second)->position);
            lightColors.push_back((element.second)->color);
        }

        m = hit.triangle->material;
        color = m->emision;

        for (int i = 0; i < lightPositions.size(); i++)
        {
            glm::vec4 lightPos = lightPositions[i];
            Ray rayToLight;


            rayToLight.dir = glm::normalize(glm::vec3(lightPos - glm::vec4(hit.P, 1)));
            rayToLight.p0 = hit.P + vec3(0.9f) * rayToLight.dir;
            float dist = glm::sqrt(glm::pow((lightPos.x - hit.P.x), 2) +
                                   glm::pow((lightPos.y - hit.P.y), 2) +
                                   glm::pow((lightPos.z - hit.P.z), 2));

            if (Intersect(rayToLight, scene).dist >= dist)
            {
                glm::vec4 lightColor = lightColors[i];
                glm::vec3 curColor = glm::vec3(m->ambient);
                glm::vec3 lightPosDir = glm::normalize(glm::vec3(lightPos - glm::vec4(hit.P, 1)));
                glm::vec3 C_diffuse = glm::vec3(m->diffuse) * glm::max(glm::dot(hit.N, lightPosDir), 0.0f);
                curColor += C_diffuse;

                if (recursion_depth == 0)
                {

                    glm::vec3 tmp = glm::normalize(lightPosDir + glm::normalize(hit.V));
                    glm::vec3 C_specular = glm::vec3(m->specular) * glm::pow(glm::max(glm::dot(hit.N, tmp), 0.0f), m->shininess);
                    curColor += C_specular;
                }
                curColor.x *= lightColor.x;
                curColor.y *= lightColor.y;
                curColor.z *= lightColor.z;
                color = color + curColor;
            }
            else
            {
                continue;
            }
        }

        Ray ray2;
        Intersection hit2;
        // specular component (recursive)
        if (recursion_depth > 0)
        {
            ray2.dir = 2.0f * glm::dot(hit.N, hit.V) * hit.N - hit.V;
            ray2.p0 = hit.P + vec3(0.6f) * ray2.dir;
            hit2 = Intersect(ray2, scene);
            glm::vec3 comp = FindColor(hit2, scene, recursion_depth - 1);
            color = color + comp;
        }

        return color;
    }
}
