inherit "/players/sauron/inherit/virtual_master";

#include "/players/sauron/include/virtual.h"

void reset(int arg) {
  if(!arg) {
    set_area_size(20,20,1);
    set_map_key("x","/players/sauron/area/virtual/test_room");
    set_map(0,"\
xxx x  xx xxx  xxx x\
 x x xx  xx  xx   x \
x x x xxx  x x x    \
 xx xx   xx x x x xx\
x xx  x x  x x  xx  \
    x  x    x       \
  xx  x   xx x  xx  \
 x    x  x x  x   x \
x xx x  x  x x xxx x\
x   x  x   x x     x\
x  xx  x  x   x    x\
 xxxx      x        \
  xxx    xx x  xx   \
 x x    x   x x  x  \
x   x  x  xxxx    x \
x   x    x  x      x\
 xx    xx  x xxx    \
 x xxx  x      xxx  \
x xx     x  xxx x   \
x   x    x   x   x  \
");
    set_border_room(({ 0,0,0}),"up",
                    "/players/sauron/area/virtual/entrance");
    set_border_room(({19,0,0}),"up",
                    "/players/tuppence/workroom");
    set_border_room(({19,9,0}),"up",
                    "/players/nae/workroom");
    set_border_room(({ 0,0,0}),"north",
                    "/players/sauron/area/virtual/test_master2,3,3,0");
  }
// Important! This must come last.
  ::reset(arg);
}
