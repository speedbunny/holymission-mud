inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "child","/players/bobo/monsters/halflingc", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "This is a small portion of the corridor that seems to be abandonded\n"+
      "to the general population. It is obvious that someone very naive\n"+
      "frequents this area however, because there are little bits of refuse\n"+
      "hidden poorly around the corridor.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/corridor3.c","south",
      "/players/bobo/rooms/halfling/corridor1.c","west",
      });
   items=({
      "beams","Thick wooden beams running up the sides and accross the top of the tunnel",
      "bits","Peices of trash are scattered about half buried in the dirt",
      "corridor","This portion is similar to the rest of the warren, beaams and dirt",
      "dirt","Yep it's dirt, and it's everywhere",
      "refuse","Portions of paper and food are half covered by dirt throughout the corridor",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   replace_program("room/room");
}
