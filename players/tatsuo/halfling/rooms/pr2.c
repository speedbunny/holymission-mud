inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){


if(arg) return;

  ::reset(arg);
  set_light(1);

  long_desc = "The swift current flows past you to the west, as you travel along "+
              "the river path.\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr1","north", HPATH+"pr3","south" });

  items = ({ "path","go die okay, i told you i hate descriptions",
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

