#include "std.h"
#undef EXTRA_LONG
#define EXTRA_LONG if (id(str)) return extra_long(str);
TWO_EXIT ("players/cashimor/rooms/shackles","west",
          "players/cashimor/rooms/mountains","east",
          "The rockpath",
          "You're on a slippery path made of rocks leading from a big\n"
        + "stone to the shore. You can barely keep your balance.\n",1)

id(str) { return str == "path"; }

extra_long() {
  write ("The path is covered with snow. It's very cold here!\n");
}
