inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("fire giant captain");
 set_alias("captain");
 set_short("Captain of the Guards");
 set_race("giant");
 set_long(
  "This Fire Giant looks like he knows how to command men.\n");
 set_level(17);
 set_ac(8);
 set_hp(750);
 set_wc(25);
 set_al(-550);
 set_aggressive(1);
 set_chance(45);
 set_spell_dam(30);
 set_spell_mess2("The Captain's quickness allows him an extra strike at you.");
 set_spell_mess1("The Captain's quickness is amazing!");
}
