inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
	"This portion of the clearing is surrounded on three of the four\n"+
	"directions. The only direction that you can see that the\n"+
	"clearing continues is to the south, other than that there are\n"+
	"large buildings to the north and east and east, while the jungle\n"+
	"blocks your passage to the west.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/ball/b1.c","north",
	"/players/bobo/clan/rooms/temple/t1.c","east",
	"/players/bobo/clan/rooms/open/o6.c","south",
      });
   items=({
	"buildings","There are large, white stoned buildings to the north and east",
	"clearing","The clearing here seems not to be frequented to often and is desolate",
	"jungle","The jungle seems to rise up like a wall and is impenetrable",
	"north building","You are staring at the back of a building which is about 20 feet high",
	"east building","This building is excedingly tall, you are too close to it for a good estimate",
      });
   replace_program("room/room");
}
