inherit "/players/sauron/inherit/virtual_master";

#include "/players/sauron/include/virtual.h"

void reset(int arg) {
  if(!arg) {
    set_area_size(4,4,1);
    set_map_key("x","/players/axlrose/test_area/room");
    set_map(0,"\
xxxx\
xxxx\
xxxx\
xxxx\
");
    set_border_room(({3,3,0}),"up","/players/axlrose/test_area/entrance");
  }
// Important! This must come last.
  ::reset(arg);
}
