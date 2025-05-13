inherit "/obj/treasure";

#include "/players/topaz/defs.h"

reset(arg) {
  ::reset();

    set_id("scroll of recall");
    set_name("scroll");
    set_alt_name("recall");
    set_alias("recall scroll");
    set_short("Scroll of recall");
    set_long("With this scroll you can be transported from many\n" +
             "places on the mud back to the church.\n" +
             "To use the scroll, just type 'recall' and\n" +
             "Magnacious will come to your aid if possible.\n");
               
    set_value(20);
    set_weight(1);
}

init() {
  ::init();

    add_action("_recall","recall");
}

_recall() {

  if(TP->query_immortal()) {
    write("You are transported to the church.\n");
    TP->move_player("X","/room/church");
    return 1;
  }
  if(TP->query_ghost()) {
    write("You cannot use the scroll as a ghost.\n");
    return 1;
  }
  if(environment(TP)->query_property("no_teleport")) {
    write("Nothing happens as you read the scroll.\n" +
          "Magnacious must be forbidden to enter this area.\n");
    return 1;
  }
  if(TP->query_sp() < 100) {
    write("You don't have enough spellpoints to use the scroll.\n" +
          "It costs 100 spellpoints.\n");
    return 1;
  }
  else {
    write("Magnacious appears and transports you to the church.\n");
    say("An old man appears and touches " + TP->query_name() + ".\n" +
        "The old man and " + TP->query_name() + " just vanish!\n");
    TP->move_player("X","/room/church");
    TP->restore_spell_points(-100);
    destruct(this_object());
    return 1;
  }
}
