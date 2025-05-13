inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("fire salamander");
 set_alias("salamander");
 set_short("A Firey Salamander");
 set_level(13);
 set_hp(300);
 set_whimpy(25);
 set_wc(30);
 set_ac(3);
 set_aggressive(1);
}
