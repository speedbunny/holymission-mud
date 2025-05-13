inherit "/obj/board";
#include "../valhalla.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_file(WIZ+"/valhalla/obj/mainboard");
    set_name("Valhalla's Main Board");
    set_short("Valhalla's Main Board.\n"+
                "Please leave any problems, ideas, etc. here\n");
}
