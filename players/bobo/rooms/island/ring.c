inherit "room/room";
reset (arg) {
::reset (arg);
if (arg) return;
set_light(1);
short_desc="The ring";
long_desc=
"In this area it there is a large fighting ring about 14 meters in\n"+
"diameter.  It is made of some sort of wood.  Directly to the\n"+
"south of it is a thronelike chair.  Though the ring is empty now\n"+
"you sense that it won't be for long and that eventually there will\n"+
"be great warriors to fight for both their honor and their lives.\n";
dest_dir=({
	"players/bobo/rooms/island/yard6.c","east",
	"players/bobo/rooms/island/yard7.c","west",
	"players/bobo/rooms/island/shed.c","north",
	"players/bobo/rooms/island/house.c","south",
});
items=({
	"house","A beautiful house created out of oriental architecture",
	"chair","This is where the dragon sits when there is combat",
	"ring","The fighting ring is empty...for now",
	"cobblestone","Well kept cobbleston with no cracks in it",
});
replace_program("room/room");
}
