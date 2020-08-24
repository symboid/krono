
#include "krono/app/defs.h"
#include "sdk/arch/mainobject.h"
#include "krono/app/init.h"
#include <QQuickStyle>

int main(int _argc, char* _argv[])
{
    arh::main_object_init<app_krono, int*, char***> app(&_argc, &_argv);
    app->setName("Krono");
    QQuickStyle::setStyle("Material");
    return app->run();
}
