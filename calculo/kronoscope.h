
#ifndef __SYMBOID_KRONO_CALCULO_KRONOSCOPE_H__
#define __SYMBOID_KRONO_CALCULO_KRONOSCOPE_H__

#include "krono/calculo/defs.h"
#include "krono/calculo/phisspace.h"
#include "krono/calculo/emotspace.h"
#include "krono/calculo/intlspace.h"

class KronoScope
{
public:
    KronoScope(int year, int month, int day);

private:
    typedef int DateIndex;
    static DateIndex dateIndex(int year, int month, int day);
    static DateIndex sBaseIndex;
    DateIndex mDateIndex;

public:
    void setDate(int year, int month, int day);
    int marker(int period) const;

private:
    PhisSpace mPhisSpace;
    EmotSpace mEmotSpace;
    IntlSpace mIntlSpace;

public:
    inline Contour<PhisType> phisContour() const
    {
        return mPhisSpace.contour(marker(PhisSpace::PERIOD));
    }
    inline Contour<EmotType> emotContour() const
    {
        return mEmotSpace.contour(marker(EmotSpace::PERIOD));
    }
    inline Contour<IntlType> intlContour() const
    {
        return mIntlSpace.contour(marker(IntlSpace::PERIOD));
    }

public:
    Contour<PhisType> mask() const;
    int rootSum() const;
};

#endif // __SYMBOID_KRONO_CALCULO_KRONOSCOPE_H__
