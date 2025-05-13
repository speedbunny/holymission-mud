 inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("ice troll");
 set_alias("ice");
 set_race("troll");
 set_short("An Ugly Ice Troll");
 set_level(9);
 set_hp(100);
 set_wc(10);
 set_al(-60);
 set_whimpy(25);
 set_aggressive(1);
}
