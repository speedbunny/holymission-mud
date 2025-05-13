inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("young frost giant");
 set_race("giant");
 set_alias("young giant");
 set_short("A Young Frost Giant");
 set_level(14);
 set_ep(100000);
 set_aggressive(1);
 set_hp(200);
 set_wc(20);
 set_ac(4);
 set_al(-150);
}
