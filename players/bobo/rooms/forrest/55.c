inherit "room/room";
object ob;
reset (arg) {
	if(!ob|| !living(ob)) {
	ob = clone_object("players/bobo/monsters/rabbit");
	move_object(ob, this_object());
}
if (arg) return;
set_light(1);
short_desc="A wonderful forrest filled with life.";
long_desc="You have entered a very large, very vibrant forrest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  There is a mist barring your way east.\n";
dest_dir=({
	"players/bobo/rooms/forrest/54.c","west",
	"players/bobo/rooms/plains/11.c","north",
	"players/bobo/rooms/forrest/44.c","south",
});
items=({
	"canopy","Not to dense, this let's a lot of light shine down on you.",
	"trees","Many different types of trees make up this forrest",
	"mist","A dense forbidding mist, you are much to scared to enter it."
});
}
