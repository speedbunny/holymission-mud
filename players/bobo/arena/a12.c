inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({
        1, 1, "slave","players/bobo/monsters/slave1", 0,
        2, 1, "bear","players/bobo/monsters/bear", 0,
});
::reset (arg);
set_light (1);
short_desc="In the arena.";
long_desc=
"You are at the north eastern part of the arena.  Here the regular\n"+
"gore of the arena is magnified by some of the over zealous members\n"+
"of the crowd leaning to far over the wall and then falling in only\n"+
"to be torn to shreds by animals in the arena.  Other members of\n"+
"crowd are now standing a bit farther away from the wall.  To the\n"+
"north west of you you can barely make out the balcony.\n";
dest_dir=({
        "players/bobo/arena/a8.c","south",
        "players/bobo/arena/a11.c","west",
});
items=({
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
        "gore","Blood is splattered and caked on all parts of this section of the arena",
        "crowd","Loud and obnoxious, some of them were a little too close to the action",
        "members","The rest of the crowd is standing far away from the edge of the wall",
        "wall","The wall is sheer and definitely unclimbable",
        "balcony","You can see the balcony and two figures in it but not their faces",
});
replace_program("room/room");
}
