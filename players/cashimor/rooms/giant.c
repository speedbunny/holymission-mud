#include "std.h"
#undef EXTRA_LONG
#define EXTRA_LONG if (id(str)) return extra_long(str);
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

TWO_EXIT ("players/cashimor/rooms/mountains","down",
          "players/cashimor/rooms/tower","north",
          "Tower edge",
          "You are on a yard before a tower. To the north is the entrance\n"
        + "to the tower.\n",1)

id(str) { return str == "tower"; }

extra_long() {
  write ("The tower has an incredible evil feeling about it...\n");
}

object giant;

extra_reset() {
  if (!giant) {
    giant = clone_object("/players/cashimor/monsters/giant");
    move_object(giant,this_object());
  }
}

extra_init() {
  add_action("north","north");
}

north() {
  if (living(giant)) {
    write ("The giant blocks your way into the tower!\n");
    return 1;
  }
  this_player()->move_player("north#players/cashimor/rooms/tower");
}
