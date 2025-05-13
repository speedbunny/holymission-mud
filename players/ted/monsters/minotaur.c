inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("minotaur");
 set_alias("bull");
 set_race("human");
 set_short("A Minotaur");
 set_long("This is a huge manlike creature with the head of a bull.\n");
 set_level(15);
 set_hp(500);
 set_wc(20);
 set_ac(7);
 set_al(-250);
 set_aggressive(1);
}
