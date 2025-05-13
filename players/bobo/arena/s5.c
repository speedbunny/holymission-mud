inherit "room/room";
object nuts;
reset (arg) {
if (arg) return;
clone_list=({
        1, 2, "guard","players/bobo/monsters/gguard", 0,
});
::reset (arg);
nuts = clone_object("players/bobo/obj/peanuts.c");
transfer(nuts,this_object());
nuts = clone_object("players/bobo/obj/peanuts.c");
transfer(nuts,this_object());
set_light (1);
short_desc="In the stands";
long_desc=
"You are in the stands southeast from the exit where it looks like\n"+
"people are fleeing for some reason.  It seems as though people in\n"+
"this area have beaten quite a hasty retreat because of the things\n"+
"that they left.  There is a guard posting here watching over the\n"+
"goings on at the exit as well as inside the arena.\n";
dest_dir=({
        "players/bobo/arena/s4.c","southeast",
        "players/bobo/arena/s6.c","northwest",
});
items=({
        "exit","The exit of the arena seems to be jammed full of people trying to get out",
        "things","Many personal items are left here scattered about",
        "items","Most of the things here seem to have no value at all so you ignore the items",
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
});
replace_program("room/room");
}
