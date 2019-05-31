#include "shader.h"

#include <sstream>
#include <fstream>
#include <iostream>

struct Shader::Datafile {
    std::string name;
    GLenum type; 
};

bool Shader::init()
{    
    Datafile files[2] = {
        { "vert.glsl", GL_VERTEX_SHADER },
        { "frag.glsl", GL_FRAGMENT_SHADER }
    };
    m_program = glCreateProgram();
    for(auto file : files) if(!load(file.name, file.type)) return false;
    return link(); // Returns true if successfully linked
}

bool Shader::load(const std::string &fileName, GLenum shaderType) 
{
    int shaderID = create(fileName, shaderType);
    if(compile(shaderID))
    {
        glAttachShader(m_program, shaderID);
        shaderIDs.push_back(shaderID);
        return true;
    }
    return false;
}

void Shader::useProgram()
{
    glUseProgram(m_program);
}

Shader::~Shader() {
    close();
}

void Shader::close()
{
    glUseProgram(0);
    for(auto id : shaderIDs) glDetachShader(m_program, id);
    glDeleteProgram(m_program);
    for(auto id : shaderIDs) glDeleteShader(id);
}

bool Shader::compile(int shaderID)
{
    int didCompile = 0;
    glCompileShader(shaderID);
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &didCompile);
    return didCompile;
}

int Shader::create(const std::string &fileName, GLenum shaderType)
{
    std::string str = readFile(fileName.c_str());
    char* source = const_cast<char*>(str.c_str());
    int32_t size = str.length();
    int32_t shaderID = glCreateShader(shaderType);
    glShaderSource(shaderID, 1, &source, &size);
    return shaderID;
}

bool Shader::link() 
{
    int isLinked;
    glLinkProgram(m_program);
    glGetProgramiv(m_program, GL_LINK_STATUS, &isLinked);
    if(!isLinked) error();
    return isLinked;
}

std::string Shader::readFile(const char* fileName)
{
    std::ifstream t(fileName);
    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string fileContent = buffer.str();
    return fileContent;
}
GLuint Shader::getID()
{
    return shaderIDs[0];
}

void Shader::error(int32_t shaderID) 
{
    int maxLength;

    glGetProgramiv(shaderID, GL_INFO_LOG_LENGTH, &maxLength);
    char* log = new char[maxLength];
    int length;
    glGetProgramInfoLog(m_program, maxLength, &length, log);
    if(length)
    {
        std::cout << "PROGRAM ERROR: " << log << std::endl;
    }
    else {
        glGetShaderInfoLog(shaderID, maxLength, &length, log);
        if(length) std::cout << "SHADER ERROR: " << log << std::endl;
    }
    delete log;
};