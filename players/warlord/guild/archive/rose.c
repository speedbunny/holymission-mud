inherit "/obj/treasure";

reset(arg) {
  if (arg) return 1;
  set_id("rose");
set_short("Black rose");
  set_long("This rose shows undying devotion to the holder.....\n");
  set_weight(0);
  set_info("rose (created by The Wacky and Zany Warlord using Uranus' Wand)");
  return 1;
}

query_objmaker() { return 1; }
