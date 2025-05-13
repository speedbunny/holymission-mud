#define TP      this_player()

// beep.c - for beeping ninja wizards

status main(string arg)
{
    object obj;
    
    if ((arg != "darastor") && (arg != "warlord"))
    {
	    tell_object(TP,"Sorry, but you may only beep Warlord or " +
	      "Darastor.\nAnd this only for a good reason! (e.g. a bug "+
	      "or something like that).\n" );
	      
	    return 1;
    }

    obj = find_player(arg);
    if ( !obj )
    {
    	tell_object(TP,"Sorry, he is invis or not logged in.\n");
	    return 1;
    }

    tell_object(obj, "" );
    tell_object(obj, "---->" + TP->query_real_name(1) + " beeped you !\n");
    tell_object(TP,"You beeped " + capitalize(arg) + "!\n");

    return 1;
}

