inherit "room/room";
reset(arg) {
if (arg) 
return;
set_light(1);
short_desc="The Shadowhills";
long_desc=
("You are at the northern point of the Shadowhills, to the northwest\n"+
 "you can see a dark castle.\n");
items=({
"castle","The dark castle of the Overlord",
"hills","Dark hills with no living things on them"
});
dest_dir=({
"/players/jewel/quest/hills/hill8","east",
"/players/jewel/quest/hills/hill5","south"
});
}
