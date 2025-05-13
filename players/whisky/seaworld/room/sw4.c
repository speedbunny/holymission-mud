
#include "../seaworld.h"

void reset(int arg) 
{
  ::reset(arg);

  if (filter_live(this_object()) < 2)
      CM("cuttle_fish");

  if (arg) return;

  set_light(1);
  short_desc = "In the sea";
  long_desc = BS(
     "You have entered one of the eastern parts of the sea. " +
     "The water is warm and there are some stones lying at the " +
     "bottom. The sun is shining through the water and you can " +
     "see big rocks to the west and south.");

items = ({ "stone","You see big heavy stone lying on the bottom", 
          "bottom","You see a sandy see bottom with some stones lying around",
          "rock","You see a big black rock"});

dest_dir =
       ({
      PATH+"sw8", "east",
      PATH+"sw3", "north",});
}

init() {
  ::init();
    add_action("get","get");
    }

int get(string str) 
{
  if (str!="stone") return 0;
   write("The stone is too heavy for you.\n");
   say(this_player()->query_name()+" tries to take a stone but fails.\n");
  return 1;
 }
