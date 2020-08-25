
#ifndef __SYMBOID_KRONO_CALCULO_PHISSPACE_H__
#define __SYMBOID_KRONO_CALCULO_PHISSPACE_H__

#include "krono/calculo/defs.h"
#include "krono/calculo/kronospace.h"

enum PhisType
{
    MODERATE    = 0x00,

    CHOLERIC    = 0x01,
    SANGUINE    = 0x02,
    PHLEGMATIC  = 0x04,
    MELANCHOLIC = 0x08,

    SENSITIVE   = CHOLERIC | MELANCHOLIC,
    STRONG      = PHLEGMATIC | SANGUINE,
};

class PhisSpace : public KronoSpace<PhisType, 23>
{
public:
    Contour<PhisType> match(const ContourTabular& tabular) const;

private:
    static double dist(const ContourTabular& lhs, const ContourTabular& rhs);
};

#endif // __SYMBOID_KRONO_CALCULO_PHISSPACE_H__
