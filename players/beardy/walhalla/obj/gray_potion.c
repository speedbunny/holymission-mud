inherit "/players/whisky/obj/std_potion";

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { add_name(({"potion","gray potion"}));
    set_shadow("/players/beardy/walhalla/obj/gray_shad",30,"gray_shad");
    set_long("You read the word 'stone skinn'.\n");
    set_value(1000);
    drink_msg="Your skinn gets darker.\n";
   }
}
