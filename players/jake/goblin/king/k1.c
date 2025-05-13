inherit "room/room";
#include "/players/jake/defs.h"
reset(arg) {
 if(arg) return;
 set_light(1);
 short_desc = "The kings entrance room";
 long_desc = "You stand in a large, elegantly decorated room.  Plush carpet lines\n" +
             "the floor, and comfortable looking chairs stand around a large table\n" +
             "that stands in the center of the room.  Beautifully framed portraits of what appear to be ancestors of the king line the stone walls.\n" +
             "A large domed ceiling with large windows cut into it, lights up the room.\n" +
             "Doorways exit the room to the north and west, and a staircase leads down\n" +
             "into the castle.\n";
 items = ({
  "portraits","They appear to be portraits of the kings father, grandfather, etc.",
  "carpet","Plush red carpet that squishes when you walk on it",
  "table","A large, cherry table",
  "chairs","Comfortable chairs made from cherry wood",
  "chair","A comfortable chair made from cherry wood",
});
 DD = ({
  KI + "k3","west",
  KI + "k2","north",
  CAS + "h1","down",
});
}
