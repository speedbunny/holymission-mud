inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){


if(arg) return;
  reset(arg);
  set_light(1);

  long_desc = "Several very interesting rocks lie along the side of the north "+
              "south running path, but that is the extent of the excitment"+
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr2","north", HPATH+"pr4","south" });

  items = ({ "path","go die okay, i told you i hate descriptions",
             "rocks","Okay, maybe they aren't that interesting",
             "river","It is wet",
             "current","You get dizzy and fall down",
             "river path","Shouldn't you be killing something you putz",
             "incline","go die, i hate descriptions",
             "valley","A depression in the ground, like the kind wilbie makes "+
                      "when he hits the ground at full force from a Tatsuo throw!",
              });

replace_program("room/room");

}
/*filler room to extend mud far to the south*/

