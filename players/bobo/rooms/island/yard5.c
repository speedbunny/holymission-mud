inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The yard.";
long_desc=
"You are in the area running between the side of the house and the\n"+
"wall.  This area is empty and quiet and otherwise uniteresting.\n"+
"However some movement from inside the house catches your eye.\n";
dest_dir=({
	"players/bobo/rooms/island/yard7.c","north",
	"players/bobo/rooms/island/yard3.c","south",
});
items=({
	"cobblestome","Well kept cobblestone with few cracks in it",
	"wall","A stone wall about 12 feet high",
	"house","A beautiful house created out of oriental architecture.",
	"movement","You catch a glimpse of a person through a window",
});
replace_program("room/room");
}
