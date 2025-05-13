inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("frost giant queen");
 set_alias("queen");
 set_race("giant");
 set_short("Frost Giant Queen");
 set_long("This is the Frost Giant Queen. She looks very elegant and quite beautiful.\n");
 set_level(11);
 set_ac(2);
 set_hp(260);
 set_wc(15);
 set_al(250);
}
