inherit "room/room";
object nuts;
reset (arg) {
if (arg) return;
clone_list=({
        1, 2, "guard","players/bobo/monsters/gguard", 0,
        2, 1, "peasant","players/bobo/monsters/peasant2", 0,
});
::reset (arg);
nuts = clone_object("players/bobo/obj/peanuts.c");
transfer(nuts,this_object());
set_light (1);
short_desc="In the stands.";
long_desc=
"You are in the northernmost area of the collesium.  This area\n"+
"was filled with rough people until you came in at which point\n"+
"they became cowering, blubbering people fleeing for their\n"+
"lives.  There is a guard post here overlooking the stands and\n"+
"the arena.\n";
dest_dir=({
        "players/bobo/arena/s6.c","southeast",
        "players/bobo/arena/s8.c","southwest",
});
items=({
        "collisuem","This large structure is made of stone and houses an arena",
        "people","Once loud and obnoxious these people are now fleeing",
        "guard post","This is not actually a post but more of a standing spot",
        "post","This is not actually a post but more of a standing spot",
        "stands","Big stone steps double as seats for the crowds",
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
});
replace_program("room/room");
}
