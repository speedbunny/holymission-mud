inherit "/obj/npc";
#include "/players/saffrin/defs.h"
      
object sword, platemail, gloves, boots, shield, ring, script;
      
void reset (int arg){

  ::reset(arg);
   if (!arg) {
      set_name("Hamlet");
      set_short("Hamlet, Prince of Denmark");
      set_long("The handsome young Prince of Denmark who is the rightful\n"+
                     "ruler of the land.  It is said he was driven mad by the death of\n"+
                     "his father.\n");
      set_alias("hamlet");
      set_race("human");
      set_level(100);
      set_ac(40);
      set_wc(40);
      set_al(1000);
      set_hp(18000);
      set_gender(1);
      set_attacks_change(100);
      set_attacks(7);
      set_dodge(30);
      set_aggressive(1);
      add_money(15000 + random(9000));
      set_spell_mess2("Hamlet cackles as he pounds you to a bloody pulp.\n");
      set_chance(10);
      set_spell_dam(100);
      set_dead_ob(this_object());

      MOVE(CLONE(HAM+"obj/hsword"),TO);
        init_command("wield sword");
      MOVE(CLONE(HAM+"obj/hplate"),TO);
        init_command("wear platemail");
      MOVE(CLONE(HAM+"obj/hshield"),TO);
        init_command("wear shield");
      MOVE(CLONE(HAM+"obj/hgloves"),TO);
        init_command("wear gloves");
      MOVE(CLONE(HAM+"obj/hboots"),TO);
        init_command("wear boots");
      MOVE(CLONE(HAM+"obj/hring"),TO);
        init_command("wear ring");
  }
}
     
init() {

  ::init();
     add_action("_nope","steal");
     add_action("_nope","melee");
     add_action("_nope", "hold");
     add_action("_nope", "backstab");
    
 }

 _nope() {
     write("Hamlet skillfully blocks that move!\n");
     say("Hamlet blocked a move by "+TPQN+".\n");
  return 1;
}
     
detect_invis() {
   return 1;
}

int monster_died(object ob){

object medal;

  if(present("medal",TP)) {
     return 0;
  }
  ME("You receive a medal for your courage.\n");
  medal = CLONE(HAM+"obj/badge");
  transfer(medal,TP);
  return 0;
 }
     shout(CRN+" hath destroyed Hamlet, Prince of Denmark.\n");
  return 0;

  } else {
     tell_room(environment(this_object()),"Hamlet killed by someone.\n",this_player());
     write("You are a wizard, no shout will occur.\n");
  return 0;
  }
  return 1;
}
    
