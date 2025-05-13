inherit "room/room";
reset (arg) {
   clone_list=({
	1, 1, "stork","/players/bobo/monsters/clan/jstork", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
	"This area is quiet and serene, you have a chance to stop and \n"+
	"just marvel at the granduer of your surroundings.  Looking at the\n"+
	"buildings around you, you are in awe of the accomplishments that\n"+
	"people can create.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/open/o9.c","north",
	"/players/bobo/clan/rooms/j32.c","east",
	"/players/bobo/clan/rooms/open/o3.c","south",
	"/players/bobo/clan/rooms/observe/o2.c","west",
      });
   items=({
	"buildings","The buildings around you are extremely large and entirely made of stone",
	"surroundings","Peaceful and serene, what more could an adventurer ask for",
      });
   replace_program("room/room");
}
