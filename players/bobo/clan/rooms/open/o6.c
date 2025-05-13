inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "kinkajou","/players/bobo/monsters/clan/kinkajou", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
	"This area is out of the way and deserted.  The grass here is\n"+
	"overgrown and not as well tended to as the rest of the clearing.\n"+
	"The density of the jungle to the west barrs you from you from\n"+
	"going that direction.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/open/o11.c","north",
	"/players/bobo/clan/rooms/temple/t1.c","east",
	"/players/bobo/clan/rooms/j31.c","south",
      });
   items=({
	"clearing","You can't see the rest of the clearing",
	"grass","The grass here is thick and overgrown",
	"jungle","the jungle to the west is too dense to pass through",
      });
   replace_program("room/room");
}
