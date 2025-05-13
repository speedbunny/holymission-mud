/* =============================================================== 
   Userdoc: Springleap   /players/whisky/guild/skills/springleap.c
   ---------------------------------------------------------------
   Art: damage for one to 5 victims, type 0 (weaponhit) 
   Damage || Heal: dex * 4 
   Cost: dex * 3  costs a bit more because of the area effect 
   Special: learnable by training or master / can't hit a player
   =============================================================== */
 
#define DAM   _dam (_tpd * 5)
#define COST  _cost(_tpd * 3)

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag) {
    ::reset(flag);
    if (flag == 0)
        set_partner("/players/sauron/guild/room");
}

int springleap() {
    object *inv; 
    string loc;
    int i, sz;
    int max;

    if (chk_ghost(_tp))
        return 1;
    else if (apply(call,_tp,"query_sp") < COST) {
        write("You are too low on power.\n");
        return 1;
    }
    if ( !chk_skill(_tp,"monk_springleap",8) ||
         (random(2) && apply(call,_tp,"hinder_abilities"))) {
        write("You jump high in the air, but fall on your butt!\n");
        say(_tpn+" jumps high into the air, but falls on "+_tpp+" butt!\n",
            _tp);
        apply(call,_tp,"restore_spell_points",- (1 + COST)/2);
        return 1;
    }
    max = 5;
    inv = all_inventory(_e(_tp));
    sz = sizeof(inv);

    write("You jump high up into the air striking wildly around!\n");
    say(_tpn+" jumps high up into the air striking wildly around!\n",_tp);

    while(sz && max) {
       if (inv[(sz-1)]!=_tp && !apply(call,inv[(sz-1)],"query_invis") 
           && living(inv[(sz-1)])
           && !interactive(inv[(sz-1)]) && 
           !apply(call,inv[(sz-1)],"query_familiar")) {
           switch(max) {
              case 5: 
                loc = "right foot";
                break;
              case 4: 
                loc = "left foot";
                break;
              case 3: 
                loc = "right fist";
                break;
              case 2: 
                loc = "left fist";
                break;
              default: 
                loc = "elbow";
                break;
           }
           write("You hit "+apply(call,inv[(sz-1)],"query_name")+
                 " with your "+loc+".\n");
           say(_tpn+" hits "+apply(call,inv[(sz-1)],"query_name")+" with "+
               _tpp+" "+loc+".\n",_tp,inv[(sz-1)]);
           tell_object(inv[(sz-1)],_tpn+" hits you with "+_tpp+" "+loc+"!\n");
           apply(call,inv[(sz-1)],"hit_player",DAM,1);
           max--;
       }
       sz--;
    }
    if (max < 5)
        apply(call,_tp,"restore_spell_points",-COST);
    return 1;
}

