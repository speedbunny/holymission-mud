inherit "room/room";
reset(arg) {
if (arg) 
return;
set_light(1);
short_desc="In front of a cave";
long_desc=
("You are in the Shadowlands. In front of you is a cave.\n");
items=({
"hills","Dark hills with no living things",
"skeletons","Some victims of the cave-monster",
"skeleton","A victim of the cave-monster",
"cave","A very big cave. Many skeletons are here, some are crumbled to\n"+
       "dust"
});
dest_dir=({
"/players/jewel/quest/hills/hill8","north",
"/players/jewel/quest/hills/hill3","south",
"/players/jewel/quest/hills/hill5","west"
});
}

init() {
  ::init();
  add_action("enter","enter");
}

enter(str) {
if(str!="cave") return;
this_player()->move_player("enter#players/jewel/quest/hills/cave1");
  return 1;
}

