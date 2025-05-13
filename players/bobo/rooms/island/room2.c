inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Bedroom.";
long_desc=
"You have entered Terva's room.  It is not to fancy but does\n"+
"bear a certain elegance.  There is of course a bed, also in\n"+
"this room is a vanity, some paintings, a plaque, two chairs,\n"+
"and a small table\n";
dest_dir=({
	"players/bobo/rooms/island/hall1.c","east",
});
items=({
	"bed","Not to fancy, this king sized bed is covered with satin",
	"vanity","This has a large mirror and a couple of drawers",
	"chairs","Two high back cushioned chairs sit near the table",
	"table","A small marble table about 3 feet in diameter",
	"plaque","This has some foriegn writing on it, there is a throw pillow under it",
	"paintings","Odd paintings of various landscapes",
	"pillow","There appears to be indents from someone kneeling on it",
});
replace_program("room/room");
}
