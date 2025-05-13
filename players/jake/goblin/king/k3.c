inherit "room/room";
#include "/players/jake/defs.h"
reset(arg) {
 if(arg) return;
 set_light(1);
 short_desc = "The kings waiting room";
 long_desc = "You are standing in a small hallway of sorts.  The room is simple,\n" +
   "yet elegant.  A small bench, covered with satin cushions, is the only\n" +
   "furniture in the room.  A large tapestry covers the northern wall, and\n" +
   "a marble doorway is in the southern wall.  Another, larger doorway stands\n" +
   "in the western wall, with a crown painted above it.\n";
 items = ({
   "bench","A small bench with cushions made of stain",
   "cushions","Satin cushions that cover the bench",
   "tapestry","A large tapestry with a picture of a great battle sewn into it",
   "crown","A crown has been painted above the doorway to indicate the room is important",
  });
 DD = ({
   KI + "k1","east",
    KI + "k4","west",
   KI + "k5","south",
  });
}
