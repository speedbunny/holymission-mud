inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "monkey","/players/bobo/monsters/clan/monkey", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
	"You have entered an open area near the edge of the jungle.\n"+
	"You can feel the eyes of animals in the jungle near you watching,\n"+
	"hoping that you drop some item of interest.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/observ/o1.c","north",
	"/players/bobo/clan/rooms/open/o2.c","east",
	"/players/bobo/clan/rooms/j29.c","west",
      });
   items=({
      "animals","Though you can't see them, you know that they're there...watching you",
	"eyes","You are just sure that eyes of all sorts are rivoted to your body",
	"jungle","The jungle is dark and foreboding with wild noises coming from it",
      });
   replace_program("room/room");
}
