inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc=
"once part of the forest, now ripped and torn to shreds by lumberjacks.";
long_desc=
"You have come into an area totally devoid of life.  The trees which used to\n"+
"be here have all been cut down.  The only thing that remains of the once\n"+
"great forrest is the stumps on the ground.  Some of which have been \n"+
"partially uprooted.  Where others obviously were there are just large\n"+
"holes left.\n";
dest_dir=({
	"players/bobo/rooms/forrest/21.c","east",
	"players/bobo/rooms/forrest/19.c","west",
	"players/bobo/rooms/forrest/31.c","north",
	"players/bobo/rooms/forrest/9.c","south",
});
items=({
	"stumps","Large dead wood rotting int the afternoon sun",
	"holes","Large holes are all over the ground where great trees once were",
});
}
