inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

  set_name("White Serpent");
  set_alias("serpent");
  set_long("A very large serpent composed of what appears to be fog of some sort.\n"+
  "Its twenty foot long body coils tightly as you approach. \n");
  set_al(0);
  set_ac(16);
  set_level(18);
  set_con(14);
  set_wc(14);
  set_hp(380);
  set_aggressive(0);
