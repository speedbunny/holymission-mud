inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Dining room.\n";
long_desc=
"This is the elegant dining room. All the furniture here is Victorian.\n"+
"The table and chair are made from fine mahogany wood. The is a \n"+
"beautiful oriental rug under the table on the floor. Above you\n"+
"you can see a dazzling chandelier. In the northeast corner you \n"+
"see a hutch next to the east window and northern window\n";
items=({
"candles","There long red candles",
"hutch","The hutch contains beautiful silver, porcelain and crystal dinnerware",
"table","You see a floral arrangement with candles on either side",
"floral arrangement","There are an assortment of flowers here",
"window","Which window? North or east",
"north window","You see the backyard from this view",
"east window","You see the car port from this view",
"chandelier","It's made of solid brass with crystal trim",
"rug","Looks to be a hand made oriental rug",
"chairs","The chairs are made from fine mahogany wood",
"chair","The chair is made from fine mahogany wood",
"floor","It's made of all cedar wood with a rug under the table",
});
dest_dir=({
"players/warlord/house/kitchen","west",
"players/warlord/house/living_room","south",
});
}
init() {
::init();
add_action("light","light");
add_action("set","set");
add_action("sit","sit");
}
light(str) {
if (!str) {
write("What are you trying to light? The candles perhaps?\n");
return 1;
}
if ((str=="candles")||(str=="the candles")) {
write("You light both of the candles one at a time.\n It looks very romantic in here now.\n");
say(this_player()->query_name()+" lights the candles. Its looks romantic now.\n");
return 1;
}
else {
write("You can't light the "+str+" you will burn down the house.\n");
return 1;
}
}
set(str) {
if (!str) {
write("What do you want to set? The table perhaps ?\n");
return 1;
}
if ((str=="table")||(str=="the table")) {
write("You set the table with beautiful dinnerware.\n");
say(this_player()->query_name()+" sets the table.\n");
return 1;
}
else {
write("You can't set that.\n");
return 1;
}
}
sit(str) {
if(!str) {
write("Where do you want to sit?\n");
return 1;
}
if ((str=="on chair")||(str=="in chair")) {
write("You sit in a chair at the table.\n");
say(this_player()->query_name()+" sits in a chair.\n");
return 1;
}
else {
write("You can't sit there.\n");
return 1;
}}
