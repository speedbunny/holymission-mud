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
"seems to be in disrepair but it still bars your way north and east.\n";
dest_dir=({
	"players/bobo/rooms/island/yard11.c","west",
	"players/bobo/rooms/island/yard8.c","south",
});
items=({
	"plants","Various varieties of plants and weeds have made their home here",
	"trees","The trees here tower overall that you can see",
	"rocks","Once part of the walkway, now just rubble",
	"cobblestone","Once nice and clean, it has beed reduced to rubble",
	"wall","A stone wall about 12 feet high, it is old and marred",
});
replace_program("room/room");
}
