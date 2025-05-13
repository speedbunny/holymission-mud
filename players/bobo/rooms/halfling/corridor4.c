inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "You are walking down the main, and only corridor of the halfling\n"+
      "warren. There are a few torches along the wall dimly lighting up\n"+
      "a space that is practically unimaginable to live in.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/home1.c","north",
      "/players/bobo/rooms/halfling/corridor.c","east",
      "/players/bobo/rooms/halfling/corridor5.c","west",
      });
   items=({
      "beams","Thick wooden beams running up the sides and accross the top of the tunnel",
      "dirt","Yep it's dirt, and it's everywhere",
      "torches","Old torches that look as if they are going to go out at any minute",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   replace_program("room/room");
}
