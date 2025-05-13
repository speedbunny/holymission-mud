
/* set_wc changed to set_class....Was bugged  Gambit 103094 */
/* live stealer */

inherit "/obj/weapon";

void reset(int flag)
{
    if (flag == 0)
    {
	set_name("grey blade");
	set_alias("blade");
	set_short("A grey, blood covered blade");
	set_class(8);
	set_value(10000);
	set_hit_func(this_object());
	set_long( 
	  "This is the famous sword of life stealing.\n");
    }
}

int weapon_hit(object mob)
{
    int steal, align;

    align = this_player()->query_alignment();

    if (align > 0)
	steal = 40;      
    else if (align < - 10000)
    {
	steal = 1;
	call_out("dest_me",2);
    }
    else if (align < -1000)
	steal = 10;
    else if (align < -100)
	steal = 20;
    else 
	steal = 30;

    if (random(100) <= steal)
    {
	write("Your black blade sucks the life out of "+mob->query_name());
	write("\n");
	tell_object(mob,
	  "You feel a bone reaching into your chest.\n");
        mob->reduce_hit_point(steal);
	this_player()->heal_self(steal);
	this_player()->set_al(align - steal);
    }
    return (2 + random(steal/2));
}

void dest_me()
{
    write("You hear a voice saying: MUhaahaaaa MY MISSION IS FULFILLED\n");
    write("\nYour blade vanishes !\n\n");                                       
    this_player()->stop_wielding(this_object());
    destruct(this_object());
}

int do_unwield(string arg)
{

   if(interactive(this_player()) && this_player()->query_alignment() < -100 &&
      this_player()->query_wielded()==this_object())
    {
	write("The blade jumps back into your hand !\n");  
	return 1;
    }
    else 
	return ::do_unwield(arg);
}

int drop() 
{
    if (interactive(this_player()) && this_player()->query_alignment() < -100)
    {
	write("The gray blade jumps back in your inventory !\n");
	return 1;
    }
    else 
    {
	if (query_wielded())
	    this_player()->stop_wielding(this_object());
    }
    ::un_wield();
    ::drop();
    return 0;
}


get()
{

    if (present("grey blade",this_player()))
    {
	write("The gray blade suddenly jumps out of your inventory.\n");
	say(this_player()->query_name()+" drops a gray blade.\n",this_player());
	return 0;
    }
    return 1;
}
