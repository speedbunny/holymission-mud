/* =============================================================== 
   Userdoc: Death             /players/whisky/guild/skills/death.c
   ---------------------------------------------------------------
   Art: damage self && victim  (critical, prepared fullhit)
   Damage || Heal: victim dex * 7 : higher is the victim
                   has a far lower level, own rnd(3 * level)
   Cost: dex * 4 where half of the costs is own hitpoints
   Special: learnable by training or master / risc of selfkill /
            stunpossibility chance 1/3 for max. random(2) rounds /
   =============================================================== */


#define DAM    _dam(_tpd * 5)
#define COST   _cost(_tpd * 3)
#define ODAM   _cost(COST)

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag) {
    ::reset(flag);
    if (flag == 0)
        set_partner("/players/sauron/guild/room");
}

int death(string arg) {
    object mob;
    string name;
    int dam;

    if (objectp(mob = chk_attack(_tp,arg,COST))) {
	     name = apply(call,mob,"query_name");

	     if (!chk_skill(_tp,"monk_death",9) ||  
	        (random(2) && apply(call,_tp,"hinder_abilities"))) {
	         write("You concentrate your powers, but fall on your butt!\n");
	         say(_tpn+" tries a combat move, falls on "+_tpp+" butt!\n",
	             _tp,mob);
	         tell_object(mob,_tpn+" tries to hit you but falls on "+
	             _tpp+" butt!\n"); 

	         apply(call,_tp,"restore_spell_points",- ((1 + COST)/2));
	         apply(call,mob,"attack_object",_tp);
                 apply(call,_tp,"hold",mob,random(3));
                 return 1;
	     }
	     write(
	     "You concentrate your powers and give "+name+" a deadly blow!\n");
	     say(_tpn+" gives "+name+" a deathly blow!\n",_tp,mob);
	     tell_object(mob,_tpn+" gives you a deadly blow!\n"); 

	     if (living(mob)) {
	         apply(call,_tp,"attack_object",mob);
	         if (!random(3))
		           apply(call,mob,"hold",_tp,1 + random(2));

                 dam = DAM;
// to very low levels better hit
	         if (apply(call,mob,"query_con") < _tpl)
		          dam *= 2;
	         if (mob && living(mob)) {
                if (dam > apply(call,mob,"query_hp")) {
                   tell_object(mob,"You puke out your guts!\n");
                   write(apply(call,mob,"query_name")+" pukes out "+
                         apply(call,mob,"query_possessive")+" guts!\n");
                   say(apply(call,mob,"query_name")+" pukes out "+
                         apply(call,mob,"query_possessive")+" guts!\n",_tp);
                }
		          apply(call,mob,"hit_player",dam,7);
            }
	     }
	     if (living(_tp)) {
	         apply(call,_tp,"restore_spell_points",-COST);
	         if (ODAM)
		          apply(call,_tp,"hit_player",random(ODAM),7);
	     }
	     return 1;
    }
    return 0;
}
