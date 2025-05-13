inherit "room/room";
object ob;
reset (arg) {
	if(!ob|| !living(ob)) {
	ob = clone_object("players/bobo/monsters/moose");
	move_object(ob, this_object());
}
if (arg) return;
set_light(1);
short_desc="A wonderful forest filled with life";
long_desc=
"Yo have entered a very large, very vibrant forest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  There is a mist barring your way south.\n";
"and south.\n";
dest_dir=({
	"players/bobo/rooms/forrest/4.c","east",
	"players/bobo/rooms/forrest/2.c","west",
	"players/bobo/rooms/forrest/14.c","north",
});
items=({
	"canopy","Not to dense, this lest a lot of light shine down on you",
	"trees","Man;y different types of trees make up this forest",
	"mist","A dense forbidding mist, you are much to afraid to enter it",
});
}
