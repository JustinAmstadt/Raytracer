#include <iostream>
#include <array>
#include <glm/vec3.hpp> 

#include "ray.hpp"

// Type aliases for vec3
using point3 = glm::vec3;
using color = glm::vec3;


glm::vec3 ray_color(const Ray& r);
void write_color(std::ostream &out, glm::vec3 pixel_color);

int main() {
    // Image

    const float ASPECT_RATIO = 16.0 / 9.0;
    const int IMAGE_WIDTH = 400;
    const int IMAGE_HEIGHT = static_cast<int>(IMAGE_WIDTH / ASPECT_RATIO);

    float viewport_height = 2.0;
    float viewport_width = ASPECT_RATIO * viewport_height;
    float const FOCAL_LENGTH = 1.0;

    point3 origin = point3(0.0f, 0.0f, 0.0f);
    auto horizontal = glm::vec3(0.0f, viewport_width, 0.0f);
    auto vertical = glm::vec3(0.0f, viewport_height, 0.0f);
    auto lower_left_corner = origin - horizontal/2.0f - vertical/2.0f - glm::vec3(0, 0, FOCAL_LENGTH);
    // Render

    std::cout << "P3\n" << IMAGE_WIDTH << ' ' << IMAGE_HEIGHT << "\n255\n";

    std::array<std::array<glm::vec3, IMAGE_WIDTH>, IMAGE_HEIGHT> picture;

    for (int j = IMAGE_HEIGHT-1; j >= 0; --j) {
       std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush; 
        for (int i = 0; i < IMAGE_WIDTH; ++i) {
            float u = float(i) / (IMAGE_WIDTH - 1);
            float v = float(j) / (IMAGE_HEIGHT - 1);
            Ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);


            glm::vec3 line = glm::vec3(r, g, b);
            picture.at(j).at(i) = line;
        }
    }

    for (int j = IMAGE_HEIGHT-1; j >= 0; --j) {
            for (int i = 0; i < IMAGE_WIDTH; ++i) {
        write_color(std::cout, picture.at(j).at(i));
        }
    }
}

glm::vec3 ray_color(const Ray& r){

}

void write_color(std::ostream &out, glm::vec3 pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(255.999 * pixel_color[0]) << ' '
        << static_cast<int>(255.999 * pixel_color[1]) << ' '
        << static_cast<int>(255.999 * pixel_color[2]) << '\n';
}