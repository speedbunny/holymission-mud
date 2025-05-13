inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="A wonderful forest filled with life.";
long_desc=
"You have entered a very large, very vibrant forest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  There is a mist barring your way both west\n"+
"and south.\n";
dest_dir=({
	"players/bobo/rooms/forrest/2.c","east",
	"players/bobo/rooms/forrest/12.c","north",
});
items=({
	"canopy","Not to dense, this les a lot of light shine down on you",
	"trees","Many different types of trees make up this forest",
	"mist","A dense forbidding mist, you are much to afraid to enter it",
});
}
