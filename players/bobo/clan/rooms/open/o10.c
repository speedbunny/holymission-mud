inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
	"You are walking along the edge of the jungle.  There are a\n"+
	"number of big rocks jutting from the ground here and a small\n"+
	"stone building to the north of here.  You can hear a loud\n"+
	"russling on the other side of the thick undergrowth of the\n"+
	"jungle.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/nunnery/n2.c","north",
	"/players/bobo/clan/rooms/j32.c","south",
	"/players/bobo/clan/rooms/open/o9.c","west",
      });
   items=({
	"building","A white stone building with several windows is north of here",
	"ground","It is rocky and uneven, you need to watch your step",
	"jungle","The dense jungle lines the eastern edge of here",
	"rocks","They look like they used to be white but now are covered in moss",
	"undergrowth","You hope it is thick enough to keep the russeling on the other side",
      });
   replace_program("room/room");
}
