inherit "/players/whisky/obj/std_potion";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","yellow potion"}));
     set_shadow("/players/beardy/test_shadow",0,random(1000));
     set_long("You read the words 'Wisdom rules'\n");
      set_value(250);
      drink_msg = "You feel wiser now.\n";
     }
}

   

