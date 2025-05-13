inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The yard.";
long_desc=
"You have come to another corner.  In this corner there seems to be a\n"+
"lack of care for things that go on here.  The plants and trees have\n"+
"have grown unchecked here.  The nice cobblestone that is in the rest\n"+
"of the area has been reduced to groupings of rocks.  Even the wall\n"+
"seems to be in disrepair but it still bars your way north and west.\n";
dest_dir=({
	"players/bobo/rooms/island/yard11.c","east",
	"players/bobo/rooms/island/yard9.c","south",
});
items=({
	"plants","Various varieties of plants and weeds have made their home here",
	"trees","Large trees that grow high above everything else you can see",
	"cobblestone","Once nice and clean, it has been reduced to rubble",
	"wall","A stone wall about 12 feet high, it is old and marred",
	"rocks","Once part of the walkway now just rubble",
});
replace_program("room/room");
}
