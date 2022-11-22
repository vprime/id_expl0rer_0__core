//
// Created by nohbu on 11/21/2022.
//

#ifndef ID_EXPL0RER_DEVELOPMENT_CORE_H
#define ID_EXPL0RER_DEVELOPMENT_CORE_H

#include "math.h"

namespace Engine
{

    class Transform
    {
    public:
        Math::Vector3 position;
        Math::Vector3 rotation;
        Math::Vector3 scale;
    };

    class SceneComponent
    {
    public:
    };

    class Layer
    {
    public:
        SceneComponent * components;

    };

    class Scene
    {
    public:
        Layer * layers;

    };

    class Camera
    {
    public:
        Engine::Transform transform;
    };
}

#endif //ID_EXPL0RER_DEVELOPMENT_CORE_H
