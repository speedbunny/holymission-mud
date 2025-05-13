inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
	"You have come to part of the clearing that seems to be more\n"+
	"open than other areas.  There are few rocks on the ground here,\n"+
	"the grass is properly maintained, and it is quiet.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/open/o12.c","north",
	"/players/bobo/clan/rooms/open/o8.c","east",
	"/players/bobo/clan/rooms/observ/o1.c","south",
	"/players/bobo/clan/rooms/temple/t1.c","west",
      });
   items=({
	"clearing","You know, a clearing, lack of obsticles",
	"grass","Green grass that is well maintained",
	"rocks","You have a hard time seeing any rocks in this area",
      });
   replace_program("room/room");
}
