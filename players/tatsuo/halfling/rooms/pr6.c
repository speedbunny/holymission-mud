inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){


if(arg) return;
  ::reset(arg);
  set_light(1);

  long_desc = "The path continues throught the valley from north to south"+
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr5","north", HPATH+"pr7","south" });

  items = ({ "path","go die okay, i told you i hate descriptions",
             "valley","A depression in the ground, like the kind Wilbie makes "+
                      "when he hits the ground at full force from a Tatsuo throw!",
              });

replace_program("room/room");

}
/*filler room to extend mud far to the south*/

