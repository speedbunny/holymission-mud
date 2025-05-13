/* Shadow Demon */  

inherit "/obj/monster";

#include "/players/tamina/defs.h"

object ring;

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

    set_name("Shadow Demon");
    set_alt_name("shadow");
    set_race("demon");
    set_short("Shadow Demon");
    set_long(
"A vicious looking Demon conjured entirely of shadows, that flits\n"+
"through the darkness with terrifying speed, and accuracy.\n");
    set_level(40);
    set_ac(22);
    set_wc(45);
    set_al(-850);
    set_aggressive(1);
    set_spell_mess2("The Demon smothers you in a cloud of Shadow!\n");
    set_spell_mess1("The Demon summons a cloud of Shadow...\n"+
                    "It engulfs its victim completey!!\n");
    set_spell_dam(55+random(46));
    set_chance(24);
    add_money(5000+random(2001));
    set_trapped(1);
    set_dead_ob(TO);
}

monster_died(ob) 
{
  TRM (E (TO),
"\nThe vile creature is banished back to the foul realms\n"+
"from whence it came...\n");

  write("Amidst the dissembling shadows, you can see a shiny ring\n"+
        "fall to the ground...\n");

  MO (CLO (COBJ + "quest/d_ring"), E(TO));

  destruct(TO);
  return 1;
}
