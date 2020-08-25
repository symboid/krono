
#include "krono/calculo/setup.h"
#include "krono/calculo/qkronosummary.h"

QKronoSummary::QKronoSummary(QObject* parent)
    : QObject(parent)
    , mYear(1800)
    , mMonth(1)
    , mDay(1)
{
}

void QKronoSummary::setYear(int year)
{
    if (mYear != year)
    {
        mYear = year;
        emit yearChanged();
    }
}

void QKronoSummary::setMonth(int month)
{
    if (mMonth != month)
    {
        mMonth = month;
        emit monthChanged();
    }
}

void QKronoSummary::setDay(int day)
{
    if (mDay != day)
    {
        mDay = day;
        emit dayChanged();
    }
}
