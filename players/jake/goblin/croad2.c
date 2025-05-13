inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "croad2";
long_desc = "The path proceeds north towards the castle.\n"
+ "A wall of trees to the west denies passage.\n"
+ "You can see a small clearing to the east.\n";
items = ({
"trees","A cluster of evergreen trees",
});
dest_dir = 
({ "players/jake/goblin/croad1","south",
"players/jake/goblin/clear","east",
"players/jake/goblin/croad3","north",
});
}
