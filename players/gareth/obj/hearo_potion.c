
inherit "/players/whisky/obj/std_potion";


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","brown potion"}));
      set_long("You read on the vial 'hearos feast'.\n");
      set_value(6000);
     drink_msg = "You feel completely restored !\n";
     functions = ([
                   "heal_self":1000,
                   "add_poison":-10000,
                   "drink_alcohol":2,
                   "drink_soft":2,
                   "eat_food":2 
                ]);
     }
}

   

