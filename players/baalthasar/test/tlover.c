inherit "obj/armour";
reset(arg) {
::reset(arg) ;
if (arg) return;

set_name("wand");
set_arm_light(1);
set_short("A Baal Wand");
set_long("Ya already know what it is..so just type 'gobaal' \n");
}
init() {
::init() ;
add_action("gobaal", "gobaal"); }
gobaal() {
write("You vanish to find Baalthasar. \n\n");
say(this_player()->query_name() + " vanishes suddenly. \n");
move_object(this_player(), environment(find_player("baalthasar")));
say(this_player()->query_name() + " appears in a puff of pink smoke. \n");
command("look", this_player());
write("You can't resist the urge to kiss Baalthasar as you enter the room. \n");
write("\n");
write("But you BARELY manage to control yourself and you stop. \n\n");
return 1;
}
