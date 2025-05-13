inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("ice elemental");
 set_alias("ice");
 set_race("elemental");
 set_level(10);
 set_ep(100000);
 set_hp(250);
 set_wc(25);
 set_al(-100);
 set_aggressive(1);
 set_whimpy(25);
}
