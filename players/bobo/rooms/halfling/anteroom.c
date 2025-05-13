inherit "room/room";
reset (arg) {
   clone_list=({
      1, 2, "guard","/players/bobo/monsters/halflingg1", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "As you walk into this room you immediately notice that it's unlike\n"+
      "the rest of the warren. There is an ornate carpet covering the\n"+
      "floor, and beautiful tapestries adorning the walls. There are many\n"+
      "beautiful things about the room.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/corridor7.c","east",
      "/players/bobo/rooms/halfling/leader.c","west",
      });
   items=({
      "beams","The beams in this area are made of superior wood and are skillfully erected",
      "carpet","The carpet is an ancient one with a weave that is unlike any you've seen",
      "floor","The floor is covered by a beautiful carpet.",
      "tapestries","The tapestries seem to depict a lineage of the halflings of the warren",
      "things","Upon further inspection, though these things are beautiful, they are worthless",
      "walls","The walls are covered with heavy woven tapestries",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   replace_program("room/room");
}
