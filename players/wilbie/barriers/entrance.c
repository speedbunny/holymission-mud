inherit"room/room";
#include "/players/wilbie/def.h"

reset(arg){

   if(!arg){

   set_light(1);

   short_desc="Before the ancient halls";

   long_desc="You stand before a dark and weathered building of ancient "+
            "granite.  Twisting vines cover the stone walls and the ground "+
            "all around, and a dank mist fills the air.  There is an "+
            "oppressive feel to this place, and a sense of dread that seeps "+
            "into your bones.\n";

   items=({"walls","They are ancient granite walls",
           "vines","They are twisted and dead",
           "building","It is a building of ancient granite",
           "place","You are in fromt of an ancient looking building",
           "stone","It appears to be granite",
           "ground","It is the muddy ground of a graveyard",
           "air","You can see a dank looking mist",
           "granite","It is a hard dark rock",
           "mist","It is fog rising off the ground"});


   dest_dir=({ GPATH+"hall1","north",
 
   GPATH+"w_grave1", "south",
           });
   }
  ::reset(arg); replace_program("/room/room");
 }
