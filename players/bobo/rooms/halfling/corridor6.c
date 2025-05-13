inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "This portion of the corridor looks as if there has been little\n"+
      "gremlins making mischief here. There are portions of the wall gouged\n"+
      "out, chips in the beams, and mounds of dirt all around the area. To\n"+
      "the north you can hear loud noises, and screeching halfling voices.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/nursery.c","north",
      "/players/bobo/rooms/halfling/corridor5.c","east",
      "/players/bobo/rooms/halfling/corridor7.c","west",
      });
   items=({
      "beams","The beams in this area seem to have been carved on a lot",
      "chips","Small portions of the beams have been torn away by someone",
      "dirt","Yep it's dirt, and it's everywhere",
      "mounds","Small mounds of dirt are all over here, some of them are larger than others",
      "wall","Little portions of the wall have been scratched away",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   replace_program("room/room");
}
