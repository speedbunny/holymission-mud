inherit "/players/beardy/obj/std_potion";

reset(int arg)
{ ::reset(arg);
  if(!arg)
  { add_name(({"potion","gray potion"}));
    set_shadow("/players/beardy/obj/gray_shad",5,"gray_shad");
    set_long("You read the word 'superman'.\n");
    set_value(1000);
    drink_msg="You feel like superman now.\n";
   }
}
