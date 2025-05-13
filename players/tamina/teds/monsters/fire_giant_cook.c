inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("fire giant cook");
 set_alias("cook");
 set_short("Fire Giant Cook");
 set_race("giant");
 set_long(
 "This is a plump red faced cook. His white hat sits crookedly on his head.\n");
 set_level(8);
 set_ac(2);
 set_hp(200);
 set_wc(15);
 set_al(-250);
 set_whimpy(25);
 set_chance(45);
 set_spell_dam(10);
 set_spell_mess2("The cook spills boiling hot water on you!");
 set_spell_mess1("The cook spills a pot of hot water.");
}
