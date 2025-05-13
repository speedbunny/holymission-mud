inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({ 
         1, 2, "tiger","players/bobo/monsters/tiger", 0,
         2, 1, "slave","players/bobo/monsters/slave", 0,
});
::reset(arg);
set_light(1);
short_desc="Inside the arena.";
long_desc=
"You are at the south western edge of the arena.  The wall here is\n"+
"covered in something that looks to be intestines.  It also blocks\n"+
"your view of the stands above you though you can make out the\n"+
"balcony to the northwest of you.\n";
dest_dir=({
        "players/bobo/arena/a6.c","north",
        "players/bobo/arena/a3.c","east",
});
items=({
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
        "wall","There are intestines stuck to the wall, you feel like puking",
        "instestines","You are usure wether they are human or not",
        "stands","Big stone steps doule as seats for the crowds",
        "balcony","You can just make out two figures watching over everything on it",
});
replace_program("room/room");
}
