inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Study.\n";
long_desc=
"This is Christian's study. He does all thinking here.\n"+
"As you look around the room you can see a lot of nice furniture.\n"+
"There is a huge bookcase on the north wall to the right of the \n"+
"window. In the corner is a computer desk. On the south wall is a\n"+
"couch.\n";
items=({
"couch","This looks to be a comfy couch",
"bookcase","This bookcase houses all of Christian's books and his stereo",
"stereo","This is the state of the art model. You see tapes near it",
"tapes","The only tape you see is Erotica",
"window","From this window you get a nice view of the backyard",
"erotica","This tape has two songs:Side 1- Where life begins Side 2- Rain",
"computer","This is an IBM 486DX/50MHz computer with a big screen",
"screen",
"_________________________________________________________\n"+
"|                                                       |\n"+
"|                                                       |\n"+
"|                                                       |\n"+
"|                                                       |\n"+
"|                     Skyler                            |\n"+
"|                                                       |\n"+
"|                       Is a                            |\n"+
"|                                                       |\n"+
"|                         Great lover                   |\n"+
"|                                                       |\n"+
"|                                                       |\n"+
"|                                                       |\n"+
"|                                                       |\n"+
"---------------------------------------------------------\n\n",
});
dest_dir=({
"players/warlord/house/hallway","east",
});
}
init() {
::init();
add_action("sit","sit");
}
sit(str) {
if (str=="on couch") {
write("You sit on the couch.\n");
say(this_player()->query_name()+" sits on the couch.\n");
return 1;
}
}
