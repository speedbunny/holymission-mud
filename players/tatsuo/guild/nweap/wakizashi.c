#define TP             (this_player())
#define OWNERS         "/players/tatsuo/guild/nweap/weap_owners"

inherit "/players/tatsuo/guild/nweap/genNinWeap";

#include "/players/tatsuo/guild/nweap/nweap_mess.h"

query_auto_load() { return "players/tatsuo/guild/nweap/wakizashi:"; }

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    set_name( "wakizashi" );
    set_short( "A wakizashi" );
    set_long(
      "A wakizashi is a medium, slighty curved, sword. It is a nina weapon.\n"+
      "The wakizashi looks very sharp.\n" );
    set_class( 18 );
    set_value( 0 );
    set_weight( 6 );

    hit_fact = 5;
    monst_hit_fact = 5;
    needed_lvl_fst = 22;
    needed_lvl_sec = 26;
    raise_block = 90;

}
/*

int security_check()
{
    if ( this_player() ) {
	if ( !(OWNERS->is_waki_owner(this_player()->query_real_name())) &&
	  this_player()->query_player() )
	{
	    log_file( "ninja_log",
	      this_player()->query_real_name() + " waki: reset-security ("+
	      ctime(time())+")\n" );
	    write( "Privilege violation !!!! LOGGED !\n" );
	    destruct( this_object() );
	}
	else
	    set_owner( this_player()->query_real_name() );
    }
    else {
	log_file( "ninja_log",
	  "waki: reset-security, no this_player() ("+ ctime(time())+")\n" );
	destruct( this_object() );
    }
}

int wield( string arg )
{
    if(this_player()->query_real_name()=="warlord")  
	return( ::wield( arg ) );
    if ( !arg || !present( arg, this_player() ) ) return( 0 );

    if ( TP->query_player() && !(OWNERS->is_waki_owner(TP->query_real_name())) )
    {
	write( "The wakizashi refuses to be wielded by you !\n" );
	return( 1 );
    }

    return( ::wield( arg ) );
}
*/
drop(){
tell_object(this_player(),"You do not desire to drop your wakizashi.\n");
return 1;
}
