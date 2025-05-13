inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "smonkey","/players/bobo/monsters/clan/smonkey", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
        "Entering this area you think that it's rather nondescript\n"+
	"and that there is nothing special about it but then you \n"+
	"notice a large hole in the ground with a pile of dirt next\n"+
        "to it.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/open/o13.c","north",
	"/players/bobo/clan/rooms/open/o9.c","east",
	"/players/bobo/clan/rooms/observ/o8.c","south",
	"/players/bobo/clan/rooms/open/o8.c","west",
      });
   items=({
	"area","This part of the clearing barely looks different than the rest, save the hole",
	"dirt","A large pile of loose dirt sits next to the hole",
	"hole","A large hole, it is a few feet deep",
	"ground","grass covers the ground, except where the hole is",
	"pile","A large pile of loose dirt sits next to the hole",
      });
   replace_program("room/room");
}
