//
// Created by nohbu on 11/21/2022.
//

#ifndef ID_EXPL0RER_DEVELOPMENT_MATH_H
#define ID_EXPL0RER_DEVELOPMENT_MATH_H

namespace Math
{

    struct Vector2short
    {
    public:
        Vector2short(short x, short y);
        short X;
        short Y;
    };

    struct Vector2
    {
    public:
        Vector2(float x, float y);
        float X;
        float Y;
    };

    struct Vector3
    {
    public:
        Vector3(float x, float y, float z);
        float X;
        float Y;
        float Z;
    };

}
#endif //ID_EXPL0RER_DEVELOPMENT_MATH_H
