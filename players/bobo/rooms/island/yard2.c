inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The yard.";
long_desc=
"You have come to a corner of the area inside the walls.  The wall\n"+
"blocks your way east and south.  This place is quiet, almost\n"+
"unsettlingly so.  The only other living thing in this area except\n"+
"you is some grass that has pushed through the cobblestone.\n";
dest_dir=({
	"players/bobo/rooms/island/yard1.c","west",
	"players/bobo/rooms/island/yard4.c","north",
});
items=({
	"grass","Some grass has grown in the cracks of the cobblestone",
	"cobblestone","well kept cobblestone with few cracks in it",
	"wall","A stone wall about 12 feet high",
	"walls","Stone walls about 12 feet high",
});
replace_program("room/room");
}
