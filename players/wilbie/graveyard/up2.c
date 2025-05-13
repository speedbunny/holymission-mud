   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You are in a long hallway of white marble.  This place is very different "+
   "from the black granite of the lower floor of the cathedral.  You almost "+
  "feel at ease... Almost.\n";

  items=({
  "hallway","It is made of finely polished white marble",
  "floor","It is rather clean for such an old place",
  "cathedral","All you can see of the cathedral is this little hallway "+
              "right now",
  "place","The place is a hallway of white marble",
  "granite","You remember seeing some granite downstairs",
  "marble","It is white, and polished well",
  });
   dest_dir=({
   "/players/wilbie/barriers/up1","east",
   GPATH+"up3","west",
   });

  clone_list=({
  1,1,"apprentice","/players/wilbie/graveyard/monsters/apprent",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/armor1",0,
  });
  ::reset();
  }
::reset(arg); replace_program("/room/room");
 }
