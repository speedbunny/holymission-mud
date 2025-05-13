inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Opium plant.";
long_desc=
"There is a lot of different things going on here but it is all for\n"+
"the same goal, to produce opium.  There is a large smelting pot in\n"+
"the center of the room.  There are workers wandering in and out of\n"+
"this area doing their job so as of yet you have gone unnoticed.\n";
dest_dir=({
	"players/bobo/rooms/island/prison.c","north",
	"players/bobo/rooms/island/desk.c","south",
});
items=({
	"torches","Wooden torches line the walls",
	"workesrs","Workers going about their business.  You dare not disturb them",
	"pot","A large smelting pot about 14 feet in diameter",
});
replace_program("room/room");
}
