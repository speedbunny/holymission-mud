inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The yard.";
long_desc=
"Entering this area you are awe struck by the sheer beauty of it.\n"+
"There are flowers planted running parallel to the wall, shrubs\n"+
"neatly groomed.  The cobblestone is swept and kept clear of debris.\n"+
"You almost feel like you are invading on the quiet majesty of it all.\n"+
"to the west is the ring, the whole reason why this island is here.\n";
dest_dir=({
	"players/bobo/rooms/island/ring.c","west",
	"players/bobo/rooms/island/yard8.c","north",
	"players/bobo/rooms/island/yard4.c","south",
});
items=({
	"cobblestone","Well kept cobblestone with few cracks in it",
	"wall","A stone wall about 12 feet high",
	"flowers","Beautiful flowers of all sorts adorn the flower bed",
	"shrubs","They are well kept and have been cut into intricate patterns",
	"ring","The fighting ring, it is the reason for the whole island",
});
replace_program("room/room");
}
