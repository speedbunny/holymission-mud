inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("The Rod of Demons");
  set_short("The Rod of Demons");
  set_long("This rod seems to give off strange power.\n" +
           "It is nearly 2 meters long and is pretty heavy.\n" +
           "There are exotic looking runes inscribed on the rod.\n" +
           "This weapon feels very good in your hands.\n");
  set_alias("rod");
  set_alt_name("rod of demons");
  set_read("You can't read the runes, but you think it says\n" +
           "something about awesome power!!\n");
  set_class(20);
  set_value(6000);
  set_weight(6);
  set_hit_func(this_object());
}
weapon_hit(attacker) {
  if(attacker->id("figley")) {
  write("Your rod won't hit Figley!\n");
  return (-1000);
  }
}
