inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Bedroom.";
long_desc=
"This is the room of Kung Lao.  He is one of the combatants of the\n"+
"tournament of the dragon.  The room itself is lavishly decorated in\n"+
"eastern decor.  It has a large bed, fancy drapes, beautiful tapestries,\n"+
"and a bare hard wood floor.\n";
dest_dir=({
	"players/bobo/rooms/island/hall1.c","west",
});
items=({
	"bed","A fancy four poster bed with cloth strung across the top",
	"drapes","Large gaudy cloth cover the windows",
	"tapestries","These depict ancient ronin fighting to win some honor",
	"floor","A beautiful brown glossy wooden floor",
});
replace_program("room/room");
}
