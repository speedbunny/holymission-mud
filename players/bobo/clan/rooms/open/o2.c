inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
	"You are next to the exit from the open area back into the jungle.\n"+
	"The ground here seems to be maintained by someone as it is covered\n"+
	"with lush grass and is free of debris.  To the north a large\n"+
	"the place is maintained by some force.  To the north a large\n"+
	"stone building looms before you.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/observ/o2.c","north",
	"/players/bobo/clan/rooms/open/o3.c","east",
	"/players/bobo/clan/rooms/j27.c","south",
	"/players/bobo/clan/rooms/open/o1.c","west",
      });
   items=({
	"eyes","You are just sure that eyes of all sorts are rivoted to your body",
	"building","A large white washed building with a rounded top",
	"grass","Thick green grass carpets this area",
	"ground","The ground here is flat and generally free of debris",
	"jungle","The jungle is dark and foreboding with wild noises coming from it",
      });
   replace_program("room/room");
}
