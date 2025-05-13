/* ===============================================================
   Userdoc: unhide           /players/whisky/guild/skills/unhide.c
   ---------------------------------------------------------------
   Art: Stoping the hide per hand (getting visible)
   Damage || Heal: none
   Cost: none
   Special: Just the feature to destruct the hide_shadow which is
            under ~whisky/guild/shadows/hide_shad.c and become   
            visible at own will.
   =============================================================== */

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag) {
    ::reset(flag);
    if (flag == 0)
        set_partner("/players/sauron/guild/room");
}
 
int unhide() {
    object hide_ob;
    
    hide_ob = apply(call, _tp, "hide_object");
    if(objectp(hide_ob)) {
        apply(call, hide_ob, "set_no_unhide_msg", 1);
        apply(call, hide_ob, "end_shadow", hide_ob); 
        write("You recover yourself.\n");
        return 1;
    }
    /* just to be sure */
    apply(call,_tp,"set_vis");
    write("But you are not hidden.\n");
    return 1;
}
