   inherit"/room/room";
#include "/players/wilbie/def.h"
   reset(arg){
   if(!arg){
   set_light(0);
   short_desc="In a narrow passage";
   long_desc=
   "You are in a dark hallway.  The walls seem to be made of a strange "+
   "metal, rusted from centuries of damp air.  To the west, you hear loud "+
  "chanting that overpowers all other sound.  And it seems to be right "+
  "in the room west of you!!\n";

  items=({
  "hallway","A long hallway of iron",
  "metal","Rusty iron",
  "room","The hallway leads to a room to your west",
  "light","It comes from the west",
  "air","You stare at the air until your eyeballs dry out",
  "walls","They are iron walls",
  "floor","The floor is iron",
  "iron","Old rusted iron",
  "west","There seems to be some light to the west",
  });

  clone_list=({
  1,1,"fanatic","/players/wilbie/graveyard/monsters/fanatic",0,
  1,5,"apprentice","/players/wilbie/graveyard/monsters/apprent",0,
 -1,1,"armour","/players/wilbie/graveyard/armor/armor3",0,
 -1,1,"hammer","/players/wilbie/graveyard/weapons/hammer",0,
  });
  ::reset();

   dest_dir=({
   GPATH+"med-room","west",

   GPATH+"longhall8","east",
   });
  }
::reset(arg); replace_program("/room/room");
 }
