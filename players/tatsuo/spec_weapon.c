// spec_weapon: Darastor 120298
// inheritable file for special ninja weapons - eg katana, wakizashi
// and ninja-to
// NOTE: set_security_function MUST be called in reset 0 before inherited
#define TP this_player()
// reset

#define OWNERS         "/players/patience/guild/nweap/weap_owners"

inherit "/players/patience/guild/nweap/ninja_weapon";

string security_function_name;

int security_check();

void set_security_function(string str)
{
    security_function_name = str;
}

void reset(int arg)
{
    ::reset(arg);
    if (!arg)
	security_check();
}

int security_check()
{
    if(security_function_name)
    {
	if (this_player())
	{
	    if (!(call_other(OWNERS, security_function_name,
			     this_player() -> query_real_name())) &&
		(this_player() -> query_player()))
	    {
		log_file("ninja_log",
			 this_player()->query_real_name() +
			 " " + query_name() + ": reset-security ("+
			 ctime(time())+")\n" );
		write( "Privilege violation !!!! LOGGED !\n" );
		destruct( this_object() );
	    }
	    else
		set_owner( this_player()->query_real_name() );
	}
	else
	{
	    log_file( "ninja_log",
		      query_name() + ": reset-security, no this_player()(" +
		      ctime(time())+")\n" );
	    destruct( this_object() );
	}
    }
}

int wield(string arg)
{
    if (!arg || !present(arg, this_player()))
	return(0);

    if (( this_player() -> query_player()) &&
     (TP->query_wielded()->query_owner() == TP->query_real_name()) )
    {
        write( "The " + query_name() + " refuses to be wielded by you !\n" );
	return(1);
    }

    return(::wield(arg));
}
