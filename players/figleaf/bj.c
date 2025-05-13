inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("bj");
  set_short("BJ");
  set_long("An annoying yellow dinosaur wearing a baseball cap. Another one\n"+
           "of Barney's 'friends'.\n");
  set_race("dinosaur");
  set_level(20);
  set_al(1000);
  set_aggressive(0);
  return 1;
}


