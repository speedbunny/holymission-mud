#include "/players/ambrose/room.h"
#include "/players/ambrose/defs.h"

void reset(int arg)
 {
  ::reset(arg);
    if(arg)
       return;
      set_light(1);
      short_desc="A formless room";
      long_desc="This room begs to be made into something special!\n";
      property=({"no_teleport"});
      dest_dir=({
                "/players/ambrose/avalon/entrance/entran1","down",
      });
      items=({
      "room","You need to make it into something!",

           });
       smell="Does'nt smell like anything.";
     }
  void init()
  {
   ::init();
    add_action("no_way_out","",1);
 }






