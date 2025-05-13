/* =============================================================== 
   Userdoc: Bless             /players/whisky/guild/skills/bless.c
   ---------------------------------------------------------------
   Art: (self or friend) raises the damage of normal attacks temporarly 
   Damage || Heal: 10 points enhanced_damage (type 0)
   Cost: 20
   Special: learnable by training or master / look under bless_shad.c
            in the /obj/shadows/ directory.
   =============================================================== */

#define COST 20

inherit "/players/whisky/guild/skill_obj";
#include "gdef.h"

void reset(int flag) {
    ::reset(flag);
    if (flag == 0)
       set_partner("/players/sauron/guild/room");
}

int bless(string arg) {
    object mob;
    object shad;
    string name;
    string poss;
    string rel;

    rel = apply(call,_tp,"query_religion");

   if (!stringp(rel)) {
       write("But you arn't a believer in any god.\n");
       return 1;
   }
   else if (arg && lower_case(arg)==apply(call,_tp,"query_real_name") 
       && apply(call,_tp,"query_attack")) {
      write("No way you are fighting for your life!\n");
      return 1;
   }
   else if (objectp(mob = chk_present(_tp,arg,COST))) {
      name = apply(call,mob,"query_name");
      poss = apply(call,_tp,"query_possessive");

      if (apply(call,mob,"shad_id","bless")) {
          if (mob != _tp)
              write("But, "+name+" is already blessed!\n");
          else
              write("But, you are already blessed!\n");
          return 1;
      }
      if (!chk_skill(_tp,"monk_bless",3)) {
          write("But, "+rel+" doesn't hear you!\n");
          apply(call,_tp,"restore_spell_points", - (1+COST)/2 );
          return 1;
      }
      if (mob != _tp)  {
         write("You bless "+name+" in the name of "+rel+"!\n");
         say(_tpn+" gives "+poss+" blessings to "+name+"!\n",mob,_tp);
         tell_object(mob,"You feel blessed!\n");
      }
      else {
         mob = _tp;
         tell_object(mob,"You feel blessed!\n");
      }
      shad = clone_object("/obj/shadows/bless_shad");
      apply(call,shad,"set_effects","bless");
      apply(call,shad,"start_shadow",mob,700); 
      apply(call,_tp,"restore_spell_points", - COST );
   }
   return 1;
}

