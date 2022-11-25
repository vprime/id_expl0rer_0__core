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
        virtual ~SceneComponent() = 0;
        Engine::Transform transform;
    };

    class Layer
    {
    public:
        std::vector<SceneComponent *> components;
    };

    class Scene
    {
    public:
        std::vector<Layer> layers;
    };
}

#endif //ID_EXPL0RER_DEVELOPMENT_CORE_H
