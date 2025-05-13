
inherit "/players/whisky/obj/std_potion";


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","blue potion","light blue potion"}));
      set_long("It look like a drink container.\n");
      set_value(20);
      drink_msg = "Ahhh you feel a bit tipsy but much better now !\n";
      functions = ([ "heal_self":40,   
                     "drink_alcohol":10 ]);
     }
}

   

