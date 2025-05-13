/* =============================================================== 
   Userdoc: Hide               /players/whisky/guild/skills/hide.c
   ---------------------------------------------------------------
   Art: Hide and seek
   Damage || Heal: none
   Cost: 10 power (so called spellpoints)
   Special: learnable by training or master / a player never knows
            if she is hidden / even as hidden by a new hide it gives
            a new reroll / gets unhidden if attacked / can be seen
            ever with detect invis or true sight.
   =============================================================== */
 
#define COST _cost(10)

inherit "/players/whisky/guild/skill_obj";

#include "gdef.h"

void reset(int flag) {
    ::reset(flag);
    if (flag == 0)
        set_partner("/players/sauron/guild/room");
}

int hide(string arg) {
   object shad;
   object vic;
   object hide_shad; 
   
    if (arg) 
        return 0;
    else if (chk_ghost(_tp))
        return 1;
    else if (objectp(vic= apply(call,_tp,"query_attack")) && _e(_tp)==_e(vic)
             && !apply(call,_tp,"query_invis")) {
        write("No way you are fighting for your life!\n");
        return 1;
    }
    else if (_tps < COST) {
        write("You don't feel agil enough to hide yourself!\n");
        return 1;
    }
    if (objectp(hide_shad = apply(call,_tp,"hide_object"))) {
         apply(call,hide_shad,"end_shadow",hide_shad);
         say(_tpn+" arrives.\n",_tp);
    }
    if (!chk_skill(_tp,"monk_hide",3)) {
        write("You attemt to hide yourself!\n");
        apply(call,_tp,"restore_spell_points",- (1 + COST)/2);
        return 1;
    }
    if (random(60) < (30 + _tpd/2)) {
        say(_tpn+" hides "+
        apply(call,_tp,"query_objective")+"self in the darkness!\n",_tp);

        if (apply(call,_tp,"hide_shad"))
            destruct(apply(call,_tp,"hide_object"));

        shad = clone_object(_shad+"hide_shad");
        this_player()->set_invis(this_player()->query_level()-1);
        funcall(call,shad,"start_shadow",_tp, 100 + 
                     random(_tpw * 2),"hide_shad");
    }
    write("You attemt to hide yourself!\n");
    apply(call,_tp,"restore_spell_points",-COST);
    return 1;
}

