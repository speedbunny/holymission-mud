inherit "room/room";
reset (arg) {
   clone_list=({
      1, 2, "nanny","/players/bobo/monsters/halflingcg", 0,
      2, 4, "child","/players/bobo/monsters/halflingc3", 0,
      3, 1, "girl","/players/bobo/monsters/halflingfc", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "This is the halfling nursery where all the little children of the\n"+
      "warren are normally cared for. There are all sorts of toys in the\n"+
      "room as well as several big messes from the children. In the corner\n"+
      "of the room is the discipline keeper.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/corridor6.c","south",
      });
   items=({
      "beams","Thick wooden beams running up the sides and accross the top of the tunnel",
      "dirt","Yep it's dirt, and it's everywhere",
      "discipline keeper","This is a big wooden paddle with holes through it so that air can pass through",
      "messes","typical children messes are scattered about the room",
      "toys","Blocks and other toys are all over this area",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   replace_program("room/room");
}
