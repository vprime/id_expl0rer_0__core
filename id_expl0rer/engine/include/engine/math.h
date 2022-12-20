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
        Vector2Int();
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
        bool Contains(Vector2Int * point);
        bool Intersects(Math::BoundsInt * bounds);
        static Math::BoundsInt Intersection(Math::BoundsInt * a, Math::BoundsInt * b);
        void Update(Vector2Int center, Vector2Int size);
        Vector2Int GetMin() {return m_Min;};
        Vector2Int GetMax() {return m_Max;};
        Vector2Int GetSize() {return m_Size;};

    private:
        Vector2Int m_Center;
        Vector2Int m_Size;
        Vector2Int m_Extents;
        Vector2Int m_Max;
        Vector2Int m_Min;


    };

}
#endif //ID_EXPL0RER_DEVELOPMENT_MATH_H
