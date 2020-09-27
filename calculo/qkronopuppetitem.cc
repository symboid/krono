
#include "krono/calculo/setup.h"
#include "krono/calculo/qkronopuppetitem.h"
#include <QPainter>
#include <QGraphicsPixmapItem>

QKronoPuppetItem::QKronoPuppetItem(QQuickItem* parent)
    : QQuickPaintedItem(parent)
    , mPuppetWidth(0)
    , mPuppetHeight(0)
    , mPuppetLeft(0)
    , mPuppetTop(0)
    , mHMiddle(0)
    , mMarginSize(15)
{
    connect(this, SIGNAL(phisCapacityChanged()), this, SLOT(update()));
    connect(this, SIGNAL(phisEmissionChanged()), this, SLOT(update()));
    connect(this, SIGNAL(emotCapacityChanged()), this, SLOT(update()));
    connect(this, SIGNAL(emotEmissionChanged()), this, SLOT(update()));
}

QPointF QKronoPuppetItem::calcPoint(qreal relX, qreal relY) const
{
    return QPointF(mHMiddle + relX * mPuppetWidth, mMarginSize + mPuppetTop + relY * mPuppetHeight);
}

void QKronoPuppetItem::drawChakraSize(QPainter* painter, const QPointF& chakraPoint, const QPointF& labelCenter,
        int chakraSize, bool isMainChakra)
{
    qreal cRad = isMainChakra ? mPuppetHeight / 40.0 : 1.0;
    painter->setPen(QPen(QColor("black")));
    painter->drawEllipse(chakraPoint, cRad, cRad);
    painter->setPen(QPen(QColor(0xA0,0xA0,0xA0)));
    painter->drawLine(chakraPoint, labelCenter);

    QString chakraSizeText(QString::number(chakraSize));
    const QRectF textBoundingRect(QFontMetrics(painter->font(), painter->device()).boundingRect(chakraSizeText));
    qreal circleSize = qMax(textBoundingRect.width(), textBoundingRect.height());
    QPointF circlePos = labelCenter;// - QPointF(circleSize,circleSize) / 2;
    painter->drawEllipse(circlePos, circleSize, circleSize);
    painter->setPen(QPen(QColor("black")));
    painter->drawText(labelCenter - textBoundingRect.center(), chakraSizeText);
}

void QKronoPuppetItem::paint(QPainter* painter)
{
    painter->setRenderHints(QPainter::Antialiasing, true);
    QRectF sceneRect = boundingRect();

    // load man shape picure:
    QPixmap manShapePixmap(QPixmap(":/picture/manshape.jpg").scaled(sceneRect.width()*0.66, sceneRect.height(), Qt::KeepAspectRatio));
    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(manShapePixmap);
    // man shape geometries:
    mPuppetWidth = pixmapItem->boundingRect().width();
    mPuppetHeight = pixmapItem->boundingRect().height();
    mPuppetLeft = (sceneRect.width() - mPuppetWidth) / 2.0;
    mPuppetTop = (sceneRect.height() - mPuppetHeight) / 2.0;
    mHMiddle = sceneRect.center().x();

    painter->drawImage(sceneRect.topLeft() + QPointF(mPuppetLeft,mPuppetTop), manShapePixmap.toImage());
//    pixmapItem->setPos(sceneRect.topLeft() + QPointF(mPuppetLeft,mPuppetTop));
//    mScene->addItem(pixmapItem);

    qreal cDist = 0.07;

    qreal hLev = 0.28; // level of heart
    drawChakraSize(painter, calcPoint(0, 0.18), calcPoint(-0.65, hLev-cDist), m_emotEmission, true);
    drawChakraSize(painter, calcPoint(0, hLev), calcPoint(-0.65, hLev), m_emotCapacity, true);
    drawChakraSize(painter, calcPoint(0, 0.36), calcPoint(-0.65, hLev+cDist), m_phisEmission, true);
    drawChakraSize(painter, calcPoint(0, 0.48), calcPoint(-0.65, hLev+2*cDist), m_phisCapacity, true);

    qreal wLev = 0.36; // level of wrist
    drawChakraSize(painter, calcPoint(0.23, 0.20), calcPoint(0.65, wLev-cDist), m_emotEmission);
    drawChakraSize(painter, calcPoint(0.26, wLev), calcPoint(0.65, wLev), m_emotCapacity);
    drawChakraSize(painter, calcPoint(0.35, 0.50), calcPoint(0.65, wLev+cDist), m_phisEmission);
    drawChakraSize(painter, calcPoint(0.39, 0.55), calcPoint(0.65, wLev+2*cDist), m_phisCapacity);

    qreal aLev = 0.94; // level of ankle
    drawChakraSize(painter, calcPoint(0.20, 0.51), calcPoint(0.65, aLev-3*cDist), m_phisCapacity);
    drawChakraSize(painter, calcPoint(0.10, 0.74), calcPoint(0.65, aLev-2*cDist), m_phisEmission);
    drawChakraSize(painter, calcPoint(0.07, aLev), calcPoint(0.65, aLev-cDist), m_emotCapacity);
    drawChakraSize(painter, calcPoint(0.07, 0.97), calcPoint(0.65, aLev), m_emotEmission);
}
