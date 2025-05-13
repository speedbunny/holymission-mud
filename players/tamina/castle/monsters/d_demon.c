/* Dust Demon */  

inherit "/obj/monster";

#include "/players/tamina/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;

    set_name("dust demon");
    set_alias("demon");
    set_short("Dust Demon");
    set_long(
"This monstrosity swirls up from the very dust on the floor,\n"+
"possessed by some malevolent spirit in the furtherance of evil.\n");
    set_level(30);
    set_ac(19);
    set_n_wc(36);
    set_al(-750);
    set_aggressive(1);
    set_no_ears(1);
    set_prevent_poison(1);
    set_spell_mess2(
"The Dust Demon causes you to inhale its poisonous dust!!\n");
    set_spell_mess1(
"The Demon of Dust throws a cloud of harmful Dust at its victim !!\n");
    set_chance(33);
    set_spell_dam(30 + random(65));
    add_money(1000 + random(2001));
    set_dead_ob(TO);
}

monster_died() 
{
    TRM (E (TO),
"The Dust falls to the ground, reverting to the state it was in before...\n");  
    destruct(TO);
    return 1;
}

init() 
{
  ::init();
  add_action("assassinate", "assassinate");
  add_action("suggest",     "suggest");
  add_action("hold",        "hold");
  add_action("timehold",    "timehold");
  add_action("death",       "death");
  add_action("freeze",      "freeze");
}

assassinate() 
{
    TRM (E (TO),
"The Demon whispers: How canst thou Assassinate that which dost not live?\n");
    return 1;
}

int suggest(string str)
{
  if (str == "fear demon")
  {
    TRM (E (TO),
"The Dust Demon is not open to suggestion.\n");
    return 1;
  }
  return 0;
}

timehold()
{
    TRM (E (TO),
"The Demon rasps: Fool!!  Thou canst not hold me!!\n");
    return 1;
}

hold()
{
    TRM (E (TO),
"The Demon rasps: Fool!!  Thou canst not hold me!!\n");
    return 1;
}

death() 
{
    TRM (E (TO),
"The Demon grins: Thou canst not kill that which dost not live...\n");
    return 1;
}

freeze()
{
    TRM (E (TO),
"The Dust Demon sneers: Thine puny command over the Elements is useless\n"+
"                       against me !!\n");
    return 1;
}

