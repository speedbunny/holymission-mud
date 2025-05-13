inherit "/room/room";
#include "/players/wilbie/def.h"

  reset(arg){
  if(!arg){

  set_light(0);


   short_desc="In the dungeon";
   long_desc=
   "The passage seems to widen here a bit, and large piles of bones on all "+
   "sides seem to suggest that this is a storage room for the dead.  The air "+
   "seems a bit warmer here for some reason.\n";

    items=({
    "creatures","They look a lot like demons!!",
    "passage","It gets a little wider here",
    "piles","They seem to hold a lot of old bones",
    "bones","Some of them look new",
    "room","It is a grotesque room",
    "air","You see a vision of yourself standing in a darkened pit, trying "+
          "desparately to look at something that can't be seen.  You feel "+
          "really silly",
    });

    dest_dir=({
    GPATH+"hell2","west",
    GPATH+"hell4","south",
    });


  clone_list=({
  1,1,"merillith","/players/wilbie/graveyard/monsters/merillith",0
  });
  ::reset();
}
::reset(arg); replace_program("/room/room");
}
