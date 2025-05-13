#include "/players/redsexy/guild/guilddefs.h"

inherit "/players/redsexy/guild/rooms/store";
object staff, dagger, darts, scythe, bracers, gloves, sandals;

reset(arg) {
  ::reset(arg);
  long_desc = "Everything from the Main Shop is stored here.\n";
  if(arg) return;
}

init() {
  ::init();
  add_action("east", "east");
}

inventory(arg) {
  standard();
  ::inventory(arg);
}

buy(arg) {
  standard();
  ::buy(arg);
}

standard() {
  if(!present("black staff", TO)) {
    staff = clone_object(PATH + "weapons/blackstaff");
    MOVE(staff, TO);
  }
  if(!present("black dagger", TO)) {
    dagger = clone_object(PATH + "weapons/blackdagger");
    MOVE(dagger, TO);
  }
  if(!present("darts", TO)) {
    darts = clone_object(PATH + "weapons/darts");
    MOVE(darts, TO);
  }
  if(!present("scythe", TO)) {
    scythe = clone_object(PATH + "weapons/scythe");
    MOVE(scythe, TO);
  }
  if(!present("bracers", TO)) {
    bracers = clone_object(PATH + "armor/bracers");
    MOVE(bracers, TO);
  }
  if(!present("gloves", TO)) {
    gloves = clone_object(PATH + "armor/blackgloves");
    MOVE(gloves, TO);
  }
  if(!present("sandals", TO)) {
    sandals = clone_object(PATH + "armor/sandals");
    MOVE(sandals, TO);
  }
  return 1;
}

east(arg) {
  if(!arg) {
    write("You exit the shop.\n");
    TP->MOVEP("out of the store#" + PATH + "rooms/armshop");
    return 1;
  }
}
