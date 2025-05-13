inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("raccoon");
  set_alt_name("animal");
  set_short("A small raccoon");
  set_long("A small, anxious raccoon. It looks kind of peaceful.\n");
  set_level(2);
  set_size(1);
  set_al(0);
  set_agressive(0);
  set_race("mammal");
}

