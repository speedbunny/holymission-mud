inherit "room/room";
reset(arg) {
if (arg) 
return;
set_light(1);
short_desc="The Shadowhills";
long_desc=
("You are in the Shadowhills, evil lurks everywhere.\n");
items=({
"hills","Dark hills with no living things"
});
dest_dir=({
"/players/jewel/quest/hills/hill5","east",
"/players/jewel/quest/hills/hill1","south"
});
}
