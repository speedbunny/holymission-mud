inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "This area looks to be a site where the warren will be expanded.\n"+
      "There are various tools strewn about the room and there is also a\n"+
      "large indentation in the north wall where it seems the halflings\n"+
      "have been digging.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/corridor2.c","east",
      "/players/bobo/rooms/halfling/corridor.c","south",
      });
   items=({
      "beams","Thick wooden beams running up the sides and accross the top of the tunnel",
      "dirt","Yep it's dirt, and it's everywhere",
      "indentation","There is the beginning of a new tunnel on the north wall",
      "north wall","There is a large indentation in the north wall",
      "site","It looks like there is some major construction going on here",
      "tools","Halfling shovels, pick axes and other tools valuable to no one",
      "wall","The wall is slowly being removed, and now there is a large indentation in it",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   replace_program("room/room");
}
