#include "/players/tamina/defs.h"
inherit "room/room";

reset(arg){
   if(arg) return;

     set_light(-1);
     short_desc = "East Corridor ";
     long_desc = 
   "As you proceed along this very dark corridor, you are thankful for the\n"+ 
   "light-sources that you remembered to bring.  A cold breeze whistles\n"+
   "through the empty passage, making your torch flicker dangerously\n"+ 
   "and casting strange silhouettes against the walls.  Far ahead of you,\n"+
   "you can see the entrance to the largest of the towers of Arthur's\n"+
   "Castle.  To the east, another passage branches off into the East Wing.\n";

     dest_dir = ({
   CROOMS + "ecorridor1","north",
   CROOMS + "ewing1","south",
   CROOMS + "ewing2","east",
     });

     items = ({
  "corridor",
"You can't see very much in the corridor because of the "+
"distinct lack of light",
  "walls",
"Across the stones are weird looking shapes made out of shadow, "+ 
"that almost seem alive in the gloom...",    
      });

}

