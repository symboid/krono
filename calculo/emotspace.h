
#ifndef __SYMBOID_KRONO_CALCULO_EMOTSPACE_H__
#define __SYMBOID_KRONO_CALCULO_EMOTSPACE_H__

#include "krono/calculo/defs.h"
#include "krono/calculo/kronospace.h"

enum EmotType
{
    PASSIONATE,
    EGOIST,
    SLOPPY,
    COLD,
    ALTRUIST,
    EMPATIC,
};

typedef KronoSpace<EmotType, 28> EmotSpace;

#endif // __SYMBOID_KRONO_CACLULO_EMOTSPACE_H__
