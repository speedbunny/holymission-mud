inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("an ugly fairy");
  set_alias("fairy");
  set_alt_name("fairy");
  set_short("An UGLY Fairy");
  set_long("This seems to resemble a fairy, but she is one of the UGLIEST things\nyou have ever seen...\n");
  set_level(5);
  set_al(100);
  set_hp(100);
  set_ep(5000);
  set_wc(6);
  add_money(75);
  set_ac(2);
  set_aggressive(0);
  return 1;
}


