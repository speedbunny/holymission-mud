#include "/players/tamina/defs.h"
inherit "room/room";

reset(arg){

     set_light(1);
     short_desc = "Courtyard of Camelot";
     long_desc = 
   "This is the courtyard of the deserted castle.  It doesn't look as\n"+ 
   "though the menials have been here in quite a while, since there\n"+
   "are weeds sprouting out all over the place, and tumble-weeds flying\n"+ 
   "aimlessly around the bare space.  You can see a set of stocks lying\n"+ 
   "to one side of the yard.  To your right, you can see a small tower,\n"+ 
   "with a dark corridor running into the distance.  To your left, you\n"+ 
   "can see another dark corridor that spans the length of the castle walls.\n";

     dest_dir = ({
   CROOMS + "entrance","south",
   CROOMS + "wcourt1","west",
   CROOMS + "ecourt1","east",
   CROOMS + "court2","north",
     });

     items = ({
   "stocks", 
"A rotten pile of wood now, covered in grime and mould as a "+ 
"result of disuse",
   "weeds", 
"Ugly looking plants that you don't like the look of",
   "tower", 
"This seems to be a simple functional tower, with only one "+
"floor",
   "corridor", 
"You can't see very much in the corridor because of the "+
"distinct lack of light",
     });

    ::reset (arg);

    RPR("room/room");

}
