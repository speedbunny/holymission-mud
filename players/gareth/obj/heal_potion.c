
inherit "/players/whisky/obj/std_potion";


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","red potion"}));
      set_long("You read on the vial 'heal'.\n");
      set_value(4000);
      drink_msg = "You feel much better now !\n";
      functions = ([ "heal_self":1000 ]);
     }
}

   

