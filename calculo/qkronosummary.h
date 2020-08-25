
#ifndef __SYMBOID_KRONO_CALCULO_QKRONOSUMMARY_H__
#define __SYMBOID_KRONO_CALCULO_QKRONOSUMMARY_H__

#include "krono/calculo/defs.h"
#include <QObject>

class QKronoSummary : public QObject
{
    Q_OBJECT

public:
    QKronoSummary(QObject* parent = Q_NULLPTR);

public:
    Q_PROPERTY(int year MEMBER mYear WRITE setYear NOTIFY yearChanged)
private:
    int mYear;
    void setYear(int year);
signals:
    void yearChanged();

public:
    Q_PROPERTY(int month MEMBER mMonth WRITE setMonth NOTIFY monthChanged)
private:
    int mMonth;
    void setMonth(int month);
signals:
    void monthChanged();

public:
    Q_PROPERTY(int day MEMBER mDay WRITE setDay NOTIFY dayChanged)
private:
    int mDay;
    void setDay(int day);
signals:
    void dayChanged();
};

#endif // __SYMBOID_KRONO_CALCULO_QKRONOSUMMARY_H__
