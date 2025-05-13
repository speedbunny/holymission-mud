inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("gopher");
  set_race("rodent");
  set_short("Gopher");
  set_long("A little brown gopher.\n");
  set_level(7);
  set_hp(90);
  set_wc(5);
  set_ac(5);
  add_money(20);
}
