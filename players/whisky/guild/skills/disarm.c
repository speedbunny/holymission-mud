/* =============================================================== 
   Userdoc: Disarm          /players/whisky/guild/skills/disarm.c
   ---------------------------------------------------------------
   Art: weapon grap, if sucess the weapon falls to the ground
   Damage || Heal: none
   Cost: none
   Special: learnable by training or master / chance is a dexcombat
            between monk and victim. Failure means a high chance the
            victim checks it and attacks. / very slow feature
   =============================================================== */

inherit "/players/whisky/guild/skill_obj";

#include "gdef.h"

void reset(int flag) {
    ::reset(flag);
    if (flag == 0)
       set_partner("/players/sauron/guild/room");
}
 
int disarm(string arg) {
   object mob;
   string name;
   string poss;
   object *inv;
   int i, sz;
   int formula;


   if (objectp(mob = chk_present(_tp,arg,0))) {
      name = apply(call,mob,"query_name");
      poss = apply(call,mob,"query_possessive");

      if (mob == _tp) {
         write("You bite yourself in your hands.\n");
         return 1;
      }
#if 0
// 230498: Sauron: Removed hands check... irelevant.
      else if (apply(call,mob,"query_hands_free") > 1) {
          write("Trying to cut of the hands off of "+name+"?\n");
          return 1;
      }
#endif
      else if (_e(_tp) && _e(_tp)->query_property("no_fight")) {
        write("You feel too peaceful for that action!\n");
        return 1;
      }
      else if (!objectp(apply(call,mob,"query_wielded"))) {
         write("But "+apply(call,mob,"query_name")+" has no wielded weapon.\n");
         return 1;
      }

      if (apply(call,mob,"query_no_steal") || 
          !chk_skill(_tp,"monk_disarm",4)) {
         write("You failed to disarm "+name+".\n");
         tell_object(mob,"You feel a hand trying to grap your weapon!\n");
         if (apply(call,mob,"query_npc") 
             && (random(apply(call,mob,"query_int")) > _tpd))
             apply(call,mob,"attack_object",_tp);
         return 1;
      }

      if (apply(call,_tp,"query_attack") && 
         mob == apply(call,_tp,"query_attack") )    
         formula = _tpd;
      else 
         formula = _tpd * 2;

      if ( random(formula) < random(apply(call,mob,"query_dex")/2)) {
         write("You failed to disarm "+name+".\n");
         tell_object(mob,"You feel a hand trying to grap your weapon!\n");
         if (apply(call,mob,"query_npc") && 
            (random(apply(call,mob,"query_int")) > _tpd))
             apply(call,mob,"attack_object",_tp);
         return 1;
      }
      else {
         write("Successfully you disarm "+name+".\n");
         tell_object(mob,"You lost your wielded weapon!\n");
        
         inv = all_inventory(mob);
 
         for(sz = sizeof(inv), i = 0; i < sz; i++) {
             if (apply(call,inv[i],"query_wielded")) {
                 apply(call,mob,"stop_wielding",inv[i]);
                 transfer(inv[i],_e(_tp));
                 return 1;
              }
         }
         if (apply(call,mob,"query_npc") && 
            (random(apply(call,mob,"query_int")) > _tpd))
             apply(call,mob,"attack_object",_tp);
     }
     return 1;
   }
   return 1;
}

