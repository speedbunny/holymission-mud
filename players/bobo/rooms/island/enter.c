inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The island of The Dragon.";
long_desc=
"You are on the border of the real world and the world of The Dragon,\n"+
"where there is only his way.  To the north are the gates leading into\n"+
"the compound.  The gate is kept between two stone walls.  There is  \n"+
"no way to go around the walls due to the dense trees.\n";
dest_dir=({
	"players/bobo/rooms/island/yard1.c","north",
});
items=({
	"trees","These dense trees block any passage around the camp",
	"wall","A stone wall about 12 feet high",
	"walls","The walls around the compound are 12 feet high",
        "gate","A metal gate.  It is currently open",
        "gates","Metal gates.  They are currently open",
});
replace_program("room/room");
}
