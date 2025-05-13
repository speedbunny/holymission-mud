inherit "obj/treasure";

object sword;

void reset (int arg) {
    if (!arg) 
    {
	set_id("cauldron");
	short_desc=("A cauldron");
	long_desc=
	"This cauldron has a strange, green liquid in it. You think that this\n"+
	"substance would be greating at cleaning rusty weapons.\n";
	set_weight(100000);
	set_value(0);
    }
}

void init()
{
    ::init();
    add_action("clean","clean");
}

status clean (string arg) {
    if (!arg) { return write("Clean what?\n"),1; }
    if ((arg == "sword") || (arg == "rusty sword"))
    {
	if (!present("#rustysword#",this_player())) { notify_fail("You do not have that.\n"); }
	write("You dip the sword in the green liquid.\n");
	write("The sword glows in a green light and vanishes.\n");
	write("The cauldron shakes and moments later your hands glow blue.\n");
	write("A sword of light appears in your hands.\n");
	write("After several moments, the light vanishes leaving a beautiful sword behind.\n");
	say(capitalize(this_player()->query_name())+" dips the sword in the cauldron.\n");
	say("The sword glows in a green light and vanishes.\n");
	say("The cauldron shakes and moments later "+capitalize(this_player()->query_name())+"'s hands glow blue.\n");
	say("A sword of light appears in "+capitalize(this_player()->query_name())+"'s hands.\n");
	say("After several moments, the light vanishes leaving a beautiful sword behind.\n");
	command("bghtyu",this_player());
	return 1;
    }
    write("You don't think the cauldron is made to clean this.\n");
    return 1;
}
status get() { return 0; }
