inherit "room/room";
reset(arg) {
if (arg) return;
set_light(3);
short_desc = "c4";
long_desc = 
"You have reached the corner of the castle.\n"
+ "The hall continues to the north, and a small doorway to your south.\n"
+ "The black carpet stops here, but a blue one picks up heading north.\n";
items = ({
"floor","It is made of the same ruby red stones as all the others",
"ceiling","It is made of white stone, but it has a picture of a naked goblin woman on it",
"woman","A picture of a naked goblin woman with large breasts on the ceiling",
"wall","Grey stone walls",
"window","All you can see is trees that surround the castle",
"carpet","The black carpet comes to an end here.\nA blue one extends north",
});
dest_dir = ({
"players/jake/goblin/castle/c3","west",
"players/jake/goblin/castle/c4a","southeast",
"players/jake/goblin/castle/c5","north",
});
}
