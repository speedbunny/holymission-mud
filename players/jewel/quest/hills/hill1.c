inherit "room/room";
reset(arg) {
if (arg) 
return;
set_light(1);
short_desc="The Shadowhills";
long_desc=
("You are in the Shadowhills, evil lurks everywhere.\n");
items=({
"hills","Dark hills with no living things on them"
});
dest_dir=({
"/players/jewel/quest/hills/hill4","north",
"/players/jewel/quest/hills/hill2","east",
"/players/jewel/quest/darkl9","south"
});
}
