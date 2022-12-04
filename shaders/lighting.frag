#version 330 core

in vec4 position; // raw position in the model coord
in vec3 normal;   // raw normal in the model coord

uniform mat4 modelview; // from model coord to eye coord
uniform mat4 view;      // from world coord to eye coord

// Material parameters
uniform vec4 ambient;
uniform vec4 diffuse;
uniform vec4 specular;
uniform vec4 emision;
uniform float shininess;

// Light source parameters
const int maximal_allowed_lights = 10;
uniform bool enablelighting;
uniform int nlights;
uniform vec4 lightpositions[ maximal_allowed_lights ];
uniform vec4 lightcolors[ maximal_allowed_lights ];

// Output the frag color
out vec4 fragColor;


void main (void){
    if (!enablelighting){
        // Default normal coloring (you don't need to modify anything here)
        vec3 N = normalize(normal);
        fragColor = vec4(0.5f*N + 0.5f , 1.0f);
    } else {
        
        // HW3: You will compute the lighting here.
        vec4 p = modelview * position;
        vec4 q = vec4(0,0,0,0);
        vec4 SumLight = vec4(0,0,0,0);
        vec3 n = vec3(0,0,0);
        vec4 temp_v = (vec4(0,0,0,1)-p);
        vec4 v = vec4(0,0,0,0);
        vec3 lj = vec3(0,0,0);
        vec3 hj = vec3(0,0,0);
        
        for(int j = 0; j < maximal_allowed_lights;j++){
            //R = E + sum(ambient + diffuse max + specular max)*l
            
            q = view * lightpositions[j];
            n = normalize(inverse(transpose(mat3(modelview)))*normal);
            lj = normalize((p.w * q.xyz)-(q.w*p.xyz));
            v = normalize(temp_v);
            hj = normalize(vec3(v)+lj);
            SumLight += (ambient + (diffuse*max(dot(n,lj),0)) + specular*pow(max(dot(n,hj),0),shininess)) * lightcolors[j];

        }
        fragColor = emision + SumLight;
    }

    
}
