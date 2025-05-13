inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Living room.\n";
long_desc=
"This is the elegant living room. The room is furnished in colonial furniture.\n"+
"To the east is a well made fireplace. To the south you see an \n"+
"antique looking couch. To the north you see a doorway leading to \n"+
"the dining room with a large bookcase to the right of it. To the\n"+
"west is the foyer.\n";
items=({
"couch","An antique looking couch. Sit on it",
"fire","You see a beautiful romantic fire burning",
"doorway","There are french doors here leading to the dining room",
"fireplace","A beautifully made fireplace with a marble mantle",
"mantle","The mantle is made of solid marble and has an antique clock and a picture on it",
"clock","This is an ancient clock from England",
"floor","The floor is made of solid cedar wood",
"bookcase","This is a rather large bookcase that houses many books",
"picture","This is the wedding picture of Skyler and Christian",
});
dest_dir=({
"players/warlord/house/foyer","west",
"players/warlord/house/dining_room","north",
});
}
init() {
::init();
add_action("sit","sit");
add_action("imag","imagine");
add_action("light","light");
add_action("take","take");
}
sit(str) {
if (!str) {
write("Sit where?\n");
return 1;
}
if((str=="on the couch") || (str=="on couch")) {
write("You sit comfortably on the couch.\n");
say(this_player()->query_name()+" sits on the couch.\n");
return 1;
}
if((str=="on the floor") ||(str=="on floor")) {
write("You sit on the floor.\n");
say(this_player()->query_name()+" sits on the floor.\n");
return 1;
}
else {
write("You can't sit  "+str+"\n");
return 1;
}
}
light(str) {
if (!str) {
write("Light what?\n");
return 1;
}
if ((str=="the fireplace") || (str=="fireplace")) {
write("You light the fireplace. It starts to feel nice and warm.\n");
say (this_player()->query_name()+" lights the fireplace. Its feels warm in here.\n");
return 1;
}
else {
write("You can't light that. It will cause the house to burn down.\n");
return 1;
}
}
imag(str) {
if(!str) {
write("What do you want to imagine?\n");
return 1;
}
write(capitalize(str)+".\n");
return 1;
}
