inherit "room/room";
reset(arg) {
if (arg) 
return;
set_light(1);
short_desc="The Shadowhills";
long_desc=
("You are in the Shadowhills, evil lurks everywhere.\n"+
 "to the east you see some mountains.\n");
items=({
"hills","Dark hills with no living things",
"mountains","Some small mountains with an evil aura"
});
dest_dir=({
"/players/jewel/quest/hills/hill6","north",
"/players/jewel/quest/hills/hill2","west"
});
}
