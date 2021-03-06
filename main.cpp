#include "Image.hpp"
#include "Scene.hpp"
#include "Sphere.hpp"
#include "Object.hpp"
#include "Ray.hpp"
#include "Vector.hpp"
#include "Light.hpp"
#include "Point_Light.hpp"
#include "Plane.hpp"
#include "Camera.hpp"
#include <memory>
#include <vector>
#include "Distant_light.hpp"


int main()
{
    float aspect_ratio = 1920 / 1080;
    Camera camera(Vector(-0.2, 0.5, 0.5), Vector(0, 0.4, -2), Vector(0, 1, 0), 45, aspect_ratio);
    auto texture_plane_bottom = std::make_shared<Diffuse_texture>(0.18);
    auto texture_plane_right = std::make_shared<Diffuse_texture>(0.18);
    auto texture_plane_back = std::make_shared<Diffuse_texture>(0.18);

    auto texture_sphere = std::make_shared<Diffuse_texture>(0.18);

    auto texture_sphere2 = std::make_shared<Diffuse_texture>(0.18);

    Sphere sphere(Object::Surface_type::DIFFUSE, texture_sphere, Vector(0, 0.4, -2), 0.4, Vector(0, 1, 0));

    Sphere sphere2(Object::Surface_type::DIFFUSE, texture_sphere2, Vector(1, 0.4, -2), 0.4, Vector(0, 1, 0));

    Plane plane_back(Object::Surface_type::DIFFUSE, Vector(0, 0, -3), Vector(0, 0, 1), texture_plane_back, Vector(1, 0, 0));

    Plane plane_bottom(Object::Surface_type::DIFFUSE, Vector(0, 0, -2), Vector(0, 1, 0), texture_plane_bottom, Vector(0, 0, 1));

    Plane plane_right(Object::Surface_type::DIFFUSE, Vector(2, 0, -2), Vector(-1, 0, 0), texture_plane_right, Vector(0, 1, 1));

    std::shared_ptr<Object> sphere_ptr = std::make_shared<Sphere>(sphere);
    std::shared_ptr<Object> sphere_ptr2 = std::make_shared<Sphere>(sphere2);
    std::shared_ptr<Object> plane_ptr_back = std::make_shared<Plane>(plane_back);
    std::shared_ptr<Object> plane_ptr_bottom = std::make_shared<Plane>(plane_bottom);
    std::shared_ptr<Object> plane_ptr_right = std::make_shared<Plane>(plane_right);
    std::vector<std::shared_ptr<Object>> objects{};
    objects.push_back(sphere_ptr);
    objects.push_back(plane_ptr_bottom);
    objects.push_back(sphere_ptr2);
    objects.push_back(plane_ptr_back);
    //objects.push_back(plane_ptr_right);
    Point_Light light1(150, Vector(1, 1, -1));
    Point_Light light2(150, Vector(-1, 1.5, -1));
    std::vector<Point_Light> lights;
    lights.push_back(light1);
    Distant_light distantLight(25, (Vector(0.0, 0.4, -2.0) - Vector(1, 1, -1)).normalize());
    //lights.push_back(light2);
    Scene scene(objects, camera, distantLight, 1080, 1920);
    //Scene scene(objects, camera, lights, 1080, 1920);
    scene.render(Scene::RenderingMethod::PATHTRACING);
    scene.save_image();
    return 0;
}
