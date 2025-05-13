inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("rabbit");
  set_alt_name("animal");
  set_short("A small rabbit");
  set_long("A small, furry rabbit. It looks kind of peaceful.\n");
  set_level(2);
  set_size(1);
  set_al(0);
  set_aggressive(0);
  set_race("mammal");
}

