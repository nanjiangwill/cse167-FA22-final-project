// #include "RayTracer.h"
// using namespace std;

// void RayTracer::Raytrace(Camera cam, RTScene rtscene, Image &image){
//     int w = image.width;
//     int h = image.height;
//     for (int j = 0; j < h; j++)
//     {
//         for (int i = 0; i < w; i++)
//         {
//             Ray ray = RayThruPixel(cam, i, j, w, h);
//             Intersection hit = Intersect(ray, $rtscene);
//             image.pixel[j*w+i] = FindColor(hit,1);
//         }
//     }
// }
// Ray RayTracer::RayThruPixel(Camera cam, int i, int j, int width, int height)
// {
//     Ray ray;
//     glm::vec3 CamEye = cam->eye;
//     glm::vec3 CamTarget = cam->target;
//     glm::vec3 CamUp = cam->up;
//     float aspect = cam->aspect;
//     float fovy = cam->fovy;

//     glm::vec3 w = glm::normalize(CamEye - CamTarget);
//     glm::vec3 u = glm::normalize(glm::cross(CamUp, w));
//     glm::vec3 v = glm::crose(w, u);
//     float a = 2 * (((i + 1 / 2) / width) - 1);
//     float b = 1 - 2 * ((j + 1 / 2) / height);
//     glm::vec3 d = glm::normalize(a * aspect * (glm::tan(fovy / 2) * u) + b * (glm::tan(fovy / 2) * v - w));
//     ray.p0 = camEye;
//     ray.dir = d;
//     return ray;

// } // page
// Intersection RayTracer::Intersect(Ray ray, Triangle *triangle)
// {
//     Intersection intersection;
//     intersection.triangle = triangle;
//     glm::vec4 rayPosition = glm::vec4(ray.p0, 1);
//     glm::mat4 RayTran;
//     RayTran[0] = glm::vec4(triangle->P[0], 1);
//     RayTran[1] = glm::vec4(triangle->P[1], 1);
//     RayTran[2] = glm::vec4(triangle->P[2], 1);
//     RayTran[3] = glm::vec4(-ray.dir, 0);

//     glm::vec4 lambda = glm::inverse(RayTran) * rayPosition;

//     // If all lambdas and are greater than zero then we have an intersection

//     if(lambda.x>=0 && lambda.y>=0 && lambda.z>=0 && lambda.w>=0){
//         glm::vec3 q = (lambda.x) * triangle->P[0] + (lambda.y) * triangle->P[1] + (lambda.z) * triangle->P[2];
//         glm::vec3 n = glm::normalize((lambda.x) * triangle->N[0] + (lambda.y) * triangle->N[1] + (lambda.z) * triangle->N[2]);
//         intersection.P = q;
//         intersection.N = n;
//         intersection.V = -ray.r;
//         intersection.dist = lambda.w;
//     }
//     else{
//         intersection.dist = INFINITY;
//     }
// }
// Intersection RayTracer::Intersect(Ray ray, RTScene *scene)
// {
//     float mindist = INFINITY;
//     Intersection hit;
//     hit.dist = mindist;
//     vector<Triangle> triangleList = scene->triangle_soup;
//     Triangle *triangle;
//     for (size_t i = 0; i < triangleList.size(); i++)
//     { // Find closest intersection; test all objects
//         triangle = &triangleList[i];
//         Intersection hit_temp = Intersect(ray, triangle);
//         if (hit_temp.dist < mindist)
//         { // closer than previous hit
//             mindist = hit_temp.dist;
//             hit = hit_temp;
//         }
//         }
//     return hit;
// }
// glm::vec3 RayTracer::FindColor(Intersection hit, int recursion_depth){

//      if (recursion_depth >= 0)
//     {
//         glm::vec3 color = hit.visible ? RTModel : glm::vec3(0.0f);
//         return color + specular * FindColor(hit, recursion_depth - 1);
//     }
//     return 0
// }
