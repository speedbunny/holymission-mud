
/* please don't copy this potion is only a gag :) */
inherit "/players/whisky/obj/std_potion";


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","red potion"}));
      set_shadow("/players/whisky/obj/red_bull_shad",200,"red_bull_shad");
      set_long("You read on the vial 'red bull'.\n");
      set_value(450);
      drink_msg = "You feel your speed increasing !\n";
     }
}

   

