inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("fox");
  set_alt_name("animal");
  set_short("A fox");
  set_long("A fox. It seems to be looking around for some fresh meat.\n");
  set_level(4);
  set_size(1);
  set_al(0);
  set_aggressive(1);
  set_race("mammal");
}

