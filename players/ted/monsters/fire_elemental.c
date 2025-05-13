inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("fire elemental");
 set_race("elemental");
 set_short("An Evil Fire Elemental");
 set_level(10);
 set_aggressive(1);
 set_whimpy(25);
 set_hp(250);
 set_ac(5);
 set_wc(25);
 set_al(-300 );
}
