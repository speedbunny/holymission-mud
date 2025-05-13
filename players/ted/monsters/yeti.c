inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("yeti");
 set_race("ape");
 set_short("A Huge White Yeti");
 set_long("A huge white snow ape.\n");
 set_level(10);
 set_ep(100000);
 set_hp(300);
 set_wc(15);
 set_ac(5);
 set_whimpy(25);
}
