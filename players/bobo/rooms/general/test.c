inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
	short_desc="Bobo's first test room.";
	long_desc="This is absolutely with out a doubt the most horrid room you have\n" +
"ever been in. It is filthy and there are roaches scurrying across the floor\n";
smell="this area reeks the stink of a thousand stinks";
dest_dir=({
	"players/bobo/workroom.c", "out",
	"/room/church","church",
	});
items=({
	"roaches","filthy disgusting creatures",
	"trash","you have to wade through all the garbage in this room"
});
}
