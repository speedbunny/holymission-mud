#include "../seaworld.no_water.h"
inherit "room/room";

object *rudi;
reset(arg) {
  ::reset(arg);

if (arg) return;
    if (!rudi)
 {
   rudi = clone_object("/players/whisky/seaworld/monster/rudi");
   move_object(rudi,this_object());
  }
set_light(1);
short_desc = "On a stony path";
long_desc = 
  "You are now walking on a stony path. To the south you can\n"+
  "see the big fence bordering a beautiful garden and to the\n"+
  "north you can see a dark forest.\n";
  dest_dir = ({
    "/players/whisky/meadow/room/m1","north",
    "/players/whisky/seaworld/room/sea_way2","east",
    "/players/whisky/garden/room/path2","west" });
items = ({
    "forest","You see a lot of big spruces",
    "stonewall","Maybe the way to the sea but now unpossible to pass",
    "fence","You see a big brown garden fence",
    "bottom","You see a stony bottom"});
}
   
