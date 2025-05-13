inherit "room/room";
reset (arg) {
if (arg) return;
set_light(10);
short_desc="The refracting station.";
long_desc="Wandering into this clearing you are struck by the brilliance of\n"+
"a very large, very radiant beam of energy.  There is a building in the\n"+
"center of the clearing which the beam passes through.  The beam runs both\n"+
"northeast and south from the building.  There is a path leading to the north\n"+
"where you speculate the beam uused to run that trees seem to be starting to\n"+
"re-establish themselves in but where the beam is to the northeast there is\n"+
"devestation where half-trees lie, torn apart by the beam\n";
dest_dir=({
	"players/bobo/rooms/forrest/29.c","east",
	"players/bobo/rooms/forrest/27.c","west",
	"players/bobo/rooms/forrest/17.c","south",
	"players/bobo/rooms/forrest/39.c","north",
});
items=({
   "trees","The trees that are so thick in the forest shy away from the beam.",
   "beam","The energy seems to be of a magical sort. It is about 8 feet across",
   "building","The building seems to be some sort of refracting station.",
});
}
init() {
  ::init();
  add_action("enter","enter");
}
enter(str) {
  if (str=="station") {
  write("You enter the station.\n");
  this_player()->move_player("enters the station#players/bobo/rooms/forrest/refract1");
return 1;
}
}
