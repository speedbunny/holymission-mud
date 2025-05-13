

#include "/players/ambrose/room.h"
#include "/players/ambrose/defs.h"

void reset(int arg)
 {
  ::reset(arg);
    if(arg)
       return;
      set_light(1);
      short_desc="The top of a cliff";
      long_desc=
      "You are standing on the top of a cliff overlooking a huge valley. \n"
     +"Below you in the valley you can see a gleaming white city in the \n"
     +"distance with a lush green forest surrounding it.  On the far side of\n"
     +"the valley you see a smoking chasm, almost like a wound in the land.\n"
     +"The path before you wanders slowly downward toward the forest and you\n"
     +"see a road leading to the city.\n";
     property=({"no_teleport"});
      dest_dir=({
        AVAL +"entrance/cavern","west",
        AVAL +"entrance/cliff2","down",
      });
      items=({
      "chasm","A gaping wound in the land you get a evil feeling",
      "city","You can't make details except for the large tower in the center",
      "forest","Lush and green it is the very picture of the word fertile",
      "path","It wanders downward the cliffside to the valley floor below",

           });
       smell="You can smell the lush forest below.";
     }
  void init()
  {
   ::init();
    add_action("no_way_out","",1);
 }






