inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="A wonderful forrest filled with life.";
long_desc="You have entered a very large, very vibrant forrest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  This looks like a good spot to camp.\n";
dest_dir=({
	"players/bobo/rooms/forrest/55.c","east",
	"players/bobo/rooms/forrest/53.c","west",
	"players/bobo/rooms/plains/10.c","north",
	"players/bobo/rooms/forrest/43.c","south",
});
items=({
	"canopy","Not to dense, this let's a lot of light shine down on you.",
	"trees","Many different types of trees make up this forrest",
});
}
