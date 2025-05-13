inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("levert");
  set_alias("rabbit");
  set_short("A tiny levert");
  set_long("This seems to be a young rabbit.\n");
  set_race("mammal");
  set_level(1);
  set_al(30);
  set_hp(30);
  set_wc(1);
  add_money(30);
}
