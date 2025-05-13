inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("deer");
  set_alt_name("animal");
  set_short("A small deer");
  set_long("A small, nervous deer. It looks kind of peaceful and wary.\n");
  set_level(5);
  set_size(2);
  set_al(0);
  set_aggressive(0);
  set_race("mammal");
}

