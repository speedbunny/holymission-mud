inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("orc");
 set_race("orc");
 set_short("A Dirty Orc");
 set_level(random(3)+2);
 set_aggressive(1);
 set_hp(35);
 set_al(-60);
}
