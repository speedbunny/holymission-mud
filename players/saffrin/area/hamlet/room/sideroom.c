inherit "room/room";
#include "/players/saffrin/defs.h"

object human;

reset(arg){
  
  if(arg)return;

     set_light(1);

     short_desc = "A sideroom of the throne room";

     long_desc =
	"You are in a side room off of the main throne.  This room was designed "+
         	"for the king's secret late night meeting and has become Hamlet's place "+
          	"of brooding.  The room is decorated in dark, rich greens, reds, purples, and blue."+
        	"  There is a large couch along the south wall.  A rather large desk looms at the"+
          	" center of the room.\n";
          
     dest_dir=({
	HAM+"room/throne15", "northeast",
     });

     items=({
          	"couch", "A green couch with an oak frame",
            "desk", "A large oak desk",
     });

     MOVE(CLONE(HAM+"npc/hamlet"),TO);
}

