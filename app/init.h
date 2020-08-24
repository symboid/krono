
#ifndef __SYMBOID_KRONO_APP_INIT_H__
#define __SYMBOID_KRONO_APP_INIT_H__

#include "krono/app/defs.h"
#include "sdk/arch/appqml.h"
#include "sdk/controls/init.h"
#include "sdk/hosting/init.h"
#include "krono/calculo/init.h"

struct app_krono : arh::app_qml<app_krono>
{
    APP_OBJECT(krono)

    app_krono(int* _argc, char*** _argv)
        : arh::app_qml<app_krono>(_argc, _argv)
    {
    }

    arh::mod_init<mod_sdk_controls> _M_mod_sdk_controls;
    arh::mod_init<mod_sdk_hosting> _M_mod_sdk_hosting;
    arh::mod_init<mod_krono_calculo> _M_mod_krono_calculo;
};

#endif // __SYMBOID_KRONO_APP_INIT_H__
