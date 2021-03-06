#version 450 core

in vec3 vertexPosition_modelspace;
in vec3 vertexNormal_modelspace;

out vec3 fragmentColor;
out vec4 ShadowCoord;
out vec3 vertexNormal_cameraspace;
out vec3 lightDirection_cameraspace;

uniform mat4 V;
uniform mat4 MV;
uniform mat4 MVP;
uniform mat4 DepthBiasMVP;

uniform vec3 lightInvDirection_worldspace;

void main()
{
    gl_Position = MVP * vec4(vertexPosition_modelspace, 1);

    // Same, but with the light's view matrix
    ShadowCoord = DepthBiasMVP * vec4(vertexPosition_modelspace, 1);

    lightDirection_cameraspace = (V * vec4(lightInvDirection_worldspace, 0)).xyz;
    vertexNormal_cameraspace = (MV * vec4(vertexNormal_modelspace,0)).xyz;

    fragmentColor = vertexNormal_modelspace;
}
