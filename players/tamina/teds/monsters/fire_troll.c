inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("fire troll");
 set_race("troll");
 set_short("An Evil Fire Troll");
 set_long("This creature vaguely resembles a troll made of molten lava.\n");
 set_alias("evil troll");
 set_whimpy(25);
 set_level(9);
 set_hp(100);
 set_wc(10);
 set_al(-100);
 set_aggressive(1);
}
