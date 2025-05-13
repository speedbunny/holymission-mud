
inherit "/players/whisky/obj/std_potion";


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","red potion"}));
      set_shadow("/players/whisky/obj/haste_shad",120,"haste_shad");
      set_long("You see a red bull on the vial and the inscription 'haste'.\n");
      set_value(450);
      drink_msg = "You feel your speed increasing !\n";
     }
}

   

