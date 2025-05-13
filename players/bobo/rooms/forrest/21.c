inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc=
"Once part of the forest, now ripped and torn to shreds by lumberjacks.";
long_desc=
"This area has been clearcut some time ago.  There are still dead stumps\n"+
"covering the landscape but as nature does most of the time it is rebuilding\n"+
"and revitalizing.  The terrain is covered with tall grass and an occasional\n"+
"tree.  As a whole, though this area was decimated some time ago it seems to\n"+
"be thriving.";
dest_dir=({
	"players/bobo/rooms/forrest/22.c","east",
	"players/bobo/rooms/forrest/20.c","west",
	"players/bobo/rooms/forrest/32.c","north",
	"players/bobo/rooms/forrest/10.c","south",
});
items=({
	"stumps","Large dead wood rotting in the afternoon sun",
	"holes","Large holes are all over the ground where great trees once were",
});
}
