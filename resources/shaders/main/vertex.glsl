#version 450 core

//uniform mat4 mat4_view;
//uniform mat4 mat4_projection;
//
//layout (location = 0) in vec3 pos;
//layout (location = 1) in vec2 texCoord;
//
//out vec2 fTexCoord;

//layout (location = 0) uniform ivec2 windowSize;
//layout (location = 4) uniform vec2 mousePos;

void main() {
//    gl_Position = mat4_projection * mat4_view * vec4(pos, 1.0);
//    fTexCoord = texCoord;
    float x = -1.0 + float((gl_VertexID & 1) << 2);
    float y = -1.0 + float((gl_VertexID & 2) << 1);
    gl_Position = vec4(x, y, 0, 1);
//    float windowLength = length(windowSize);
//    vec2 circlePos = vec2(mousePos.x, windowSize.y - mousePos.y) / windowLength;
//
//    gl_Position = vec4(circlePos, 0.0, 1.0);
//    gl_PointSize = 100;
}