#version 330 core
out vec4 FragColor;

in vec3 Normal;
in vec3 FragPos;
in vec3 Color;

uniform vec3 lightPos;
uniform vec3 lightColor;
uniform vec3 viewPos;

void main()
{
    vec3 grassColor = vec3(.398, .398, .0) * 1;
    vec3 mountainColor = vec3(.37, .25, .125) * 1;
    float slopeThresh = .1f;
    float blend = .5f;

    // ambient
    float ambientStrength = 0.3;
    vec3 ambient = ambientStrength * lightColor;

    // diffuse
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * lightColor * 1.2;

    // specular
    float specularStrength = .2;
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = specularStrength * spec * lightColor;

    //coloring
    float slope = 1 - Normal.y;
    float grassH = slopeThresh * (1 - blend); //grass blend height
    float weight = 1 - clamp((slope - grassH) / (slopeThresh - grassH), .0, 1.f); //grass weight
    vec3 endColor = grassColor * weight + mountainColor * (1 - weight); //the color of the fragment
    vec3 result = (ambient + diffuse + specular) * endColor; //the color of the fragment with lighting applied
    FragColor = vec4(result, 1.0);
}