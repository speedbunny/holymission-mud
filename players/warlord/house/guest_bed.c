inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Guest bedroom.\n";
long_desc=
"This is the guest bedroom for any overnight guests they have.\n"+
"The room is moderately furnished with a cozy bed and a nice dresser.\n"+
"Next to the bed is a night stand and on the west wall is a closet.\n";
items=({
"drawers","Small drawers. Try opening one.",
"hangers","Simple looking clothes hangers",
"closet","This is an ordinary closet with a few hangers in it",
"bed","A cozy double bed",
"dresser","A wooden 3 drawer dresser",
"night stand","A little night stand for trinkes to be placed on",
});
dest_dir=({
"players/warlord/house/hallway","north",
});
}
init() {
::init();
add_action("open","open");
add_action("lay","lay");
add_action("sit","sit");
}
open(str) {
if(!str) {
write("Open what?\n");
return 1;
}
if((str=="drawer")||(str=="top drawer")||(str=="middle drawer")||(str=="bottom drawer")) {
write("You open the "+str+" and find it empty.\n");
return 1;
}
else {
write("You can't open that.\n");
return 1;
}}
sit(str) {
if(!str) {
write("You want to sit where?\n");
return 1;
}
if((str=="on bed")||(str=="on the bed")) {
write("You sit on the bed.\n");
say(this_player()->query_name()+" sits on the bed.\n");
return 1;
}
else {
write("You can't sit there.\n");
return 1;
}}
lay(str) {
if (!str) {
write("You want to lay where?\n");
return 1;
}
if((str=="on bed")||(str=="on the bed")||(str=="in bed")||(str=="in the bed")) {
write("You lay on the bed. It feels very comfortable.\n");
say(this_player()->query_name()+" lays on the bed.\n");
return 1;
}
else {
write("You can't lay there it's too dirty.\n");
return 1;
}}
