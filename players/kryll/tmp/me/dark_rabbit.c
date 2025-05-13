inherit "/obj/monster";

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("rabbit");
  set_alt_name("animal");
  set_short("A small rabbit");
  set_long(
    "A small, furry rabbit. It has menacing red eyes and "+
    "unusually long teeth. Perhaps it has been tainted by evil.\n"
  );
  set_level(5);
  set_wc(4);
  set_size(1);
  set_al(-100);
  set_move_at_reset();
  set_aggressive(1);
  set_race("mammal");
}

