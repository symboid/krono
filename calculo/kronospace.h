
#ifndef __SYMBOID_KRONO_CALCULO_KRONOSPACE_H__
#define __SYMBOID_KRONO_CALCULO_KRONOSPACE_H__

#include "krono/calculo/defs.h"

struct ContourTabular
{
    double mCapacity;
    double mEmission;
};

template <typename ContourType>
struct Contour : ContourTabular
{
    ContourType mType;
    int mMarker;
};

enum ContourDyn
{
    DYN_NONE,

    DYN_SYNC,
    DYN_COMP,
    DYN_LEAD,
    DYN_LED,
};

template<typename SpaceType, int SPACE_PERIOD>
class KronoSpace
{
public:
    virtual ~KronoSpace() {}

public:
    typedef SpaceType ContourType;
    enum { PERIOD = SPACE_PERIOD };

protected:
    static const ContourTabular TABULAR[SPACE_PERIOD];
    static SpaceType calcType(const ContourTabular& tabular);

public:
    Contour<SpaceType> contour(int marker) const
    {
        ContourTabular tabular = TABULAR[(marker - 1) % SPACE_PERIOD];
        Contour<SpaceType> contour;
        contour.mCapacity = tabular.mCapacity;
        contour.mEmission = tabular.mEmission;
        contour.mMarker = marker;
        contour.mType = calcType(tabular);
        return contour;
    }
    ContourDyn calcDyn(const Contour<SpaceType>& lhs,
            const Contour<SpaceType>& rhs) const;
};

#endif // __SYMBOID_KRONO_CALCULO_KRONOSPACE_H__
