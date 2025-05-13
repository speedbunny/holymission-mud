inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "You are in a small corridor that is dimly lit by a torch on the\n"+
      "wall. This area, like most of the warren, seems to be just dirt and\n"+
      "support beams.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/corridor1.c","north",
      "/players/bobo/rooms/halfling/corridor3.c","east",
      "/players/bobo/rooms/halfling/entrance.c","south",
      "/players/bobo/rooms/halfling/corridor4.c","west",
      });
   items=({
      "beams","Thick wooden beams running up the sides and accross the top of the tunnel",
      "dirt","Yep it's dirt, and it's everywhere",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   replace_program("room/room");
}
