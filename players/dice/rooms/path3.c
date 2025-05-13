
inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Path";
   long_desc =
     "You are nearly in the village.\n"+
     "The woods are almost gone here, and the roofs of the village\n"+
     "seem to be coming closer and closer.\n"+
     "The smell of freshly baked bread becomes stronger and stronger.\n";

   dest_dir = ({
      "players/dice/rooms/path2","west",
      "players/dice/rooms/path4","east"
       });

   items =({
            "roofs","The roofs from the houses",
            "roof","The roof on a house",
            "woods","The last woods surrounding you",
            "house","A coalminer house",
            "houses","Coalminer houses",
            "wood","The last wood surrounding you",
            "chimney","A smoking chimney",
             "village","A small coalminers village",
            "chimneys","Smoking chimneys"
           });


   smell = "You smell the fresh bread coming from the houses \n"+
           "This smell really makes you hungry.\n";
}
