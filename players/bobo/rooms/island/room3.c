inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Bedroom.";
long_desc=
"This room is totally empty except a small bed.  There is nothing\n"+
"else in here.  There is apparently a member of the tournament that\n"+
"either has not arrived or doesn't realize that they are a part of\n"+
"it yet.\n";
dest_dir=({
	"players/bobo/rooms/island/hall2.c","west",
});
items=({
	"bed","A small single bed without any sheets or blankets on it",
});
replace_program("room/room");
}
