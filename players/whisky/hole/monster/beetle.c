inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return 1;
  set_name("beetle");
  set_short("A big brown beetle");
  set_long("A big brown beetle crawling around.\n");
  set_race("insect");
  set_level(1);
  set_size(1);
  set_al(10);
  set_hp(30);
  set_ep(400);
  set_wc(2);
 return 1;
}
