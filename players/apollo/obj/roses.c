inherit"obj/treasure";
reset(arg) {
    if(arg) return;
    set_id("A dozen red roses");
    set_alias("roses");
    set_short("A dozen red roses");
    set_long("A set of a dozen freshly cut long stem red roses.\n" +
      "They are very beautiful and romantic, and give off\n" +
      "such a wonderful smell.\n");
    set_value(0);
    set_weight(0);
}
void init()
{
    ::init();
    add_action("smell","smell");
}
int smell (string str)
{
    if (str!= "roses")
    {
	notify_fail("Smell what ?\n");
	return 0;
    }
    write("You smell the freshness of the red roses.\n");
    say("HHmmmm ! "+this_player()->query_name()+" smells the red roses.\n");
    return 1;
}
