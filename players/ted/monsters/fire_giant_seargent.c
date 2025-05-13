inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("fire giant seargeant");
 set_alias("seargent");
 set_short("Fire Giant Seargeant");
 set_race("giant");
 set_long("This Fire Giant looks meaner and tougher than your average fire giant.\n");
 set_level(17);
 set_ac(8);
 set_hp(550);
 set_wc(25);
 set_al(-550);
 set_whimpy(25);
 set_aggressive(1);
 set_chance(45);
 set_spell_dam(30);
 set_spell_mess2("The Seargeant smashes you in the face with his fist!");
 set_spell_mess1("The Seargeant's fists are deadly!");
}
