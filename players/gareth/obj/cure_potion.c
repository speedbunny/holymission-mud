
inherit "/players/whisky/obj/std_potion";


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","pink potion"}));
      set_long("You read on the vial 'cure light'.\n");
      set_value(250);
      drink_msg = "You feel better now !\n";
      functions = ([ "heal_self":50 ]);
     }
}

   

