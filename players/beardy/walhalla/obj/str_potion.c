inherit "/players/whisky/obj/std_potion";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","dark red potion"}));
     set_shadow("/players/beardy/walhalla/obj/str_shad",500,"str_shad");
     set_long("You read the words 'Strength'\n");
      set_value(250);
      drink_msg = "You feel stronger now.\n";
     }
}

   

