inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return;
  set_name("goldsun");
  set_alias("sun");
  set_race("human");
  set_short("Goldsun.\n");
  set_long("Goldsun is an annoying little brat.\n");
  set_level(99);
  set_wc(1);
  set_hp(1);
  set_ac(1);
  set_str(1);
  set_dex(1);
}

 
