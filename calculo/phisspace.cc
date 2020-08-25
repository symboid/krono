
#include "krono/calculo/setup.h"
#include "krono/calculo/phisspace.h"

template <>
const ContourTabular KronoSpace<PhisType,23>::TABULAR[PhisSpace::PERIOD] =
{
    {33,35},
    {55,72},
    {15,65},
    {50,72},
    {30,41},
    {75,21},
    {45,72},
    {60,22},
    {35,28},
    {35,49},
    {95,22},
    {30,99},
    {40,61},
    {20,55},
    {40,28},
    {90,21},
    {50,83},
    {10,45},
    {99,55},
    {30,52},
    {20,79},
    {80,69},
    {25,21},
};

template<>
PhisType KronoSpace<PhisType,23>::calcType(const ContourTabular& contour)
{
    double A = contour.mCapacity; A /= 100.0;
    double B = contour.mEmission; B /= 100.0;
    double factor = 4.0 / 9.0;

    if (A < B)
    {
        if (A >= factor)
        {
            return SANGUINE;
        }
        else if (B * factor < A)
        {
            return MODERATE;
        }
        else if (B >= A * factor * 10.0)
        {
            return SENSITIVE;
        }
        else
        {
            return CHOLERIC;
        }
    }
    else
    {
        if (B >= factor)
        {
            return STRONG;
        }
        else if (B < A * factor)
        {
            return PHLEGMATIC;
        }
        else
        {
            return MELANCHOLIC;
        }
    }
}

template <>
ContourDyn KronoSpace<PhisType,23>::calcDyn(const Contour<PhisType>& lhs,
        const Contour<PhisType>& rhs) const
{
    switch (lhs.mMarker - rhs.mMarker)
    {
    case -1: case 0: case 1: case PERIOD - 1: case -PERIOD + 1: return DYN_SYNC;
    case -12: case -11: case 11: case 12: return DYN_COMP;
    case 5: case 6: case 5 - PERIOD : case 6 - PERIOD: return DYN_LEAD;
    case -5: case -6:  case PERIOD - 5: case PERIOD - 6: return DYN_LED;
    default: return DYN_NONE;
    }
}

double PhisSpace::dist(const ContourTabular& lhs, const ContourTabular& rhs)
{
    double lhsReaction = lhs.mEmission / lhs.mCapacity;
    double rhsReaction = rhs.mEmission / rhs.mCapacity;
    return lhsReaction < rhsReaction ? rhsReaction - lhsReaction : lhsReaction - rhsReaction;
}

Contour<PhisType> PhisSpace::match(const ContourTabular& sample) const
{
    Contour<PhisType> matching;
    matching.mMarker = 1;
    matching.mCapacity = TABULAR[0].mCapacity;
    matching.mEmission = TABULAR[0].mEmission;

    for (int tabIndex = 1; tabIndex < PERIOD; ++tabIndex)
    {
        const ContourTabular& contour = TABULAR[tabIndex];
        if (dist(sample, contour) < dist(sample, matching))
        {
            matching.mMarker = tabIndex + 1;
            matching.mCapacity = contour.mCapacity;
            matching.mEmission = contour.mEmission;
        }
    }

    matching.mType = calcType(matching);

    return matching;
}
