
#ifndef __SYMBOID_KRONO_CALCULO_INIT_H__
#define __SYMBOID_KRONO_CALCULO_INIT_H__

#include "krono/calculo/defs.h"
#include "sdk/arch/modqt.h"
#include "sdk/controls/init.h"

struct KRONO_CALCULO_API mod_krono_calculo : arh::mod_qt<mod_krono_calculo>
{
    MOD_OBJECT(krono_calculo)

    static constexpr const char* qml_pkg_name = "Symboid.Krono.Calculo";
    static constexpr int qml_pkg_ver_major = 1;
    static constexpr int qml_pkg_ver_minor = 0;

    mod_krono_calculo();
    ~mod_krono_calculo();

    arh::mod_init<mod_sdk_controls> _M_mod_sdk_controls;
};

#endif // __SYMBOID_KRONO_CALCULO_INIT_H__
