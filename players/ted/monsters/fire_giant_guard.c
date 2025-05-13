inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("fire giant guard");
 set_alias("guard");
 set_short("A Fire Giant Guard");
 set_race("giant");
 set_long(
"This is a dirty, smelly fire giant. He is about 10 feet tall and must weigh\n"+
"in at around 400 pounds. He doesn't look very happy that you are here.\n");
 set_level(14);
 set_ac(6);
 set_hp(350);
 set_wc(25);
 set_al(-450);
 set_whimpy(25);
 set_aggressive(1);
}
