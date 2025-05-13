inherit "obj/treasure";
#include "bard.h"
#include "/players/turbo/guild/levels.h"
#include "/players/turbo/guild/bin/sing.h" //Too much timing in the singing functions to have as seperate object - Exos/* Bard Soul Mk2.1 September 29 */
int guild, prowess;
string bardline;

int get() { return ( 1 ); }
int drop( string str ) { return ( 1 ); }
string query_bard_line() { return ( bardline ); }
int set_bard_line( string str ) { bardline=str; }
int id( string str ) { return ( str=="lute" || str=="bardsoul" || str=="guildsoul" ); }
int query_prowess() { return ( prowess ); }
void ok_prowess() { prowess = 0; }

void set_prowess() { 
    prowess = 1;
    call_out( "ok_prowess", 2 );
}

void reset( int arg ) {
    ::reset( arg );
    if ( !arg ) {
	set_name( "lute" );
	set_alias( "guildsoul" );
	set_short( "A well-crafted Lute" );
	set_long(" This is your gift from Taliesin.  Your lute is your most\n\
	  prized possession.  It also lets you perform your bardic\n\
	  magic.  The symbol of The Harpers is on the back.\n" );
	set_value( 0 );
	set_weight( 0 );
	guild = GM->query_number( "bard" );
    }
}

void init() {
    ::init();
    set_bard_line( "On" );
    add_action( "_cast", "cast" );
    add_action( "_cast", "summon" );
    add_action( "do_quit", "quit" );
    add_action( "_filter", "", 1 );
    if( !this_player()->query_immortal() && !this_player()->query_invis() )
	CD->do_chat( guild, "<*> " + capitalize( this_player()->query_real_name() ) + 
	  " wanders back into our land. <*>\n" );
    if( !this_player()->query_immortal() ) {
	this_player()->setmin( "enters strumming " + this_player()->query_possessive() + " lute" );
	this_player()->setmout( "strums " + this_player()->query_possessive() + " lute, as " +
	  this_player()->query_pronoun() + " strolls" );
    }
}

status _cast( string str ) {

    CHK_GHOST();
    if( !str ) {
	write( "Cast which spell?\n" );
	return ( 1 );
    }
    if( find_call_out( "cast_spell" ) != -1 ) {
	write( "You are already casting a spell!\n" );
	return ( 1 );
    }
    write( "You begin to perform...\n" );
    say( this_player()->query_name() + " begins a performance...\n" );
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
    if( theverb == "bard/" || theverb == "bard=" ) {
	( BIN + "bard" )->main( str );
	return ( 1 );
    }
    if ( file_size( BIN + theverb + ".c" ) > 0)
	if ( ( BIN + theverb + ".c" )->main(str) )
	    return ( 1 );
	else return ( 0 );
    return ( 0 );
}

int do_quit( string str ) {
    if( !this_player()->query_immortal() && !this_player()->query_invis() )
	CD->do_chat(guild, "<*> " + capitalize( this_player()->query_real_name() ) + 
	  " wanders off to new lands. <*>\n" );
    destruct( this_object() );
    return ( 0 );
}

void guild_changes() {
    if( !this_player()->query_immortal() )
	CD->do_chat( guild, "<*> " + capitalize( this_player()->query_real_name() ) +
	  " abandons " + this_player()->query_possessive() + " Harper brethren! <*>\n" );
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
    if( verb == "summon" ) {
	if( file_size( SUMMON + filename + ".c" ) <= 0 ) {
	    write( "There is no such orb!\n" );
	    return ( 1 );
	}
	if( ( SUMMON + filename + ".c" )->main( arg ) !=1 ) {
	    write( "You fail to summon the orb!\n" );
	    return ( 1 );
	}
	return ( 1 );
    }
    if( file_size( SPELL + filename + ".c" ) <= 0 ) {
	write( "You do not know this spell.\n" );
	return ( 1 );
    }
    if( ( SPELL + filename + ".c" )->main( arg ) !=1 ) {
	write( "You fail to cast this spell!\n" );
	return ( 1 );
    }
    return ( 1 );
}
