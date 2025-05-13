inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "child","/players/bobo/monsters/halflingc1", 0
   });
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
"The corridor continues on here with little change. There are a\n"+
      "few torches lining the wall of this otherwise barren hallway.\n"+
"They barely light up the hallway, making this a miserable place\n"+
      "to live.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/home2.c","north",
      "/players/bobo/rooms/halfling/corridor4.c","east",
      "/players/bobo/rooms/halfling/workshop.c","south",
      "/players/bobo/rooms/halfling/corridor6.c","west",
      });
   items=({
      "beams","Thick wooden beams running up the sides and accross the top of the tunnel",
      "dirt","Yep it's dirt, and it's everywhere",
      "torches","Old torches that look as if they are going to go out at any minute",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   replace_program("room/room");
}
