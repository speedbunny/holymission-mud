#include "std.h"
#undef EXTRA_LONG
#define EXTRA_LONG if (id(str)) return extra_long(str);

FOUR_EXIT ("players/cashimor/rooms/rockpath","west",
           "players/cashimor/rooms/cave","north",
           "players/cashimor/rooms/giant","up",
           "players/cashimor/rooms/village","south",
           "The mountains",
           "These are the dangerous mountains of the north. There is a\n"
         + "slippery rock path leading to the west and an entrance to\n"
         + "a cave to the north. To the south you can see a village in\n"
         + "the distance. To the east you see a high mountain looming\n"
         + "up. It feels as if climbing it could be very dangerous...\n",1)

id(str) { return str == "mountain"; }

extra_long() {
  write ("It seems as if some man made structure is on top of it.\n"
       + "And it seems as if this structure is guarded by a very\n"
       + "dangerous monster...\n");
}
