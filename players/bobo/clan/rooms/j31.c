inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In the Jungle.";
   long_desc=
	"This part of the jungle is extremely thin and you can see that\n"+
	"to the north and to the east it clears out into an open field \n"+
	"with large white washed buildings in it.  To the south the jungle\n"+
	"thickens and to the west it is totally impassible.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/open/o6.c","north",
	"/players/bobo/clan/rooms/open/o4.c","east",
	"/players/bobo/clan/rooms/j28.c","south",
      });
   items=({
	"buildings","Quite a few large, impressive white washed buildings are in the field",
	"field","A large grassy field with buildings on it",
	"jungle","It's hardly a jungle here, more of an overgrown area",
      });
   replace_program("room/room");
}
