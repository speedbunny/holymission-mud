inherit "/players/whisky/obj/std_potion";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","yellow potion"}));
     set_shadow("/players/beardy/walhalla/obj/wis_shad",500+random(249),"wis_shad");
     set_long("You read the words 'Wisdom rules'\n");
      set_value(250);
      drink_msg = "You feel wiser now.\n";
     }
}

   

