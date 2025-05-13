
inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "path";
   long_desc =
     "You are walking on a path leading to a village.\n"+
     "The woods get light here and in the distance you notice\n"+
     "the roofs of the village. Smoke can be seen coming from the \n"+
     "chimneys.\n"+
     "The fresh smell of the forest becomes stronger here.\n";

   dest_dir = ({
      "/players/dice/rooms/path2","east",
       });
   items =({
           "chimneys","A small chimney on top of the roof",
           "path","A path leading east and west",
           "roofs","The roofs of the houses of the coalminers",
           "chimney","A small chimney on top of the roof",
           "wood","Fresh woods surrounding you",
           "woods","Fresh woods surrounding you",
           "dice","THE MIGHTY CREATOR OF THIS AREA",
           "roof","The roof of the house of the coalminers",
           "smoke","The smoke is coming from the chimneys"

           });


   smell = "You smell the fresh woods like a relief to your nose.";
}
