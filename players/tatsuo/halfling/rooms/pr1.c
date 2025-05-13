inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){


if(arg) return;
  ::reset(arg);

  set_light(1);

  long_desc = "The small path follows the river to the south for quite a distance. "+
              "The fields of grain to the west are starting to give way to a steeper "+
              "incline rising from the river valley.\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"p12","north", HPATH+"pr2","south" });

  items = ({ "path","go die okay, i told you i hate descriptions",
             "river","It is wet",
             "incline","go die, i hate descriptions",
             "valley","A depression in the ground, like the kind wilbie makes "+
                      "when he hits the ground at full force from a Tatsuo throw!",
              });

replace_program("room/room");

}
/*filler room to extend mud far to the south*/

