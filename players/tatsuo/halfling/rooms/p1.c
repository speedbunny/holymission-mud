inherit "room/room";
#include "/players/tatsuo/def.h"


void reset(int arg)

  if(arg) return;
   if(!present("halfling")){ MO(CO(HMON+"halfling"),TO); } 
  ::reset(arg);

  long_desc = "You find yourself moseying down a quaint little path "+
              "on the east side of the stream.  Very little vegetation "+
              "stands out on this side of the water, although a rather "+
              "large bush does stand out on the other side of the "+
              "stream.  The path continues south, while a humpback "+
              "bridge lies just to the north.\n";

  short_desc = "On the path to the Halfling village";
 
  set_light(1);
  
  dest_dir = ({ HPATH+"p2","south", "/room/hump","north" });

  items = ({ "path","It runs north and south",
             "vegetation","What the fuck are you a rabbit, go down the "+
             "damn path",
             "bush","To get a better look at it, head north, and cross\n"+
                    "the bridge to the west side of the stream",
             ({"bridge","humpback bridge"}), "It is made of stone and "+
              "is usually cluttered with sticks" });
   replace_program("room/room");
}


