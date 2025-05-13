inherit "obj/treasure";

int get() { return ( 1 ); }
int drop( string str ) { return ( 1 ); }
string query_bard_line() { return ( bardline ); }
int set_bard_line( string str ) { bardline=str; }
int id( string str ) { return ( str=="lute" || str=="bardsoul" || str=="guildsoul" ); }

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
