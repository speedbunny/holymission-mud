

inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village entry";
   long_desc =
     "You have entered the village.\n"+
     "The house to the north looks small, but that view might be deceiving. \n"+
     "The smell of freshly baked bread is strong, \n"+
     "and it comes from a small house to the northwest of you.\n";

   dest_dir = ({
      "players/dice/rooms/path4","west",
      "players/dice/rooms/vill2","east",
      "players/dice/rooms/house1","north"
       });
   items =({
           "house","Which house, there are two ???",
           "north house","It looks like a small bakery",
           "village","A small coalminer village",
           "north-west house","It looks like a normal house",
           "house 1","It looks like a small bakery",
           "house 2","It looks like a normal house",
           "northwestern house","It looks like a normal house",
           });


   smell = "The smell of fresh bread is strong here, "+
           "and it comes from the north-west.\n";
}
