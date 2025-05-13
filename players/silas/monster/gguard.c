inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("guard");
  set_alias("gnome");
  set_short("gnome guard");
  set_long("This creature is quite small for a guard, but it takes its job very \nseriously, so beware!\n");
  set_race("gnome");
  set_level(8);
  set_al(0);
  set_hp(180);
  add_money(150+random(100));
  set_wc(8);
  set_ac(4);
  set_aggressive(1);
  return 1;
}


