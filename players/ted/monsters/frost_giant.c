inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("frost giant hunter");
 set_alias("hunter");
 set_short("A Frost Giant Hunter");
 set_race("giant");
 set_level(16);
 set_ep(500000);
 set_hp(350);
 set_wc(20);
 set_ac(4);
 set_al(-150);
 set_aggressive(1);
}
