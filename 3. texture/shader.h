#pragma once

#include <string>
#include <vector>
#include <GL/glew.h>

class Shader
{
public:
    GLuint m_program;
    std::vector<int32_t> shaderIDs;
    GLuint vertexShader, fragmentShader;    
    struct Datafile;
    bool init();
    bool load(const std::string &fileName, GLenum shaderType);
    void useProgram();
    ~Shader();
    void close();
    bool compile(int shaderID);
    int create(const std::string &fileName, GLenum shaderType);
    bool link();
    std::string readFile(const char* fileName);
    void error(int32_t shaderID = 0);
};