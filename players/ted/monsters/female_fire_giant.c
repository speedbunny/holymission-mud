inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("female fire giant");
 set_alias("female");
 set_race("giant");
 set_short("A Female Fire Giant Scout");
 set_level(14 );
 set_ep(100000 );
 set_hp(200 );
 set_wc(20 );
 set_ac(5 );
 set_al(-150 );
 set_aggressive(1 );
}
