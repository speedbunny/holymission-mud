inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("wooly mammoth");
 set_race("mammoth");
 set_alias("mammoth");
 set_short("A Huge Wooly Mammoth");
 set_level(13);
 set_hp(300);
 set_wc(30);
 set_ac(3);
 set_whimpy(25);
 set_aggressive(1);
}
