inherit"obj/food";

reset(arg) {
    if(arg) return;
    set_name("cup");
    set_short("A Reese's Peanut Butter Cup");
    set_long("A peanut butter cup.  It is round and smells delicious!\n" +
      "You wonder how many ways there are to eat it!\n"); 
    set_value(0);
    set_weight(1);
    set_eater_mess("The chocolate and peanut butter melt in your mouth. " +
                    "Yummmmie.\n"); 
    set_strength(2);                                  
  
}
void init()
{
    ::init();
    add_action("smell","smell");
}
int smell (string str)
{
    if (str!= "cup")
    {
	notify_fail("Smell what ?\n");
	return 0;
    }
    write("You smell chocolate and peanut butter creation, your mouth waters.\n");
    say("Yummie! "+this_player()->query_name()+" smells the peanut butter cup.\n");
    return 1;
}
