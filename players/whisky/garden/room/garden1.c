 
 
inherit "room/room";
#include "../garden.h"
 
void reset(int arg) 
{
  if (filter_live(TO) < 2)
  {
    CM("bee");
    CM("bee");
  }
  if (arg) return;
     set_light(1);
     short_desc = "In a beautiful garden";
     no_castle_flag = 0;
    long_desc =
                "You have entered Chantilly's beautiful garden. " +
                "It's a lovely place where you can imagine to stay " +
                "forever. The sun is shining on your face and you " +
                "immediately feel better. There is a brown garden " +
                "fence to the north and south. The way is open to " +
                "the north and west.\n";
    items = ({ "fence","You see a big brown garden fence",
               "garden fence","You see a big brown garden fence"});
    dest_dir = ({ ROOM+"/garden4", "north",
		  ROOM+"/garden2", "west" });
}

init() 
{
  ::init();
  add_action("climb","climb");
 }

int climb(string str) 
{
  if (str=="fence") {
   write(
    "On this place the fence is much too high, you stumble and fall down.\n");
   say(this_player()->query_name()+
       " tries to climb the fence, but falls down.\n");
  this_player()->hit_player(10);
  return 1;
  }
  return 0;
}

