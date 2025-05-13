inherit "obj/treasure";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset();

    set_id("yo-yo");
    set_name("yo-yo");
    set_alt_name("yoyo");
    set_short("A yo-yo");
    set_long("This yo-yo looks like fun.\n" +
             "To use it, just type, \"yo\"\n");
    set_value(100);
    set_weight(1);
}

init() {
  ::init();
    add_action("_yo","yo");
}

_yo(str) {
  if(!str) {
    switch(random(4)) {
      case 0:
        write("You perform a \"Walk the Dog\" with the yo-yo.\n");
        say(TP->query_name() + " performs a \Walk the Dog\" with a yo-yo.\n");
        break;
      case 1:
        write("You perform an \"Around the World\" with the yo-yo.\n");
        say(TP->query_name() + " performs an \"Around the World\" with a yo-yo.\n");
        break;
      case 2:
        write("You perform a \"Cradle\" with the yo-yo.\n");
        say(TP->query_name() + " performs a \"Cradle\" with a yo-yo.\n");
        break;
      case 3:
        write("You perform a \"Sleeper\" with the yo-yo.\n");
        say(TP->query_name() + " performs a \"Sleeper\" with a yo-yo.");
        break;
    }
  }
  else {
    write("Just type, \"yo\"\n");
  }
  return 1;
}
