#ifndef RAY_H
#define RAY_H
#include <glm/vec3.hpp> 

// Type aliases for vec3
using point3 = glm::vec3;
using color = glm::vec3;

class Ray{
public:
point3 origin;
glm::vec3 direction;

Ray(){}
Ray(const point3& orig, glm::vec3& dir) : origin(orig), direction(dir){}

point3 getOrigin() const {
    return origin;
}

glm::vec3 getDirection() const {
    return direction;
}

point3 at(float t) const {
    return origin + t * direction;
}
};

#endif