inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
if (arg) return 1;
  set_name("snake");
  set_alias("red snake");
  set_short("A red snake");
  set_long("It looks like a rattlesnake but it's harmless.\n");
  set_race("animal");
  set_level(4);
  set_size(2);
  set_al(50);
  set_whimpy();
 return 1;
 }
