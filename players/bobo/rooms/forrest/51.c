inherit "room/room";
object ob;
reset (arg) {
	if(!ob|| !living(obj)) {
	ob = clone_object("players/bobo/monsters/bear");
	move_object(ob,this_object());
}
if (arg) return;
set_light(1);
short_desc="A wonderful forrest filled with life.";
long_desc="You have entered a very large, very vibrant forrest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  This looks like a good spot to camp.\n";
dest_dir=({
	"players/bobo/rooms/forrest/52.c","east",
	"players/bobo/rooms/forrest/50.c","west",
	"players/bobo/rooms/plains/7.c","north",
	"players/bobo/rooms/forrest/40.c","south",
});
items=({
	"canopy","Not to dense, this let's a lot of light shine down on you.",
	"trees","Many different types of trees make up this forrest",
});
}
