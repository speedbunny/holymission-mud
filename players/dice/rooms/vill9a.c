
inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Working place";
   long_desc =
     "This is a totally deserted working place of the coalminers.\n"+
     "Here the coalminers used to clean the coals that were\n"+
     "dug up in the mines.\n"+
     "But as the mines grew empty the coalminers lost their jobs\n"+
     "and they left the place here after cleaning it up.\n";

   dest_dir = ({
      "players/dice/rooms/vill9","south",
      "players/dice/rooms/vill12","north"
       });

   items =({
            "path","A path, carefully paved by some constructors",
             "houses","Small coalminer houses",
             "constructors","They left the place when the path was finished",
            "dust","Coaldust and sand together well mixed",
            "village","Nothing special can be seen here....",
            "working place","A small area which is used to clean the coals",
            "place","A small area which is used to clean the coals"
            });


   smell = "The smell of coals is VERY strong here.\n";
}
