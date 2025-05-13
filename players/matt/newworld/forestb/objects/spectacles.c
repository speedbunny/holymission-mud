inherit "/obj/armour";

#include "/players/matt/defs.h"

string reader;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("spectacles");
  set_alias("glasses");
  set_type("spectacles");
  set_short("Spectacles");
  set_long("A small pair of silver-rimmed glasses.\n");
  set_weight(1);
  set_value(500);
}

init() {
  ::init();
  add_action("my_drop", "drop");
}

my_drop(arg) {
  if(id(arg)) {
    write("You drop the spectacles. They crumble to dust.\n");
    say(TP->SNAME + " drops spectacles. They crumble to dust.\n");
    destruct(TO);
    return 1;
  }
}

set_reader(arg) {
  reader = arg;
  return 1;
}

query_reader() { return reader; }
query_quest_item() { return 1; }
query_mage_wear() { return 1; }
query_monk_wear() { return 1; }
query_summoner_wear() { return 1; }
