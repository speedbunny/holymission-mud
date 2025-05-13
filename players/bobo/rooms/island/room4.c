inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Bedroom.";
long_desc=
"This room is sparsely furnished.  There is a bed of nails\n"+
"in the corner.  Other than that the only thing in this room\n"+
"is a bamboo sword mounted on the wall.\n";
dest_dir=({
	"players/bobo/rooms/island/hall2.c","east",
});
items=({
	"bed","A bed that you would certainly not enjoy sleeping on",
	"sword","This sword is almost strictly for practice purposes",
	"nails","These look like standard three inch nails",
});
replace_program("room/room");
}
