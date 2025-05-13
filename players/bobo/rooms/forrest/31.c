inherit "room/room";
object lumberjack;
reset (arg) {
::reset (arg);
if (arg) return;
lumberjack = clone_object("players/bobo/monsters/lumberjack.c");
transfer(lumberjack,this_object());
lumberjack = clone_object("players/bobo/monsters/lumberjack.c");
transfer(lumberjack,this_object());
lumberjack = clone_object("players/bobo/monsters/lumberjack.c");
transfer(lumberjack,this_object());
set_light(1);
short_desc="Lumber farm.";
long_desc=
"You have wandered into an area where lumberjacks are working hard at\n"+
"cutting down all the trees.  There are large piles of trees ready for\n"+
"transport.  You are being paid not attention to and everyone seems to\n"+
"be doing their job; demolishing the forest\n";
dest_dir=({
	"players/bobo/rooms/forrest/32.c","east",
	"players/bobo/rooms/forrest/30.c","west",
	"players/bobo/rooms/forrest/42.c","north",
	"players/bobo/rooms/forrest/20.c","south",
});
items=({
	"stumps","Large dead wood rotting in the affternoon sun",
	"holes","Large holes are all over the ground where great trees once were",
	"piles","Vast groupings of trees awaiting removal",
});
}
