inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("hunter");
 set_alias("hunter");
 set_race("human");
 set_long("This is an experianced looking hunter.\n");
 set_level(8);
 set_wc(15);
 set_ac(2);
 set_al(60);
}
