#define TP      this_player()

status main(string str)
{
    string path;

    if ( !str )
	    return 0;

    if(sizeof(explode(str, " ")) == 1)
    {
	    if (str == "spell")
	        str = "spells";
	    else if ( str == "class" )
	    {
	        tell_object(TP,"The class-system has been removed !\n" );
	        return 1;
	    }

	    path = "/players/tatsuo/guild/helpdir/"+str;
	    if (file_size(path) > 0 )
	    {
	        TP->more(path);
	        return 1;
	    }
    }

    return 0;
}
