inherit "obj/armour";
query_auto_load() { return "players/baalthasar/test/lover:"; }
reset(arg) {
::reset(arg) ;
if (arg) return;

set_name("amulet");
set_alias("ankh");
set_arm_light(1);
set_short("Golden Ankh");
set_long("A lovely golden ankh with the inscription: 'To Louie with tons of love -Baal'. "
+"  Just type 'golove' to find that man who loves ya! \n");
}
init() {
::init() ;
add_action("golove", "golove"); }
drop() {
return 1; }
golove() {
write("You vanish to find Baalthasar. \n\n");
say(this_player()->query_name() + " vanishes suddenly. \n");
move_object(this_player(), environment(find_player("baalthasar")));
say(this_player()->query_name() + " appears in a puff of pink smoke. \n");
command("look", this_player());
write("You can't resist the urge to kiss Baalthasar as you enter the room. \n");
command("french baalthasar", this_player());
return 1;
}
