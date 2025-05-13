inherit "room/room";
object ob;
reset (arg) {
	if(!ob|| !living(ob)) {
	ob = clone_object("players/bobo/monsters/bear");
	move_object(ob,this_object());
}
if (arg) return;
set_light(1);
short_desc="A wonderful forest filled with life";
long_desc=
"You have entered a very large, very vibrand forest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  There is a mist barring your way south.\n";
dest_dir=({
	"players/bobo/rooms/forrest/8.c","east",
	"players/bobo/rooms/forrest/6.c","west",
	"players/bobo/rooms/forrest/18.c","north",
});
items=({
	"canopy","Not to dense, this lets a lot of light shine down on you",
	"trees","Many different types of trees make up this forest",
	"mist","A dense forbidding mist, you are much to afraid to enter it",
});
}
