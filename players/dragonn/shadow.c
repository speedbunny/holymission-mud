inherit "/obj/std_shadow";
#include "/players/exos/defs.h"
int old_ac, old_wc;

varargs int start_shadow(object ob,int time,int wc,int ac) {
    old_wc=ob->query_n_wc();
    old_ac=ob->query_n_ac();
    ob->set_n_wc(wc+old_wc);
    ob->set_n_ac(ac+old_ac);
    return ::start_shadow(ob,time,"inspire",0);
}

void end_shadow(object ob) {
    me->set_n_wc(old_wc);
    me->set_n_ac(old_ac);
    TELL(me,"You feel less inspired.\n");
    ::end_shadow(ob);
}

int inspire_shad() { return 1; }
