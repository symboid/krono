
#include "krono/calculo/setup.h"
#include "krono/calculo/emotspace.h"

template <>
const ContourTabular KronoSpace<EmotType,28>::TABULAR[EmotSpace::PERIOD] =
{
    {69,95},
    {75,27},
    {31,45},
    {62,77},
    {50,59},
    {44,68},
    {12,45},
    { 6,23},
    {81,54},
    {25,77},
    {18,50},
    {44,59},
    {25,68},
    {50,77},
    {50,99},
    {50,36},
    {56,41},
    {31,14},
    {99,54},
    {44,32},
    {62,41},
    {25,18},
    {69,59},
    {56,41},
    {44,68},
    {37,41},
    {56,73},
    {44,73},
};

template <>
EmotType KronoSpace<EmotType,28>::calcType(const ContourTabular& contour)
{
    double A = contour.mCapacity; A /= 100.0;
    double B = contour.mEmission; B /= 100.0;

    if (A < B)
    {
        if (A + B > 1.2)
        {
            return PASSIONATE;
        }
        else if (B < 0.42)
        {
            return COLD;
        }
        else if (B / A > 2.0)
        {
            return ALTRUIST;
        }
        else
        {
            return EMPATIC;
        }
    }
    else
    {
        if (A + B < 0.6)
        {
            return COLD;
        }
        else if (A < 0.65)
        {
            return SLOPPY;
        }
        else
        {
            return EGOIST;
        }
    }
}

template <>
ContourDyn KronoSpace<EmotType,28>::calcDyn(const Contour<EmotType>& lhs, const Contour<EmotType>& rhs) const
{
    switch (lhs.mMarker - rhs.mMarker)
    {
    case -1: case 0: case 1: case PERIOD - 1: case -PERIOD + 1: return DYN_SYNC;
    case -15: case -14: case -13: case 13: case 14: case 15: return DYN_COMP;
    case 6: case 7: case 8: case 6 - PERIOD : case 7 - PERIOD: case 8 - PERIOD: return DYN_LEAD;
    case -6: case -7: case -8: case PERIOD - 6: case PERIOD - 7: case PERIOD - 8: return DYN_LED;
    default: return DYN_NONE;
    }
}
