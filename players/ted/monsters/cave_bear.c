inherit "obj/monster"; 

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("cave bear");
 set_alias("cave bear");
 set_race("bear");
 set_short("A Giant Cave Bear");
 set_long("This giant bear is chained to the wall with a heavy iron chain.\n");
 set_level(15);
 set_ac(5);
 set_hp(400);
 set_wc(20);
 set_al(-10);
 set_chance(40);
 set_spell_dam(40);
 set_spell_mess1("The cave bear roars his anger");
 set_spell_mess2("The Cave Bear rips you appart with his claws");
}
