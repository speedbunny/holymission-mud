inherit "room/room";
object ob;
reset (arg) {
	if(!ob|| !living(ob)) {
	ob = clone_object("players/bobo/monsters/rabbit");
	move_object(ob, this_object());
}
if (arg) return;
set_light(1);
short_desc="A wonderfull forest filled with life";
long_desc=
"You have entered a very large, very vibrant forest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  There is a mist barring your way east.\n";
dest_dir=({
	"players/bobo/rooms/forrest/21.c","west",
	"players/bobo/rooms/forrest/33.c","north",
	"players/bobo/rooms/forrest/11.c","south",
});
items=({
	"canopy","Not to dense, this lets a lot of light shine down on you",
	"trees","Many different types of trees make up this forest",
	"mist","A dense forbidding mist, you are much to scared to enter it",
});
}
