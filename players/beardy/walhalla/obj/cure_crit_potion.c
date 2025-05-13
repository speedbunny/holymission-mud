inherit "/players/whisky/obj/std_potion";


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","dark blue potion"}));
      set_long("You read on the vial 'cure serious'.\n");
      set_value(250);
      drink_msg = "You feel better now !\n";
      functions = ([ "heal_self":200 ]);
     }
}

