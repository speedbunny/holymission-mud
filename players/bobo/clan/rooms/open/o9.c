inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
	"This section of the clearing is directly south of a small\n"+
	"stone ediface.  The ground here is littered with a number\n"+
	"of large rocks making it slightly difficult to navigate.\n"+
   dest_dir=({
	"/players/bobo/clan/rooms/nunnery/n1.c","north",
	"/players/bobo/clan/rooms/open/o10.c","east",
	"/players/bobo/clan/rooms/open/o5.c","south",
	"/players/bobo/clan/tooms/open/o8.c","west",
      });
   items=({
	"ediface","A large white stoned ediface looms over you in the north",
	"rocks","Large stone rocks jut out from the ground, they to have been here for some time"
      });
   replace_program("room/room");
}
