inherit "/obj/std_potion";

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
      add_name(({"potion","purple potion"}));
     set_shadow("/players/beardy/walhalla/obj/int_shad",300,"int_shad");
     set_long("You read the words 'Intelligence'\n");
      set_value(250);
      drink_msg = "You feel more intelligent now.\n";
     }
}
