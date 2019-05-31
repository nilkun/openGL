#include <glm/gtc/matrix_transform.hpp>

class Matrix {
public:
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1.0f, .1f, 100.0f);
    // (float) width / (float) height = 1.0 at the moment since it is a perfect square
    
    // ortho
    //glm::mat4 Projection = glm::ortho(-10.0f,10.0f,-10.0f,10.0f,0.0f,100.0f); // In world coordinates
    
    glm::mat4 view = glm::lookAt(
        glm::vec3(4,3,3),
        glm::vec3(0,0,0),
        glm::vec3(0,1,0)
    );

    glm::mat4 model = glm::mat4(1.0f);

    glm::mat4 mvp = projection * view * model;
};