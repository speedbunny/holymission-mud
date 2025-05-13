inherit "room/room";
reset (arg) {
   clone_list=({
      1, 4, "man","/players/bobo/monsters/halflingm2", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "You are in the halfling workshop.  This is where they make all the\n"+
      "different tools that they use.  There are several large tables here\n"+
      "with different projects on them.  There is a metronome in the back of\n"+
      "the room.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/corridor5.c","north",
      });
   items=({
      "beams","Thick wooden beams running up the sides and accross the top of the tunnel",
      "dirt","Yep it's dirt, and it's everywhere",
      "metronome","The metronome is ticking rythmically.  Tick...tick...tick..",
      "projects","Several projects are on the table, you can't tell what they are yet",
      "tables","Large work tables are taking up the majority of this room",
      "tools","Halflings, like other races use all sorts of tools and they don't grow on trees",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   replace_program("room/room");
}
