inherit "/players/sauron/inherit/virtual_master";

#include "/players/sauron/include/virtual.h"

void reset(int arg) {
  if(!arg) {
    set_area_size(4,4,4);
    set_map_key("x","/players/sauron/area/virtual/test_room2");
    set_map(0,"\
xxxx\
xxxx\
xxxx\
xxxx\
");
    set_map(1,"\
xxxx\
xxxx\
xxxx\
xxxx\
");
    set_map(2,"\
xxxx\
xxxx\
xxxx\
xxxx\
");
    set_map(3,"\
xxxx\
xxxx\
xxxx\
xxxx\
");
    set_border_room(({ 3,3,0}),"south",
                    "/players/sauron/area/virtual/test_master,0,0,0");
  }
// Important! This must come last.
  ::reset(arg);
}
