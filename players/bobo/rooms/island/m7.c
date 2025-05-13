inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Mirror maze.";
long_desc=
"You have entered a mirror maze.  Can you make it to the end?  Can\n"+
"you even make it to the beginning?  Where are you now?\n";
dest_dir=({
	"players/bobo/rooms/island/m7.c","east",
	"players/bobo/rooms/island/m7.c","west",
	"players/bobo/rooms/island/m8.c","north",
	"players/bobo/rooms/island/m6.c","south",
});
items=({
	"mirrors","Is it a mirror or is it real?",
});
replace_program("room/room");
}
