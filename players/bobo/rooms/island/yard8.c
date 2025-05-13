inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The yard.";
long_desc=
"You have come into an area with a large amount of trees.  The\n"+
"cobblestone is cracking and breaking up.  Large chunks of it\n"+
"are missing.  Despite the lack of care given to the the brick\n"+
"beneath your feet, the area is otherwise tidy and to the west there\n"+
"is a small shack.  The wall continues to run from north to south.\n";
dest_dir=({
	"players/bobo/rooms/island/shed.c","west",
	"players/bobo/rooms/island/yard10.c","north",
	"players/bobo/rooms/island/yard6.c","south",
});
items=({
	"cobblestone","The cobblestone in this area is marred and broken",
	"chunks","Large pieces of rock are scattered in the northern part of this area",
	"shack","A small looking wooden shack",
	"wall","A stone wall about 12 feet high",
	"shed","A nice little wooden shed",
	"trees","Large trees tower over everything in this area",
});
replace_program("room/room");
}
