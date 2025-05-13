/* =============================================================== 
   Userdoc: Smash           /players/whisky/guild/skills/smash.c
   ---------------------------------------------------------------
   Art: damage stun
   Damage || Heal: 5 + dex
   Cost: dex (higher because of stun effect)
   Special: learnable by training or master / won't work on too big
            or small victims / 1/3 stunfailure change / stun min 1 round
   =============================================================== */

#define DAM  _dam(5 + _tpd)
#define TIME ( 3 + _tpd/19)
#define COST _cost(_tpd)

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag) {
    ::reset(flag);
    if (flag==0)
       set_partner("/players/sauron/guild/room");
}

int smash(string arg) {
    object mob;
    int size;
    string name;


    if (objectp(mob = chk_attack(_tp,arg,COST))) {
	     size = apply(call,mob,"query_size");
	     name = apply(call,mob,"query_name");


        if(!chk_skill(_tp,"monk_smash",6) ||
	   (apply(call,_tp,"hinder_abilities") && random(2)) ) {
	    write("You try to hold down "+name+", but fall on your butt!\n");
	    say(_tpn+" tries a combat move, falls on "+_tpp+" butt!\n",
	      _tp,mob);
	    tell_object(mob,_tpn+" tries to hold you down, but falls on "+
	      _tpp+" butt!\n"); 

	    apply(call,_tp,"restore_spell_points",- (1 + COST)/2);
	    apply(call,mob,"attack_object",_tp);
	    apply(call,_tp,"hold",_tp,random(2));
            return 1;
	}
	else if (size > 1 && size < 5) {
	    write("You hold down "+name+"'s neck and raise your knee!\n");
	    say(_tpn+" holds down "+name+"'s neck and  raises "+_tpp+
	      " knee!\n",_tp,mob);
	    tell_object(mob,_tpn+" holds you down and raises "+_tpp+" knee!\n");

		 apply(call,_tp,"attack_object",mob);
		 apply(call,mob,"hit_player",DAM,2);

		 if (objectp(mob))
           if (random(5))
		 apply(call,mob,"hold",_tp,1 + random(TIME));
	    apply(call,_tp,"restore_spell_points",-COST);
	    return 1;
	}
	else if (size < 2)
	    write(name+" is too small to smash!\n");
	else 
	    write(name+" is too large to smash!\n");
	    return 1;
    }
    return 0;
}

