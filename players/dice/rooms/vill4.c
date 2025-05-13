
inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are walking in the village.\n"+
     "It looks like all the inhabitants are coalminers.\n"+
     "But as of now, the village is entirely deserted...\n"+
     "At least ...  that's what it looks like. \n"+
     "The path has changed into a good road. \n";

   dest_dir = ({
      "players/dice/rooms/vill3","west",
      "players/dice/rooms/vill5","east"
       });

   items =({
            "path","A path, carefully paved by some constructors",
            "houses","Small Coalminers houses",
            "road","A road, carefully plaved by some constructors.",
            "inhabitants","They are not here now, maybe further on in the village."
            });


   smell = "The smell of fresh bread has almost vanished here.\n";
}
