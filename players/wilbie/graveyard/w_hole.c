inherit "/room/room";
#include "/players/wilbie/def.h"

reset (arg){
if (!arg){

   set_light(1);
   short_desc="A passage down";
   long_desc=
   "There is a large hole here with a steel ladder leading down into it. "+
   "Blood and gore cover the walls, and shattered bones lie strewn about. "+
   "A large pentagram and various symbols of evil have been drawn with "+
   "the blood... "+
   "Down the hole it looks very, very dark.  You notice that the ladder "+
   "does not reach all the way down, so it's possible that you will not "+
   "be able to come back up this way.  Demonic laughter emanates from "+
   "the hole.\n";

   items=({
   "blood","It looks fairly fresh",
   "gore","It makes you feel a little sick",
   "pentagram","An ancient symbol made up of a star in a circle",
   "bones","They have been shattered by a powerful force",
   "symbols","They are completely unknown to you",
   "hole","It is really dark down there",
   "ladder","It looks sturdy enough",
   "walls","They are covered in blood and gore",
   });

  clone_list=({
 1,24,"bone","/players/wilbie/graveyard/obj/tbone",0,
  });
  ::reset();
    dest_dir=({
   GPATH+"pit1","down",
   GPATH+"w_pass6","south",
   });

   }
replace_program("/room/room");
   }
