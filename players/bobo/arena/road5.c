inherit "room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="The road to the colliseum.";
long_desc=
"You are wandering down the road to the colliseum to watch the great\n"+
"battles that you heard about.  Oddly though this road doesn't have\n"+
"any other travelers though and you expected something a little\n"+
"more than just a dirt road leading to it.\n";
dest_dir=({
	"players/bobo/arena/road6.c","east",
	"players/bobo/arena/road4.c","west",
});
items=({
        "colliseum","To the north is the massive stone structure, it towers over you",
        "travelers","Oddly enough, there aren't any",
        "dirt road","This road is old and dilapidated, definitely not what you expected",
});
replace_program("room/room");
}
