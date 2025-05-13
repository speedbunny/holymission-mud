inherit "room/room"; 
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "croad";
long_desc = 
"You are on the road to the goblin castle.\n"
+ "You get an eerie feeling about this place.\n"
+ "There are poles in the ground with bodies of past opponents on them.\n"
+ "The castle is north of you.\n";
items = ({
"poles","Large wooden poles with bodies of orcs, humanas, and various\nothercriteria placed on them for display purposes"});
dest_dir = ({
"players/jake/goblin/croad1","north",
"players/jake/goblin/gob5","south",
});
}
