/* ------------------------ secret ninja handshake ------------------------ */
// Originally by Patience
// Darastor 131197: Moved the function out into the bin system, made a few
//                  English improvements. Used query_real_name(1) instead of
//                  capitalize(x -> query_real_name())

status main(string arg)
{
    object mob;

    notify_fail("Nshake who or what?\n");
    if(!arg)
	return 0;

    mob = present(arg,environment(this_player()) );

    if (mob && interactive(mob))
    {
    	if (mob->query_guild()==this_player()->query_guild())
    	{
    	    tell_object(mob,"Ninja "+ this_player() -> query_real_name(1) +
    	      " gives you a secret Ninja handshake.\n");
    	    tell_object(this_player(),"You give "+ mob->query_real_name(1) +
    	      " a secret Ninja handshake.\n");
    	}
    	else
    	    tell_object(this_player(),"This person isn't a member of your " +
    	      "great guild.\n");
    	return 1;
    }
    return 0;
}

