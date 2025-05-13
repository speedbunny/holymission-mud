inherit"obj/treasure";
reset(arg) {
    if(arg) return;
    set_id("A single red rose");
    set_alias("rose");
    set_short("A single red rose");
    set_long("A single red rose.  It is perfectly formed and\n" +
      "created especially for you by Misticalla.\n"); 
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
    write("You smell the fragrance of this single red rose.\n");
    say("Ahhhhh! "+this_player()->query_name()+" smells the red rose.\n");
    return 1;
}
