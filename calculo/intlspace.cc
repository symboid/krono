
#include "krono/calculo/setup.h"
#include "krono/calculo/intlspace.h"

template <>
const ContourTabular KronoSpace<IntlType,33>::TABULAR[IntlSpace::PERIOD] =
{
    {64,35},
    {21,65},
    {21,65},
    {93,82},
    {43,41},
    { 0,99},
    {57,88},
    { 7,41},
    {29,35},
    {86,35},
    {29,82},
    {86,41},
    {14,71},
    {50,59},
    {78,65},
    {93,24},
    {84,71},
    {29,41},
    {26,71},
    {99,82},
    { 7,76},
    {14,35},
    {50,65},
    {26,18},
    {29,88},
    {93,59},
    {57,82},
    {29,29},
    {29,88},
    {71,47},
    { 7,35},
    {64,59},
    {29,82},
};

template <>
IntlType KronoSpace<IntlType,33>::calcType(const ContourTabular& contour)
{
    double A = contour.mCapacity; A /= 100.0;
    double B = contour.mEmission; B /= 100.0;

    if (B > A)
    {
        if (B <= 0.41)
        {
            return WORKER;
        }
        else if (A < 0.41)
        {
            return PHILOSOPHER;
        }
        else if (A / B < 0.82)
        {
            return ENGINEER;
        }
        else
        {
            return HARMONIC;
        }
    }

    else if (B / A > 0.82)
    {
        return A+B > 1.15 ? STRATEGIST : HARMONIC;
    }

    else
    {
        return A+B < 0.5 ? ARTIST : VISIONARY;
    }
}

template <>
ContourDyn KronoSpace<IntlType,33>::calcDyn(const Contour<IntlType>& lhs,
        const Contour<IntlType>& rhs) const
{
    switch (lhs.mMarker - rhs.mMarker)
    {
    case -1: case 0: case 1: case PERIOD - 1: case -PERIOD + 1: return DYN_SYNC;
    case -17: case -16: case 16: case 17: return DYN_COMP;
    case 8: case 9: case 8 - PERIOD : case 9 - PERIOD: return DYN_LEAD;
    case -8: case -9: case PERIOD - 8: case PERIOD - 9: return DYN_LED;
    default: return DYN_NONE;
    }
}
