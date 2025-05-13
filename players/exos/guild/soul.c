inherit "obj/treasure";
#include "mage.h"

object memorized, back;
string line;

int get() { return ( 1 ); }
int drop( string str ) { return ( 1 ); }
int id( string str ) { return( str == "robe" || str == "magesoul" ); }
void set_memorized( object where ) { memorized = where; }
object query_memorized() { return( memorized ); }
void set_back( object where ) { back = where; }
object query_back() { return( back ); }
void set_mage_line( string str ) { line = str; }
string query_mage_line() { return( line ); }

void reset( int arg ) {
    ::reset( arg );
    if ( !arg ) {
	set_name( "magetester" );
	set_alias( "tester" );
	set_short( "Exos's Mage Tester v1.0" );
	set_long( "This is to test new mage work.\n" );
	set_value( 0 );
	set_weight( 0 );
    }
}

void init() {
    ::init();
    add_action( "_cast", "cast" );
    add_action( "do_quit", "quit" );
    add_action( "_filter", "", 1 );
}

status _cast( string str ) {

    if( this_player()->query_ghost() ) {
	write( "That just is not possible...\n" );
	say( this_player()->query_name() + " stops casting.\n", this_player() );
	return ( 1 );
    }

    if( !str ) {
	write( "Cast which spell?\n" );
	return ( 1 );
    }
    if( find_call_out( "cast_spell" ) != -1 ) {
	write( "You are already casting a spell!\n" );
	return ( 1 );
    }
    write( "You begin casting.\n" );
    say( this_player()->query_name() + " begins casting a spell.\n" );
    call_out( "cast_spell", 1, str, query_verb() );
    return ( 1 );
}

status _filter( string str ) {
    string theverb;

    theverb = query_verb();    
    if( theverb[0] == 39 ) 
	return ( 0 );
    if( theverb == "quit" || theverb == "dest" )
	return ( 0 );
    if( theverb == "mage/" || theverb == "mage=" ) {
	( BIN + "mage" )->main( str );
	return ( 1 );
    }
    if ( file_size( BIN + theverb + ".c" ) > 0)
	if ( ( BIN + theverb + ".c" )->main(str) )
	    return ( 1 );
	else return ( 0 );
    return ( 0 );
}

int do_quit( string str ) {
    destruct( this_object() );
    return ( 0 );
}

status cast_spell( string str, string verb ) {
    string *spellname;
    string spell, arg, filename;
    int i;

    if( !str ) {
	write( "Cast which spell?\n" );
	return ( 1 );
    }
    if( sscanf( str, "%s at %s", spell, arg ) !=2 ) 
	spell=str;
    spellname = explode( spell, " " );
    i = 1;
    filename = spellname[0];
    while( i < sizeof( spellname ) ) {
	filename += "_" + spellname[i];
	i++;
    }
    if( file_size( SPELL + filename + ".c" ) <= 0 ) {
	write( "You do not know this spell.\n" );
	say( this_player()->query_name() + "'s spell fizzles.\n" );
	return ( 1 );
    }
    if( ( SPELL + filename + ".c" )->main( arg ) !=1 ) {
	write( "You fail to cast this spell!\n" );
	say( this_player()->query_name() + "'s spell fizzles.\n" );
	return ( 1 );
    }
    return ( 1 );
}
