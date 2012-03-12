#include "util.h"

float b2Util::b2Angle(const b2Vec2 &v1, const b2Vec2 &v2)
{
    b2Vec2 toV2Vec = v1 - v2;
    return qAtan2(-toV2Vec.x, toV2Vec.y);
}

float b2Util::b2Length(const b2Vec2 &v1, const b2Vec2 &v2)
{
    return qSqrt(qPow(v2.x - v1.x, 2) + qPow(v2.y - v1.y, 2));
}

b2Vec2 b2Util::b2Center(const b2Vec2 &v1, const b2Vec2 &v2)
{
    return b2Vec2((v1.x + v2.x) / 2.0f,
                  (v1.y + v2.y) / 2.0f);
}

QPointF b2Util::qTopLeft(const b2Vec2 &vec, const QRectF &geometry, const qreal &scaleRatio)
{
    const qreal newX = vec.x * scaleRatio - geometry.width() / 2.0;
    const qreal newY = -vec.y * scaleRatio - geometry.height() / 2.0;

    return QPointF(newX, newY);
}

qreal b2Util::qAngle(const qreal &angle)
{
    return -(angle * 360.0) / (2 * b2_pi);
}

QColor b2Util::qColor(const b2Color &color)
{
    return QColor(color.r * 255, color.g * 255, color.b * 255);
}

QPointF b2Util::qPointF(const b2Vec2 &vec, const qreal &scaleRatio)
{
    return QPointF(vec.x * scaleRatio, -vec.y * scaleRatio);
}

QPolygonF b2Util::qPolygonF(const b2Vec2 *vertices, int32 vertexCount, const qreal &scaleRatio)
{
    QPolygonF polygon;
    polygon.reserve(vertexCount);

    for (int i = 0; i < vertexCount; ++i)
        polygon.append(qPointF(vertices[i], scaleRatio));

    return polygon;
}