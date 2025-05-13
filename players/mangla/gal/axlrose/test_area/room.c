inherit "/players/axlrose/inherit/patrol_room";

#include "/players/sauron/include/virtual.h"

string variable_long() {
  int *coords;

  coords=query_virtual_coords();
  return "This is a virtual room in Axlrose's test area (coordinates "
         +encode_coords(coords)+").\n";
}

void setup_room() {
  int *coords;

  coords=query_virtual_coords();
  if(coords[0]==2 && coords[1]==2 && coords[2]==0) {
    set_patrol_clone_file("/players/axlrose/test_area/patrol");
    set_patrol_size(5);
    set_patrol_walk_chance(5);
    set_patrol_walk_limit("players/axlrose/test_area/room");
    clone_patrol();
  }
}

void reset(int arg) {
  if(!arg) {
    set_light(1);
    short_desc="A room in Axl's test area.";
    long_desc="@@variable_long@@";
  }
  ::reset(arg);
}
