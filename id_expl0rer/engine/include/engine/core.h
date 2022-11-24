#ifndef ID_EXPL0RER_DEVELOPMENT_CORE_H
#define ID_EXPL0RER_DEVELOPMENT_CORE_H

#include "math.h"

namespace Engine
{

    class Transform
    {
    public:
        Math::Vector2Int position;
        Math::Vector2Int rotation;
        Math::Vector2Int scale;
        Math::BoundsInt bounds;
    };

    class SceneComponent
    {
    public:
        Engine::Transform transform;
    };

    class Layer
    {
    public:
        SceneComponent * components;
    };

    class Camera : SceneComponent
    {
    public:
        Layer * layers;
    };

    class Scene
    {
    public:
        Layer * layers;
        Camera * cameras;
    };
}

#endif //ID_EXPL0RER_DEVELOPMENT_CORE_H
