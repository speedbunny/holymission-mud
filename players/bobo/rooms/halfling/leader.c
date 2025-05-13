inherit "room/room";
#define TP this_player()
#define MP move_player
reset (arg) {
   if (arg) return;
   clone_list=({
      1, 2, "guard","/players/bobo/monsters/halflingg3", 0,
      2, 1, "leader","/players/bobo/monsters/halflingl", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "Entering this room you are almost overwhelmed by the sense that you\n"+
      "do not belong here, and you notice that everyone in the room is\n"+
      "staring at you. There is a beautiful carpet running down the center\n"+
      "of the room leading to a large chair where a mighty halfling must\n"+
      "often sit.  At the front of the chair to either side of it are two\n"+
      "guard postings.  Also in this room are two lines of stone pillars,\n"+
      "each line running parallel to the carpet.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/anteroom.c","east",
      });
   items=({
      "carpet","A royal blue fabric with gold trim.  It runs from the chair to the exit",
      "chair","A large solid chair with carvings all over the arms and back",
      "carvings","On the back of the chair there seems to be an eye staring at you",
      "pillars","Five white stone pillars run along both sides of the carpet",
      "posting","The posting is in front of the halfling leader guarding from attack",
      "tapestries","The tapestries seem to depict a lineage of the halflings of the warren",
      "walls","The walls are covered with heavy woven tapestries",
      });
}

init () {
   ::init();
   add_action("search","search");
   add_action("press","press");
}
press(str) {
   if(str=="eye") {
      write("You press the eye staring at you revealing a stairway going "+
            "down into\nthe massive chair");
      TP->MP("climbs down a secret passage#players/bobo/rooms/halfling/treasury");
      return 1;
   }
}
search(arg) {
   if(arg !="chair") return 0;
   write("You notice nothing strange about the chair except the eye.\n");
   return 1;
}
