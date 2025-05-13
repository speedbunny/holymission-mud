inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("griffon");
 set_short("Griffon");
 set_alias("griffon");
 set_race("griffon");
 set_long("This creature has the body of a lion and the head of a bird.\n");
 set_level(17);
 set_wc(20);
 set_ac(9);
 set_hp(750);
 set_al(-100);
 set_aggressive(1);
}
