#ifndef ID_EXPL0RER_DEVELOPMENT_MATH_H
#define ID_EXPL0RER_DEVELOPMENT_MATH_H

namespace Math
{

    struct Vector2Short
    {
    public:
        Vector2Short(short x, short y);
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

    struct Vector2Int
    {
    public:
        Vector2Int(int x, int y);
        int X;
        int Y;
    };

    struct Vector3
    {
    public:
        Vector3(float x, float y, float z);
        float X;
        float Y;
        float Z;
    };

    struct BoundsInt
    {
    public:
        BoundsInt(Vector2Int center, Vector2Int size);
        Vector2Int center;
        Vector2Int extents;
        Vector2Int max;
        Vector2Int min;
        Vector2Int size;

        bool Contains(Vector2Int point);
        bool Intersects(BoundsInt bounds);

    };

}
#endif //ID_EXPL0RER_DEVELOPMENT_MATH_H
