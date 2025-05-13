inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In the Jungle.";
   long_desc=
	"Entering this area you are struck by the fact that even though\n"+
	"the rest of the area is jungle in the center there is a small\n"+
	"clearing with a single plant in it.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/open/o10.c","north",
	"/players/bobo/clan/rooms/j30.c","south",
	"/players/bobo/clan/rooms/open/o5.c","west",
      });
   items=({
	"clearing","A spot in the soil that is void of plants",
	"plant","It is a medium sized plant with leaves that are larger than average",
      });
   replace_program("room/room");
}
