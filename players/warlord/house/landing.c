inherit"room/room";
reset(arg) {
if (arg) return;
set_light(1);
short_desc="Landing.\n";
long_desc=
"This is the landing on the top of the stairs. To the west is a small\n"+
"hallway. In front of you is the linen closet. To the east looks to be\n"+
"the master bedroom.\n";
items=({
"linen closet","There are towels and sheets here",
"closet","There are towels and sheets here",
"sheets","These are bed sheets",
"towels","These are bath towels and beach towels here",
"beach towel","This towel is for the pool",
"bath towel","This towel is for the bathroom",
});
dest_dir=({
"players/warlord/house/hallway","west",
"players/warlord/house/master","east",
"players/warlord/house/stairs","down",
});
}
init() {
::init();
add_action("take","take");
}
take(str){
if(!str) {
write("Take what?\n");
return 1;
}
if((str=="beach towel")||(str=="bath towel")||(str=="sheets")) {
object ob;
ob=clone_object("obj/treasure");
ob->set_id(str);
ob->set_short(capitalize(str));
ob->set_long("Simple "+str+".\n");
ob->set_weight(1);
ob->set_value(0);
move_object(ob,this_player());
write("You take "+str+" from the closet.\n");
say(this_player()->query_name()+" takes "+str+" from the closet.\n");
return 1;
}
else {
write("There are no "+str+" in the closet.\n");
return 1;
}}
