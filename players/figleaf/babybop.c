inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("baby bop");
  set_alias("babybop");
  set_short("Baby Bop");
  set_long("A very annoying green creature wearing ballet slippers.\n");
  set_race("dinosaur");
  set_level(15);
  set_al(1000);
  set_aggressive(0);
  return 1;
}


