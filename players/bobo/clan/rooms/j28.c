inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "margay","/players/bobo/monsters/clan/margay", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In the Jungle.";
   long_desc=
	"You are at the very edge of a dense jungle.  You can see that\n"+
        "To the northa nd the east of you the jungle is not quite as \n"+
        "dense as it is here, while any of the other directions the\n"+
	"jungle thickens to the point where you would have to cut your\n"+
	"way through it, and you just don't feel that energetic.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/j31.c","north",
	"/players/bobo/clan/rooms/j29.c","east",
      });
   items=({
	"jungle","The jungle here is dense, but not as dense as other areas",
      });
   replace_program("room/room");
}
