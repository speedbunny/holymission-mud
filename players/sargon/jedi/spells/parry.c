#include "/players/mangla/defs.h"


int main() {

    int cost,retime;
    object shad;

    if(!TP->query_wielded()) {
        write("You are not wielding a weapon.\n");
        return 1;
    }
    if(TP->parry_shad()) {
        TP->end_shadow(TP);
        return 1;
    }

    write("You start your parrying.\n");

    retime = 60 + TPL*3 + TP->CON*2 + TP->DEX;
    shad = clone_object(GUILD + "obj/parry_shad");
    shad->set_time(retime);
    shad->start_shadow(TP,retime,"parry_shad");

    return 1;
}
