inherit "room/room";
#include "/players/jake/defs.h"
reset (arg) {
if (arg) return;
set_light(2);
short_desc = "Second entry-way";
long_desc =
    "The main castle hall.  This is where most of the castle's traffic is.\n"
  + "A large candle light chandolier hangs from the ceiling.\n"
  + "There is a stone staircase against the eastern wall.  You\n"
  + "wonder where it leads.\n";
items = ({
"floor","Ruby-red stones make up the floor",
"ceiling","It is made of pearl-white stones",
"chandolier","It is made of crystal and has 50 lit candles in it",
"candles","White candles",
"wall","Grey stone walls",
});
dest_dir = ({
"players/jake/goblin/castle/enter","south",
"players/jake/goblin/castle/j1","west",
"players/jake/goblin/castle/h2","north",
KI + "k1","up",
});
}
