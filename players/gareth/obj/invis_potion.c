
inherit "/players/whisky/obj/std_potion";


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","crystalic potion"}));
      set_shadow("/players/whisky/obj/invis_shad",500,"invis_shad");
      set_long("You read the word 'invis'.\n");
      set_value(250);
      drink_msg = "You vanish.\n";
     }
}

   

