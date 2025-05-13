inherit "room/room";
object lumberjack;
reset (arg) {
::reset (arg);
if (arg) return;
lumberjack = clone_object("players/bobo/monsters/lumberjack.c");
transfer(lumberjack,this_object());
lumberjack = clone_object("players/bobo/monsters/lumberjack.c");
transfer(lumberjack,this_object());
lumberjack = clone_object("players/bobo/monsters/lumberjack.c");
transfer(lumberjack,this_object());
set_light(1);
short_desc="Lumber processing camp.";
long_desc=
"You have come into the center of the small encampment where the\n"+
"lumberjacks sleep when they are not working.  There is als a processing\n"+
"plant and a few other buildings here.\n";
dest_dir=({
	"players/bobo/rooms/forrest/camp1.c","barracks",
	"players/bobo/rooms/forrest/camp2.c","shop",
	"players/bobo/rooms/forrest/camp3.c","plant",
	"players/bobo/rooms/forrest/camp4.c","bar",
	"players/bobo/rooms/forrest/32.c","leave",
});
items=({
	"plant","A large plant with billowing smoke pouring out the top.",
	"buildings","Besides the plant and barracks there is a bar and shop.",
	"barracks","A long narrow building.",
	"shop","A little quaint building set up to supply the lumberjacks.",
	"bar","A make-shift bar has sprung up here.",
});
}
