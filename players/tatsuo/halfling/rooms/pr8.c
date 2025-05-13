inherit "room/room";
#include "/players/tatsuo/def.h"

void reset(int arg){

if(!present("fisherman")){
MO(CO(HMON+"fisherman"),TO);
MO(CO(HMON+"fisherman"),TO);
MO(CO(HMON+"fisherman"),TO);
}

if(arg) return;
  ::reset(arg);
  set_light(1);

  long_desc = "The view of the river and its valley is amazing.  Several small piers "+
              "jut out into the water every now and then.  Apparantly they are used "+
              "by local halfling fisherman"+
              ".\n";

  short_desc= "Along the Shayla river";

  dest_dir = ({ HPATH+"pr7","north", HPATH+"pr9","south" });

  items = ({ "path","go die okay, i told you i hate descriptions",
             "rocks","Okay, maybe they aren't that interesting",
             ({"something","something small"}), "Now is not one of those times",
             "hill","It is covered with vegetation",
             "piers","They look well made, for fishing, which is not what you are doing",
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

