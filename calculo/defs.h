
#ifndef __SYMBOID_KRONO_CALCULO_DEFS_H__
#define __SYMBOID_KRONO_CALCULO_DEFS_H__

#include "sdk/arch/defs.h"

#ifdef BUILD_KRONO_CALCULO
    #define KRONO_CALCULO_API SY_API_EXPORT
#else
    #define KRONO_CALCULO_API SY_API_IMPORT
#endif

#endif // __SYMBOID_KRONO_CALCULO_DEFS_H__
