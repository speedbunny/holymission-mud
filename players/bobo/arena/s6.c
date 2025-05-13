inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({
        1, 2, "peasant","players/bobo/monsters/peasant", 0,
        2, 2, "bob","players/bobo/monsters/peasant2", 0,
        3, 3, "slave","players/bobo/monsters/slave3", 0,
});
::reset (arg);
set_light (1);
short_desc="In the stands.";
long_desc=
"You are at the spectator exit of the colliseum.  People here\n"+
"are hurrying to get out the exit and away from something but\n"+
"they are all going so fast that they are jamming the exit and\n"+
"making it impossible for anyone to get out.\n";
dest_dir=({
        "players/bobo/arena/s5.c","southeast",
        "players/bobo/arena/s7.c","northwest",
});
items=({
        "exit","IT is thouroughly jammed and no of no use to anyone",
        "colliseum","The large building seems to be full of people who want to get out of it",
        "people","The people here look very frightened for som reason and are trying to flee",
});
replace_program("room/room");
}
