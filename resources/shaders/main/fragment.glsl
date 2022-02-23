#version 450 core

//uniform sampler2D sampler;
//
//in vec2 fTexCoord;

layout (location = 0) uniform ivec2 windowSize;
layout (location = 4) uniform vec2 mousePos;

out vec4 outColor;

void main() {
    float windowLength = length(windowSize);

    vec2 circlePos = vec2(mousePos.x, windowSize.y - mousePos.y) / windowLength;
    float circleRadius = 0.01;
    float circleShade = 0.003;

    vec2 pos = gl_FragCoord.xy / windowLength;
    vec3 circleColor = vec3(1, 1, 1) * smoothstep(circleRadius + circleShade, circleRadius, distance(pos, circlePos));
    //outColor = smoothstep(vec4(0.1, 0.1, 0.1, 0.1), vec4(0.1, 0.1, 0.1, 0.1), vec4(1, 1, 1, 1) * distance(pos, circlePos));
    outColor = vec4(circleColor, 1.0);
}
