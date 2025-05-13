inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){


if(arg) return;
  ::reset(arg):

  set_light(1);

  long_desc = "Peering eastward across the river, you can see a rather dismal "+
              "and dark looking forest.  From time to time you catch a glimpse "+
              "of something small moving around in the underbrush over there"+
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr3","north", HPATH+"pr5","south" });

  items = ({ "path","go die okay, i told you i hate descriptions",
             "rocks","Okay, maybe they aren't that interesting",
             ({"something","something small"}), "Now is not one of those times",
             "underbrush","It is green",
             "forest","It is dark and dismal",
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

