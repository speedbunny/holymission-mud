inherit "/room/room";
#include "/players/wilbie/def.h"

  object monst;

   reset(arg){
   if(!arg){

   set_light(1);

   short_desc="In the dungeon";
   long_desc=
    "The cold walls of the dungeon are splattered heavily with blood here, "+
    "which seems to be rather fresh.  On the southern wall a skeleton "+
    "hangs from a hook imbedded through the back of it's skull.\n";

  items=({
  "walls","They are damp granite",
  "dungeon","It is a cold, dark, dismal dungeon",
  "blood","Very fresh blood",
  "skeleton","It has been here for a very long time",
  "southern wall","There is a skeleton hanging on it by a hook",
  "back","There is a hole in the back of the skull",
  "walls","They are covered with both old and new blood",
  "skull","It has been punctured by the hook",
  "hook","It is firmly attached to the wall",
  });
  smell="You smell death.";
   dest_dir=({
   GPATH+"hell1","north",
   GPATH+"hell3","east",
   });
}
::reset(arg); replace_program("/room/room");
}
