inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "This is a corner of the warren corridor. The beams of this area\n"+
      "seem to have been hastily erected and quickly abandonded. The dirt\n"+
      "in this area seems to be more carefully smoothed out than in much\n"+
      "of the warren however.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/corridor2.c","north",
      "/players/bobo/rooms/halfling/corridor.c","west",
      });
   items=({
      "beams","Thick wooden beams running up the sides and accross the top of the tunnel",
      "corner","This is a corner of the corridor and as such only has two walls",
      "dirt","The ground here seems to have been smoothed out quite nicely for some reason",
      "warren","Though this is only the entrance, hopefully it won't all look like this",
      });
   move_object(clone_object("players/bobo/obj/doll.c"),this_object());
   replace_program("room/room");
}
