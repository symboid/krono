
#include "krono/calculo/setup.h"
#include "krono/calculo/kronoscope.h"

KronoScope::KronoScope(int year, int month, int day)
    : mDateIndex(sBaseIndex - dateIndex(year, month, day))
{
}

KronoScope::DateIndex KronoScope::sBaseIndex(dateIndex(1981, 12, 31));

KronoScope::DateIndex KronoScope::dateIndex(int year, int month, int day)
{
    static const int MONTH_SUM[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };

    // count days until end of previous year:
    int yearNum = year - 1;
    DateIndex dateIndex = yearNum * 365 + (yearNum / 4) - (yearNum / 100) + (yearNum / 400);

    // count day until end of previous month:
    dateIndex += MONTH_SUM[month - 1];
    if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0) && month > 2)
    {
        dateIndex++;
    }

    // incrementing days with date's day
    dateIndex += day;

    return dateIndex;
}

void KronoScope::setDate(int year, int month, int day)
{
    mDateIndex = sBaseIndex - dateIndex(year, month, day);
}

int KronoScope::marker(int period) const
{
    return (mDateIndex % period + period - 1) % period + 1;
}

Contour<PhisType> KronoScope::mask() const
{
    const Contour<PhisType> phisContour = this->phisContour();
    const Contour<EmotType> emotContour = this->emotContour();
    ContourTabular aggregated;
    aggregated.mCapacity = (phisContour.mCapacity + emotContour.mCapacity) / 2;
    aggregated.mEmission = (phisContour.mEmission + emotContour.mEmission) / 2;

    return mPhisSpace.match(aggregated);
}

double KronoScope::rootSum() const
{
    const Contour<PhisType> phisContour = this->phisContour();
    const Contour<EmotType> emotContour = this->emotContour();
    const Contour<IntlType> intlContour = this->intlContour();

    return  phisContour.mCapacity + phisContour.mEmission +
            emotContour.mCapacity + emotContour.mEmission +
            intlContour.mCapacity + intlContour.mEmission;
}
