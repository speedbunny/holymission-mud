/* Norker, a cousin of the hobgoblins */

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("norker");
    set_alias("goblin");
    set_level(random(10)+10);
    set_alt_name("norker");
    set_race("goblin");
    set_short("A norker");
    set_long("Far-distant relative of the goblin. Has "+this_object()->query_level()/6+" foot long fangs.\n"+
             "Looks similar to a hobgoblin, but shorter and tougher skin.\n");
    set_al(-100);
    set_gender(random(3));
    load_chat(8,({
      "Norker shakes a fist at you!\n",
      "Norker goblin spits in your general direction.\n",
      "Norker licks you with a wart covered tongue!\n",
      "Norker farts rudely.\n",
                 }));
    set_move_at_reset();
    set_aggressive(1);
    set_spell_mess1("Norker bites you!\n");
    set_spell_mess2("Norker bites you hard!");
    set_chance(20);
    set_spell_dam(10);
  }
}
