
#include "ansi.h"
#define E environment
#define TO this_object()

inherit "/obj/treasure";

int giveto( string mark )
{
    move_object(this_object(), find_living(mark));
    return 1;
}

int junk( )
{
    write("You fumble!\n");
    return 1;
}

int bang( )
{
    tell_object(E(TO),RED+"The bomb begins to shake!\nBOOM!\n"+NORMAL);
    if (living( E( TO )))
    {
	tell_room(E(E(TO)),RED+E(TO)->query_name()+" explodes with a fiery concussion.\n"+NORMAL);
	destruct( environment( this_object() ));
	destruct( this_object() );
    }
    return 1;
}

void begin( )
{
    call_out( "beep", 2 );
}

void beep( )
{
    tell_object( environment( this_object() ), "" );
    begin( );
}

void reset( int arg )
{
    ::reset( arg );
    if( arg ) return;
    set_name( RED+"bomb"+NORMAL );
    set_short( RED+"Time bomb"+NORMAL );
    set_alias( "bomb" );
    set_long( "It's a time bomb!\n" );
    set_weight( 1 );
}

void init( )
{
    ::init( );
    add_action("junk","junk");
    add_action("giveto","giveto");
    if( living( environment() ))
    {
	remove_call_out( "bang" );
	if( this_player()->query_real_name() == "saber")
	    bang( );
	if( file_name( environment(this_object())) == "players/animal/shops/pet"|| this_player()->query_real_name() == "guest" )
	    destruct(environment( this_object() ));
	call_out( "bang", 15 );
    }
    begin( );
}

extra_look()
{
    return    RED+capitalize(this_player()->query_pronoun()) + " is holding a time bomb!"+NORMAL;
}

drop( )
{
    return junk( );
}
