#include "buffer.h"

#include <GL/glew.h>

bool Buffer::init(Shader &shader)
{
    GLuint vbo[2], vao[1]; 
    const uint32_t positionAttributeIndex = 0, colorAttributeIndex = 1;
    const uint32_t points = 3;
    const uint32_t floatsPerPoint = 3;
    const uint32_t floatsPerColor = 4;

    const GLfloat triangle[points][floatsPerPoint] = {
        {  0.0f,  0.8f,  0.0f }, 
        { -0.8f,  -0.8f,  0.0f }, 
        {  0.8f,  -0.8f,  0.0f }, 
    };

    const GLfloat colors[points][floatsPerColor] = {
        { 0.0, 1.0, 0.0, 1.0 }, // Top left
        { 1.0, 1.0, 0.0, 1.0  }, // Top right
        { 1.0, 0.0, 0.0, 1.0  }, // Bottom right 
    };

	glGenBuffers(2, vbo);
	glGenVertexArrays(1, vao);
	glBindVertexArray(vao[0]);

	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, ( points * floatsPerPoint) * sizeof(GLfloat), triangle, GL_STATIC_DRAW);
	glVertexAttribPointer(positionAttributeIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(positionAttributeIndex);
	
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, ( points * floatsPerColor) * sizeof(GLfloat), colors, GL_STATIC_DRAW);
	glVertexAttribPointer(colorAttributeIndex, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(colorAttributeIndex);

	if (!shader.init()) return false;
	shader.useProgram();
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	return true;
}