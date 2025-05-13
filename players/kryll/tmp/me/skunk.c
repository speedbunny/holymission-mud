inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("skunk");
  set_alt_name("animal");
  set_short("A small skunk");
  set_long("A small, furry skunk. It looks harmless and peaceful.\n");
  set_level(2);
  set_al(0);
  set_size(1);
  set_aggressive(0);
  set_race("mammal");
}

