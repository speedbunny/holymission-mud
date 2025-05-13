inherit "room/room";
object ob;
reset (arg) {
	if(!ob|| !living(ob)) {
	ob = clone_object("players/bobo/monsters/rabbit");
	move_object(ob,this_object());
}
if (arg) return;
set_light(1);
short_desc="A wonderful forest filled with life.";
long_desc=
"You have entered a very large, very vibrant forest.  Everywwhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  There is a mist barring your way west.\n";
dest_dir=({
	"players/bobo/rooms/forrest/46.c","east",
	"players/bobo/rooms/plains/1.c","north",
	"players/bobo/rooms/forrest/34.c","south",
	"players/bobo/rooms/forrest/23.c","south",
});
items=({
	"canopy","Not to dense, this lets a lot of light shine down on you",
	"trees","Many different types of trees make up this forest",
	"mist","A dense forbidding mist, you are much to afraid to enter it",
});
}
