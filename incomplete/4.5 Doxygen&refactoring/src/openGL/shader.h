#pragma once

#include <string>
#include <vector>
#include <GL/glew.h>

class Shader
{

public:
    bool init();
    void useProgram();
    void close();
    GLuint getProgram() { return m_program; };
    GLuint getID();
    ~Shader();

private:
    GLuint m_program;
    std::vector<int32_t> shaderIDs;
    GLuint vertexShader, fragmentShader;    
    struct Datafile;

    std::string readFile(const char* fileName);

    void error(int32_t shaderID = 0);

    int create(const std::string &fileName, GLenum shaderType);

    bool compile(int shaderID);
    bool link();
    bool load(const std::string &fileName, GLenum shaderType);

};