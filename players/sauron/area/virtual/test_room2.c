inherit "/players/sauron/inherit/virtual_room";

#include "/players/sauron/include/virtual.h"

string variable_long() {
  string ret;
  int *coords;

  coords=query_virtual_coords();
  return "This is a virtual room at coordinates "
         +encode_coords(coords)+".\n";
}

void reset(int arg) {
  if(!arg) {
    set_light(1);
    short_desc="A virtual room.";
    long_desc="@@variable_long@@";
  }
  ::reset(arg);
}
