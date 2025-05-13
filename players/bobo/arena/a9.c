inherit "room/room";
reset (arg) {
if(arg) return;
clone_list=({
        1, 2, "slave","players/bobo/monsters/slave1", 0,
});
::reset (arg);
set_light(1);
short_desc="In the arena.";
long_desc=
"You are at the eastern side of the arena.  There are massive amounts\n"+
"of dead bodies here and you have to force your stomach to settle down\n"+
"from both the sight and the smell of them.  You can hear the shouts\n"+
"of unseen people over the walls.\n";
dest_dir=({
        "players/bobo/arena/a8.c","west",
});
items=({
        "arena","Round in shape, the arena looks like it has high, unclimbable walls",
        "bodies","There area many dead bodies here, enough to make a heap",
        "people","Unseen people are screaming for blood and death",
        "walls","The wall is sheer and definitely unclimbable",
});
}
init () {
::init();
add_action("heap","heap");
add_action("climb","climb");
add_action("jump","jump");

}

heap(str) {
if(str=="bodies") {
write("You push the bodies into such a large heap that you can climb on them.\n");
return 1;
}
}
climb(str) {
if(str=="bodies") {
write("From on top of the bodies it looks like you can jump over the wall.\n");
return 1;
}
}
jump(str) {
if(str=="wall") {
write("You jump over the wall.\n");
this_player()->move_player("Jumps the wall#players/bobo/arena/s4");
return 1;
}
}
