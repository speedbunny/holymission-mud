#include "/players/ambrose/room.h"
#include "/players/ambrose/defs.h"

void reset(int arg)
 {
  ::reset(arg);
    if(arg)
       return;
      set_light(1);
      short_desc="A path down the cliff";
      long_desc=
       "The path goes down even more closer to the valley floor, the closer\n"
      +"you get to the valley floor the more the path widens making you feel\n"
      +"safer.  The hard rock around you is starting to give away to greenery\n"
      +"and you see that you are almost on the valley floor.\n";
      property=({"no_teleport"});
      dest_dir=({
                AVAL +"entrance/cliff2","west",
                AVAL +"forest/forest1","down",
      });
      items=({
      "greenery","Lush greenery is draped on the rocks on the cliff",
      "path","Its wider here making you feel more safe.",
      "valley","You are almost in the valley now.",
      "floor","You are nearing the valley floor.",

           });
       smell="You smell the scent of pine trees.";
     }
  void init()
  {
   ::init();
    add_action("no_way_out","",1);
 }






