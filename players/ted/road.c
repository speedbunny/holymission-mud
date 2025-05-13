#include "std.h"

id(str) {
 return str == "road" || str == "alley" || str == "dark alley";
}

query_value() { return 0; }

long(str) {
 if(str == "road" || str == "alley" || str == "dark alley") {
  write("This is a dark alley leading west between some old\n");
  write("boarded up shacks and run down houses.\n");
  }
 return 1;
}

short() { return "A dark alley leads west"; }

init() {
 add_action("enter"); add_verb("west");
}

enter(str) {
  call_other(this_player(),"move_player","west#players/ted/thief/alley2");
  return 1;
}

get() { return 0; }
