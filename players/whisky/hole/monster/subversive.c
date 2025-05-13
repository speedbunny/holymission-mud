inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
 if (arg) return 1;
  set_name("subversive");
  set_alias("mouse");
  set_short("A subversive");
  set_long("A hard-working mouse looking for earthworms.\n");
  set_race("animal");
  set_level(2);
  set_size(1);
  set_al(100);
  set_whimpy();
 return 1;
}
