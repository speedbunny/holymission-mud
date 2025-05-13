#include "std.h"

#undef EXTRA_LONG
#define EXTRA_LONG if (id(str)) return extra_long(str);
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

THREE_EXIT("/players/cashimor/rooms/ice","west",
           "/players/cashimor/rooms/ice3","north",

         "/players/cashimor/rooms/ice2","east",
         "Wastelands of ice",
         "You are on the wastelands of ice. When you look around you see\n"
       + "ice all around you. This doesn't look too good: it's very cold\n"
       + "here. To the west you see a shimmering void.\n",
         1)

id(str) { return (str == "ice" || str == "void"); }
id3(str) { return str == "ice"; }
id2(str) { return str=="void"; }

extra_long(str) {
  if (id3(str)) {
  write("The ice seems very strong, but it has some irregularities.\n");
  }
  if (id2(str)) {
    write("the void is white and reminds you of home...\n");
  }
}
extra_init() {
  add_action ("west","west");
  add_action ("east","east");
  add_action ("north","north");
}
north () {
  if (!present ("skates",this_player())) {
    write ("It's too slippery!\n");
    return 1;
  }
  this_player()->move_player("skating to the east#players/cashimor/rooms/ice3");
  return 1;
}
east () {
  if (!present ("skates",this_player())) {
    write ("It's too slippery!\n");
    return 1;
  }
  this_player()->move_player("skating to the east#players/cashimor/rooms/ice2");
  return 1;
}

west() {
  if (!present ("skates",this_player())) {
    write ("It's too slippery!\n");
    return 1;
  }
  this_player()->move_player("skating to the west#players/cashimor/rooms/westrink");
  return 1;
}
