
inherit "/obj/std_potion";


void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","black potion"}));
      set_long("You read on the vial 'cure poison'.\n");
      set_value(150);
      drink_msg = "You feel much healthier now !\n";
      functions = ([ "add_poison":-10000 ]);
     }
}

   

