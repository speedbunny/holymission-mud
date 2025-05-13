inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="In the arena.";
long_desc=
"You are in the far western portion of the arena, an area of which seems\n"+
"to be deserted at the moment of any other combatants.  However over the\n"+
"wall you can hear yelling coming from unseen spectators in the stands\n"+
"above.\n";
dest_dir=({
        "players/bobo/arena/a6.c","east",
});
items=({
        "combatants","You seem to have escaped from them for now",
        "wall","The wall is sheer and definitely unclimbable",
        "spectators","You cannot see these people but it is obvious that they lust for blood",
        "stands","Big stone steps double as seats for the crowds",
});
replace_program("room/room");
}
