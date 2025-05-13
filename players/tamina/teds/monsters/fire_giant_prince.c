inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("fire giant prince");
 set_alias("prince");
 set_short("Fire Giant Prince");
 set_race("giant");
 set_long("This small boy is the son of the Fire Giant King.\n");
 set_level(11);
 set_ac(4);
 set_hp(260);
 set_wc(15);
 set_al(-250);
}
