inherit "/obj/npc";
#include "/players/saffrin/defs.h"

int monster_died(object ob) {

    shout("Jack the Ripper has been slain at "+CRN+"'s hands.\n");
 return 0;
}

void reset(int arg) {

  ::reset(arg);

  if(!arg) {
    set_name("Jack the Ripper");
    set_short("Jack the Ripper");
    set_long("This handsome young man is richly dressed and has an air "+
             "of snobbery to him.  He looks down his nose at you.  His eyes "+
             "appear a bit shifty.\n");
    set_alias("jack");
    set_race("ripper");
    set_level(75 + random(10));
    set_al(-500);
    set_gender(1);
    set_attacks_change(100);
    set_attacks(4);
    set_dodge(30);
    set_aggressive(1);
    add_money(7000 + random(2000));
    set_spell_mess2("Jack the Ripper grins in pleasure as he slices "+CQN+".\n");
    set_chance(1);
    set_spell_dam(50 + random(50));
    set_dead_ob(TO);

    MOVE(CLONE(PK+"obj/knife"),TO);
         init_command("wield knife");
  }
}

 
