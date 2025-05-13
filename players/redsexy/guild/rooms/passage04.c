inherit "/room/room";

#include "/players/redsexy/guild/guilddefs.h"

reset(arg) {
  if(arg) return;
  set_light(0);
  short_desc = "Dead End";
  long_desc =
    "    This is a dead end in the mountain passage. To the south is\n" +
    "the way out.\n";

  dest_dir = ({
    "players/redsexy/guild/rooms/passage03", "south",
  });

  items = ({
    "passage", "A dark passage deep within the mountain",
  });
}

init() {
  ::init();
  add_action("search", "search");
} 

search(arg) {
  if(!arg || arg == "passage") {
    write("You search the walls and the floor and find nothing.\n");
    write("Then you look up and notice a cleverly-hidden opening\n");
    write("set into the ceiling!\n");
    say(TP->NAME + " finds an opening in the ceiling!\n");
    add_action("enter", "enter");
    add_action("up", "up");
    add_action("my_look", "look");
    return 1;
  }
}

enter(arg) {
  if(arg == "opening" || arg == "passage") {
    write("You enter the opening.\n");
    TP->MOVEP("through the opening#" + "players/redsexy/guild/rooms/circle");
    return 1;
  }
  write("Enter what?\n");
  return 1;
}

up(arg) {
  if(!arg) {
    enter("opening");
    return 1;
  }
}

my_look(arg) {
  if(arg == "at opening") {
    write("A cleverly-hidden opening in the ceiling of the passage.\n");
    return 1;
  }
}
