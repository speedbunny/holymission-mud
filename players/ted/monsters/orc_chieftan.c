inherit "obj/monster"; 

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("orc chieftan");
 set_alias("orc");
 set_race("orc");
 set_long("This is an above average orc, problably a leader of some type.\n");
 set_aggressive(1);
 set_level(4);
 set_wc(12);
 set_ac(4);
 set_al(-100);
}
