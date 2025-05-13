inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({
        1, 1, "boy","players/bobo/monsters/boy", 0,
});
::reset (arg);
set_light (1);
short_desc="In the stands.";
long_desc=
"This portion of the stands is competely vacant and looks very\n"+
"run down.  For some reason the stone all around here is cracked\n"+
"and worn.  The normally high, strong walls are in shambles and\n"+
"large peices of rubble lie next to the wall.  There is a lot of\n"+
"garbage in this area.\n";
dest_dir=({
        "players/bobo/arena/s12.c","southeast",
        "players/bobo/arena/s10.c","northwest",
});
items=({
        "stands","Generally pretty well kept this portion seems to have fallen into disrepair"
        "stone","Normally free of cracks, there are large ones in this area",
        "wall","The barrier to keep people from jumping doesn't seem like much of a barrier",
        "garbage","Refuse carpets this area",
});
replace_program("room/room");
}
