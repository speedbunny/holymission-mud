inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Great hall.";
long_desc=
"This is the southern end of the great hall.  It is very ornately\n"+
"decorated and looks great for entertaining.  There is golden\n"+
"wall paper with various red designs on it, ancient vases line\n"+
"the sides of this room.  Lavish throw rugs adorn the floor and\n"+
"there are several beautiful crystaline chandeliers hanging from\n"+
"the ceiling.\n";
dest_dir=({
	"players/bobo/rooms/island/room1.c","east",
	"players/bobo/rooms/island/room2.c","west",
	"players/bobo/rooms/island/hall2.c","north",
	"players/bobo/rooms/island/house1.c","south",
});
items=({
	"wall paper","Very expensive looking, could it be real gold?",
	"chendeliers","Fabulously crafted with many intricate branches",
	"vases","Very ornate, you wonder what dynasty they are from",
	"rugs","These rugs are of the best quality and are well maintained",
});
replace_program("room/room");
}
