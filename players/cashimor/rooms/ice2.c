#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
#undef EXTRA_LONG
#define EXTRA_LONG if (id(str)) return extra_long(str);
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

ONE_EXIT("/players/cashimor/rooms/ice","west",
         "Wastelands of ice",
         "You are on the wastelands of ice. When you look around you see\n"
       + "ice all around you. This doesn't look too good: it's very cold\n"
       + "here.\n",
         1)

id(str) { return str=="ice"; }

extra_long(str) {
  write("The ice seems very strong, but it has some irregularities.\n");
}

object icebear;

extra_reset() {
  if (!icebear || !living(icebear)) {
     icebear = clone_object("/players/cashimor/monsters/icebear");
    move_object(icebear, this_object());
  }
}
extra_init() {
  add_action ("west","west");
}

west() {
  if (!present ("skates",this_player())) {
    write ("It's too slippery!\n");
    return 1;
  }
  this_player()->move_player("skating to the west#players/cashimor/rooms/ice");
  return 1;
}
