#include "/players/redsexy/guild/guilddefs.h"

inherit "/players/redsexy/guild/rooms/store";

object watch;

reset(arg) {
  ::reset(arg);
  long_desc = "Everything from the Main Shop is stored here.\n";
  if(arg) return;
}

init() {
  ::init();
  add_action("north", "north");
}

inventory(arg) {
 // removed from game standard();
  ::inventory(arg);
}

buy(arg) {
  standard();
  ::buy(arg);
}

standard() {
  if(!present("small watch", TO)) {
    watch = clone_object("/players/redsexy/objects/watch");
    MOVE(watch, TO);
  }
  return 1;
}

north(arg) {
  if(!arg) {
    write("You exit the store.\n");
    TP->MOVEP("out of the store#" + PATH + "rooms/magicshop");
    return 1;
  }
}
