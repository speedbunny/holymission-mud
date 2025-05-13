inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The yard.";
long_desc=
"This area is in shambles as compared to the rest of the area.  It\n"+
"seems that no one has been in here for ages to do any sort of work.\n"+
"it is practically a jungle of plants.  However there doesn't seem\n"+
"to be a break in the wall however chipped it might be.  The other\n"+
"thing missing from this jungle is animals.\n";
dest_dir=({
	"players/bobo/rooms/island/yard10.c","east",
	"players/bobo/rooms/island/yard12.c","west",
	"players/bobo/rooms/island/shed.c","south",
});
items=({
	"plants","Various varieties of plants and weeds have made their home here",
	"trees","Large trees that grow high above everything else you can see",
	"cobblestone","once nice and clean, it has been turned to rubble",
	"wall","A stone wall chipped and cracked but still there",
	"jungle","A thick overgrowth of plants and trees",
	"animals","There are no animals about",
});
replace_program("room/room");
}
