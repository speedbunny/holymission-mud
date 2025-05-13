/* =============================================================== 
   Userdoc: Choke          /players/whisky/guild/skills/choke.c
   ---------------------------------------------------------------
   Art: damage
   Damage || Heal: 10 + dex * 3
   Cost: 5 + dex * 2
   Special: learnable by training or master / dexhit, type 1
   =============================================================== */

#define DAM	_dam(10 + _tpd * 6)
#define COST	_cost(5 + _tpd * 3)

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag) {
    ::reset(flag);
    if (flag==0)
        set_partner("/players/sauron/guild/room");
}

int choke(string arg) {
    object mob;
    string name;
    string poss;
    int size;

    if (objectp(mob = chk_attack(_tp,arg,COST))) {
        name = apply(call,mob,"query_name");
        poss = apply(call,mob,"query_possessive");
        size = apply(call,mob,"query_size");

        if (!chk_skill(_tp,"monk_choke",3) ||
            (random(2) && apply(call,_tp,"hinder_abilities"))) {
            write("You try to choke "+name+", but fall on your butt!\n");
            say(_tpn+" tries to choke "+name+", but falls on "+_tpp+" butt!\n",
            _tp,mob);
            tell_object(mob,_tpn+" tries to choke you, but slips and falls on "+
            _tpp+" butt!\n"); 

            apply(call,_tp,"restore_spell_points",- (1+COST)/2);
            apply(call,mob,"attack_object",_tp);
            apply(call,_tp,"hold",_tp,random(2));
           return 1;
        }
        else if (size < apply(call,_tp,"query_size")) {
            write("You bend over and choke "+name+"'s neck!\n");
            say(_tpn+" bends over and chokes "+name+"'s neck!\n",_tp);
        } 
        else {
            write("You jump at "+name+" and choke "+poss+" neck!\n");
            say(_tpn+" jumps at "+name+" and chokes "+poss+" neck!\n");
        }
        if (living(mob)) {
            apply(call,mob,"attack_object",this_player());
            apply(call,mob,"hit_player",DAM,1);
        }
        if (living(_tp))
            apply(call,_tp,"restore_spell_points",(-COST));
        return 1;
    }
    return 0;
}
