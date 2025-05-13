#include "std.h"

id(str) {
 return str == "stair" || str == "stairs" || str == "staircase";
}

query_value() { return 0; }

long(str) {
 if(str == "stair" || str == "stairs" || str == "staircase") {
  write("This is a wooden staircase leading up.\n");
  }
 return 1;
}

short() { return "A staircase leading up"; }

init() {
 add_action("enter"); add_verb("up");
}

enter(str) {
  call_other(this_player(),"move_player","up#players/ted/party/party_booth");
  return 1;
}

get() { return 0; }
