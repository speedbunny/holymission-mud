inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
	"This area is the most open area of the clearing, you can see\n"+
	"A long way around you. The grass extends aound you for a very\n"+
	"long way.  To the immediate west you can see a tall building with\n"+
	"pillars lining the front of it.  To the far north east and south\n"+
	"you can make out white stoned buildings.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/open/o14.c","north",
	"/players/bobo/clan/rooms/open/o13.c","east",
	"/players/bobo/clan/rooms/open/o7.c","south",
	"/players/bobo/clan/rooms/temple/t1.c","west",
      });
   items=({
	"building","Which building do you want to look at?",
	"buildings","You can see four different buildings, each made of stone",
	"clearing","The mostly flat grassy clearing extends a long way",
	"east building","You can't make out much from here, just the stone walls",
	"grass","Green grass goes on almost unimpeded throughout the clearing",
	"pillars","Rows of stone pillars line the front of a massive building",
	"north building","You can see A massive pyramid like building",
	"south building","Though you can't see much from here you can see an arched roof",
	"west building","The building to your west is a large rectangular stone building",
      });
   replace_program("room/room");
}
