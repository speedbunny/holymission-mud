
/* dragon */

inherit "/obj/npc";

void reset(int flag)
{
    ::reset(flag);
    if (flag == 0)
    {
      set_name("fat dragon");
      set_alt_name("dragon");
      set_short(query_name());
      set_long(
      "A big, fat, brown dragon glaring hungrily at you !\n");
      set_level(20);
      set_attacks(3);
      add_money(900);
      set_attacks_change(40);
      set_spell_mess1("The Fat Dragon breathes a cone of fire !\n");
      set_spell_mess2("You are hit by a cone of fire !\n");
      set_chance(80);
      set_spell_dam(60);
      set_dead_ob(this_object());
    } 
}

int monster_died(object ob)
{
   object gal;

  gal = present("galonhel",environment());
  if (gal)
      gal->split_exp();
  return 0;
}

int run_away()
{
    return 0;
}

