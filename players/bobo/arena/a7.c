inherit "room/room";
reset(arg) {
if (arg) return;
clone_list=({
         1, 1, "gladiator","players/bobo/monsters/gladiator5", 0,
});
::reset(arg);
set_light(1);
short_desc="In the arena.";
long_desc=
"You are in the exact center of the arena.  This is an area where\n"+
"you can see all goings on clearly.  However this is where only the\n"+
"strongest can claim as their own.  As you peer around you can see\n"+
"other combatants, the crowd that inhabits the stands and the two\n"+
"people on the balcony north west of you.\n";
dest_dir=({
        "players/bobo/arena/a11.c","north",
        "players/bobo/arena/a8.c","east",
        "players/bobo/arena/a3.c","south",
        "players/bobo/arena/a6.c","west",
});
items=({
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
        "combatants","Man and beast alike fight to stay alive",
        "crowd","Vicious people here to see the spilling of blood",
        "stands","Big stone steps double as seats for the crowds",
        "people","Though you are unable to make out their features you can feel their greatness",
        "balcony","An ornate balcony with two people on it",
});
replace_program("room/room");
}
