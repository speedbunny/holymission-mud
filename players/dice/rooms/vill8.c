
inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are walking towards the northern part of the village.\n"+
     "The stench of coal gets a bit heavier here.\n"+
     "Further north you can see a working place where \n"+
     "the coalminers work. \n";

   dest_dir = ({
      "players/dice/rooms/vill6","south",
      "players/dice/rooms/vill9","north"
       });

   items =({
            "path","A path, carefully plaved by some constructors",
            "houses","Small coalminers houses",
            "constructors","They left after they finished the path",
            "dust","Coaldust and sand together well mixed",
            "village","Nothing special can be seen here....",
            "working place","A small area which is used to clean the coals",
            "place","A small area which is used to clean the coals"
            });


   smell = "The smell of coals gets stronger here.\n";
}
