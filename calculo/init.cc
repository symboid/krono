
#include "krono/calculo/setup.h"
#include "krono/calculo/init.h"
#include <qglobal.h>

mod_krono_calculo::mod_krono_calculo()
{
    Q_INIT_RESOURCE(krono_calculo);
    load_translator();
}

mod_krono_calculo::~mod_krono_calculo()
{
    Q_CLEANUP_RESOURCE(krono_calculo);
}
