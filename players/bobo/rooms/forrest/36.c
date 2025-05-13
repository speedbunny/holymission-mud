inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="A wonderful forest filled with life.";
long_desc=
"You have entered a very large, very vibrant forest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  This looks like a good spot to camp.\n";
dest_dir=({
	"players/bobo/rooms/forrest/37.c","east",
	"players/bobo/rooms/forrest/35.c","west",
	"players/bobo/47.c","north",
	"players/bobo/rooms/forrest/25.c","south",
});
items=({
	"canopy","Not to dense, this lets a lot of light shine down on you",
	"trees","many different types of trees make up this forest",
});
}
