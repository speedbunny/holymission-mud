inherit "room/room";
object ob;
reset (arg) {
	if(!ob|| !living(ob)) {
		ob = clone_object("players/bobo/monsters/moose");
		move_object(ob,this_object());
}
if (arg) return;
set_light(1);
short_desc="A wonderful forest filled with life.";
long_desc=
"You have entered a very large, very vibrant forest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  This looks like a good spot to camp.\n";
dest_dir=({
	"players/bobo/rooms/forrest/26.c","east",
	"players/bobo/rooms/forrest/24.c","west",
	"players/bobo/rooms/forrest/36.c","north",
	"players/bobo/rooms/forrest/14.c","south",
});
items=({
	"canopy","Not to dense, this lets a lot of light shine down on you",
	"trees","Many different types of trees make up this forest",
});
}
