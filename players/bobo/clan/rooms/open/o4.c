inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "capybara","/players/bobo/monsters/clan/capybara", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
	"This is a small grassy area that seems squeezed between a large\n"+
	"dome roofed building to the east, a building with large free\n"+
	"standing pillars next to it to the north, and jungle to both\n"+
	"the south and west.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/temple/t1.c","north",
	"/players/bobo/clan/rooms/observ/o1.c","east",
	"/players/bobo/clan/rooms/j29.c","south",
	"/players/bobo/clan/rooms/j31.c","west",
      });
   items=({
	"area","just a small, boxed in grassy area",
	"building","which building do you want to look at",
	"building with pillars","This large building is very tall and to the east of it there are pillars",
	"dome roofed building","A large domed roof caps this building, you cannot see beyond it",
	"jungle","The jungle surrounding this area is thinner than in other areas",
      });
   replace_program("room/room");
}
