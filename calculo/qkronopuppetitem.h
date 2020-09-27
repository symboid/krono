
#ifndef __SYMBOID_KRONO_CALCULO_QKRONOPUPPETITEM_H__
#define __SYMBOID_KRONO_CALCULO_QKRONOPUPPETITEM_H__

#include "krono/calculo/defs.h"
#include <QQuickPaintedItem>
#include "krono/calculo/qkronoscope.h"
#include <QPen>

class KRONO_CALCULO_API QKronoPuppetItem : public QQuickPaintedItem
{
    Q_OBJECT

public:
    static constexpr const char* qml_name = "KronoPuppet";

public:
    QKronoPuppetItem(QQuickItem* parent = Q_NULLPTR);

private:
    QPen mSizePen;
    qreal mPuppetWidth;
    qreal mPuppetHeight;
    qreal mPuppetLeft;
    qreal mPuppetTop;
    qreal mHMiddle;
    qreal mMarginSize;
    QPointF calcPoint(qreal relX, qreal relY) const;
    void drawChakraSize(QPainter* painter, const QPointF& chakraPoint, const QPointF& labelCenter,
            int chakraSize, bool isMainChakra = false);
    void paint(QPainter* painter) override;

public:
    PROPERTY_MEMBER(int, phisCapacity)
    PROPERTY_MEMBER(int, phisEmission)
    PROPERTY_MEMBER(int, emotCapacity)
    PROPERTY_MEMBER(int, emotEmission)
};

#endif // __SYMBOID_KRONO_CALCULO_QKRONOPUPPETITEM_H__
