inherit "room/room";
reset(arg) {
if (arg) 
return;
set_light(1);
short_desc="The Shadowhills";
long_desc=
("You are now in a vally surrounded by the Shadowhills.\n");
items=({
"vally","A dark cold unfriendly vally",
"hills","Dark hills with no living things"
});
dest_dir=({
"/players/jewel/quest/hills/hill7","north",
"/players/jewel/quest/hills/hill6","east",
"/players/jewel/quest/hills/hill2","south",
"/players/jewel/quest/hills/hill4","west"
});
}
