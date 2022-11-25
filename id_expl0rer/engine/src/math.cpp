#include <algorithm>
#include "engine/math.h"


Math::Vector2Short::Vector2Short(short x, short y)
{
    X = x;
    Y = y;
}

Math::Vector2::Vector2(float x, float y)
{
    X = x;
    Y = y;
}

Math::Vector2Int::Vector2Int(int x, int y)
{
    X = x;
    Y = y;
}

Math::Vector3::Vector3(float x, float y, float z)
{
    X = x;
    Y = y;
    Z = z;
}

Math::BoundsInt::BoundsInt(Vector2Int center, Vector2Int size)
{
    m_Center = center;
    if (m_Size.X < 1) m_Size.X = 1;
    if (m_Size.Y < 1) m_Size.Y = 1;
    m_Size = size;
    m_Extents = Vector2Int(size.X / 2, size.Y / 2);
    m_Min = Vector2Int(center.X - m_Extents.X, center.Y - m_Extents.Y);
    m_Max = Vector2Int(center.X + m_Extents.X, center.Y + m_Extents.Y);
}

bool Math::BoundsInt::Contains(Math::Vector2Int * point)
{
    if (m_Min.X <= point->X
    && m_Max.X >= point->X
    && m_Min.Y <= point->Y
    && m_Max.Y >= point->Y)
        return true;
    return false;
}

bool Math::BoundsInt::Intersects(Math::BoundsInt * bounds)
{
    Vector2Int otherMin = bounds->GetMin();
    Vector2Int otherMax = bounds->GetMax();

    // If otherMin <= m_Max && otherMax >= m_Min
    if ((otherMin.X <= m_Max.X && otherMin.Y <= m_Max.Y) &&
            (otherMax.X >= m_Min.X && otherMax.Y >= m_Min.Y))
        return true;
    return false;
}



Math::BoundsInt Math::BoundsInt::Intersection(Math::BoundsInt *a, Math::BoundsInt *b)
{
    // If no intersection, return empty
    if (!a->Intersects(b))
        return Math::BoundsInt(Math::Vector2Int(), Math::Vector2Int());

    int minX = std::max(a->m_Min.X, b->m_Min.X);
    int minY = std::max(a->m_Min.Y, b->m_Min.Y);
    int maxX = std::min(a->m_Max.X, b->m_Max.X);
    int maxY = std::min(a->m_Max.Y, b->m_Max.Y);

    Math::Vector2Int
        size(
                maxX - minX,
                maxY - minY
                ),
        center(
                minX + (size.X/2),
                minY + (size.Y/2)
                );

    return BoundsInt(center, size);
}
