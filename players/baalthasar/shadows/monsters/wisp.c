inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(!arg) {

  set_name("Will o' Wisp");
  set_alias("wisp");
  set_ac(19);
  set_wc(10);
  set_hp(300);
  set_al(0);
  set_level(18);
  }
}
