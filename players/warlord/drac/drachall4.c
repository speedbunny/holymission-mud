inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Dungeon hallway";
long_desc="This hallway is filled with blood all over the place. The\n"+
         "light is hitting the north wall in a strange way.\n";
items=({
"wall","The wall looks really weird. Touch it",
"north wall","The wall looks really weird. Touch it",
"blood","The blood looks very fresh",
});
dest_dir=({
"players//warlord/drac/dracdun3","east",
"players//warlord/drac/dracdun4","west",
"players/warlord/drac/drachall1", "south",
});
return 1;
}
init () {
::init();
add_action("touch","touch");
}
touch(str) {
if (str=="the wall"||str=="wall") {
write("As you touch the wall you feel a strange force pulling you through.\n");
return !this_player()->move_player("through the wall#players/warlord/quest/dungeon/room1");
}
else {
write("Touch what?\n");
return 1;
}
return 1;
}
