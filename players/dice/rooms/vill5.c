
inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are walking in the village.\n"+
     "Pretty dusty here, but you might get used to that. \n"+
     "The village is entirly deserted...\n"+
     "At least ...  that's what it looks like. \n"+
     "The path has changed into a good road. \n";

   dest_dir = ({
      "players/dice/rooms/vill4","west",
      "players/dice/rooms/vill6","east"
       });

   items =({
            "path","A path, carefully paved by some constructors",
            "houses","Small Coalminerseses.",
            "dust","Coaldust and sand together well mixed"
            });


   smell = "The smell of fresh bread has almost vanished here.\n";
}
