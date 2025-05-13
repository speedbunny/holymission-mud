inherit"obj/treasure";
reset(arg) {
    if(arg) return;
	set_id("A long-stem white rose");
    set_alias("rose");
    set_short("A single white rose");
    set_long("A single white rose. It is exquisitely shaped and\n" +
	"created for you by Blaarg.\n");
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
    if (str!= "rose")
    {
	notify_fail("Smell what ?\n");
	return 0;
    }
    write("You are overwhelmed by the strong yet delicate fragrance\n" +
	  "of this beautiful white rose.\n");
    say("Ohhhhh! "+this_player()->query_name()+" smells the white rose.\n");

    return 1;
}
