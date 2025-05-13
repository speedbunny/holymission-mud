inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({
        1, 2, "guard", "players/bobo/monsters/guard", 0, 
});
::reset(arg);
set_light(1);
short_desc="The yard.";
long_desc=
"You are in the entrance way to this compound.  To the north there\n"+
"is a large house built with oriental style architecture in\n"+
"mind.  To the south the gates stand open with a guard at each edge\n"+
"of it.  The ground here has changed from sand to a well kept\n"+
"cobblestone.\n";
dest_dir=({
	"players/bobo/rooms/island/yard2.c","east",
	"players/bobo/rooms/island/yard3.c","west",
	"players/bobo/rooms/island/house.c","north",
	"players/bobo/rooms/island/enter.c","south",
});
items=({
	"house","A beautiful house created out of oriental architecture",
	"wall","A stone wall about 12 feet high",
	"gate","A large, heavy gate made with iron bars",
	"gates","Large, heavy gates made with iron bars",
	"cobblestone","Well kept cobblestone with few cracks in it",
});
replace_program("room/room");
}
