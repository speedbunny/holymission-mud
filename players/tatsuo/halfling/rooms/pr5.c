inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){

   if(!present("deer")){ MO(CO(HMON+"deer"),TO); 
                         MO(CO(HMON+"deer"),TO); 
                         MO(CO(HMON+"deer"),TO); 
                         MO(CO(HMON+"deer"),TO); }
if(arg) return;
  ::reset(arg);
  set_light(1);

  long_desc = "The river flows through a narrow valley here.  The path you follow "+
              "now lies on the side of a hill"+

              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr4","north", HPATH+"pr6","south" });

  items = ({ "path","go die okay, i told you i hate descriptions",
             "rocks","Okay, maybe they aren't that interesting",
             ({"something","something small"}), "Now is not one of those times",
             "hill","It is covered with vegetation",
             "underbrush","It is green",
             "forest","It is dark and dismal",
             "river","It is wet",
             "current","You get dizzy and fall down",
             "river path","Shouldn't you be killing something you putz",
             "incline","go die, i hate descriptions",
             "valley","A depression in the ground, like the kind Wilbie makes "+
                      "when he hits the ground at full force from a Tatsuo throw!",
              });

replace_program("room/room");

}
/*filler room to extend mud far to the south*/

