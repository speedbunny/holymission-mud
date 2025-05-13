inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({
        1, 1, "caesar","players/bobo/monsters/caesar", 0,
});
::reset (arg);
set_light (1);
short_desc="On the balcony.";
long_desc=
"You are on the balcony near the steps leading back to the stands\n"+
"looking around you can see the whole collesium, including all of\n"+
"the stands, all of the arena, and the area surrounding the\n"+
"collesium.  The balcony itself is very nicely furnished with\n"+
"a floor you can see through somehow, and a gold plated railing\n";
dest_dir=({
        "players/bobo/arena/b1.c","southwest",
});
items=({
        "balcony","This peice of architewcture is beautifully done",
        "stands","You can see every part of the stands from here including the space below you",
        "collesium","You can see the whole collesium from way up here",
        "arena","In the arena the fights still rage",
         "area","You can see over the walls of the collesium to the surrounding area",
        "floor","Though it's darker than normal you can still see the area under the balcony",
        "railing","The railing is gold plated and very fancy",
});
replace_program("room/room");
}
