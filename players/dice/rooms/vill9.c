
inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are almost in the northern part of the village.\n"+
     "The stench of coal gets a lot heavier here.\n"+
     "Up north you can see a working place where \n"+
     "the coalminers used to work. \n";

   dest_dir = ({
      "players/dice/rooms/vill8","south",
      "players/dice/rooms/vill9a","north",
      "players/dice/rooms/vill10","east"
       });

   items =({
            "path","A path, carefully plaved by some constructors",
             "houses","Small coalminer houses",
             "constructors","They left the place when the path was finished",
            "dust","Coaldust and sand together well mixed",
            "village","Nothing special can be seen here....",
            "working place","A small area which is used to clean the coals",
            "place","A small area which is used to clean the coals"
            });


   smell = "The smell of coals gets stronger and stronger .\n";
}
