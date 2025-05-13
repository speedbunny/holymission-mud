inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("fire giant scout");
 set_alias("scout");
 set_race("giant");
 set_short("A Fire Giant Scout");
 set_level(16 );
 set_hp(350 );
 set_wc(20 );
 set_ac(4 );
 set_al(-150 );
 set_aggressive(1 );
}
