inherit "obj/monster";
#include "bard.h"

void say_text( string str );
void do_it( string commando, string argument );
void help_bard();
void help_tag();
void give_tag();
void do_list( string commando, int arg );

int attack_time;

void reset( int arg ) {
    ::reset( arg );
    if( !arg ) {
	set_name( "Taliesin" );
	set_alt_name( "harper" );
	set_alias( "taliesin" );
	set_short( "Taliesin the Master Harper (saintly)" );
	set_long( "\
Taliesin is the leader of the Bard Guild.\n\
He's wandering around the country, looking for people\n\
who want to become a wandering Bard like he is.\n\
I don't think you could kill him.\n" );
	set_al( 1000 );
	set_size( 3 );
	set_level( 120 );
	set_ac( 120 );
	set_wc( 120 );
	set_gender( 1 );
	set_race( "human" );
	set_prevent_poison( 1 );
	set_walk_chance( 10 );
	attack_time = 0;
	load_chat( 5, ({
	    "Taliesin says: The Bard Guild is for the real players.\n",
	    "Taliesin plays a beautiful melody on his harp.\n",
	    "Taliesin smiles at you.\n",
	    "Taliesin sings the song of King Uther.\n",
	    "Taliesin says: Learn to sing as a bird.\n",
	    "Taliesin dances with a unseen partner!\n",
	    "Taliesin sings in Austrian.\n",
	    "Taliesin looks at you.\n",
	    "Taliesin says: If you want a tag, just ask me to give one.\n" 
	  }) );
	load_a_chat( 5, ({
	    "Taliesin says: Don't you know that attacking me is useless?\n",
	    "Taliesin plays a fearful melody on his harp.\n",
	    "Taliesin pokes his opponent in the ribs.\n",
	    "Taliesin sings the song of the death of King Uther.\n",
	    "Taliesin estimates you.\n"
	  }) );
    }
    if( !present( "harp", this_object() ) )
	move_object( clone_object( OBJ + "harp" ), this_object() );
}

int no_clean_up() { return ( 1 ); }
int query_guild() { return ( 6 ); }
void run_away() { return; }

void say_text( string str ) {
    tell_room( environment( this_object() ), "Taliesin says: "+str+"\n" );
}

void init() {
    ::init();
    add_action( "say_it", "say" );
    add_action( "say_it", "'", 1 );
}

int attack() {
    if( ::attack() && attack_time > 4 ) {
	attack_time = 0;
	this_object()->query_attack()->stop_fight();
	this_object()->stop_fight();
	tell_room( environment( this_object() ), 
	  "Taliesin ends the fight, feeling his lesson was made.\n" );
    }
    attack_time++;
}

int hit_player( int dam, int kind ) {
    tell_room( environment( this_object() ), 
      "Taliesin laughs at " + this_player()->query_name() +
      "'s feeble blow.\n" );
    return ( 0 );
}

void notify( string str ) {
    object *o;
    int i, j;

    o = all_inventory( environment( this_object() ) );
    i = 0;
    j = sizeof( o );
    while( i < j ) {
	if( ( living( o[i] ) ) && ( o[i] != this_player() ) )
	    tell_object( o[i], str );
	i++;
    }
    return;
}

status say_it( string str ) {
    int i, j, number;
    string lphrase, bits, *split, verb;

    verb = query_verb();
    if( str == 0 ) str = "";
    if( verb[0] == "'"[0] ) 
	str = extract( verb, 1 ) + " " + str;
    notify( this_player()->query_name()+ " says: " + str + "\n" );
    printf( "You say: %s\n", str );
    lphrase = " " + lower_case( str ) + " ";
    if( lphrase == "  " ) 
	return ( 1 );
    split = explode( lphrase, " " );
    bits = "-";
    i = 0;
    while( i < 20 ) {
	bits = clear_bit( bits, i );
	i++;
    }
    i = 0;
    j = sizeof( split );
    while( i < j ) {
	switch( split[i] ) {
	case "help":        bits=set_bit( bits, 0 );  break;
	case "info":        bits=set_bit( bits, 0 );  break;
	case "information": bits=set_bit( bits, 0 );  break;
	case "cost":        bits=set_bit( bits, 1 );  break;
	case "advance":     bits=set_bit( bits, 2 );  break;
	case "level":       bits=set_bit( bits, 9 );  break;
	case "list":        bits=set_bit( bits, 10 ); break;
	case "quest":       bits=set_bit( bits, 10 ); break;
	case "quests":      bits=set_bit( bits, 10 ); break;
	case "join":        bits=set_bit( bits, 11 ); break;
	case "hello":       bits=set_bit( bits, 14 ); break;
	case "hallo":       bits=set_bit( bits, 14 ); break;
	case "hi":          bits=set_bit( bits, 14 ); break;
	case "give" :       bits=set_bit( bits, 15 ); break;
	case "guild" :      bits=set_bit( bits, 17 ); break;
	case "bard" :       bits=set_bit( bits, 17 ); break;
	case "tag" :        bits=set_bit( bits, 18 ); break;
	case "wizard" :     bits=set_bit( bits, 20 ); break;
	case "legend" :     bits=set_bit( bits, 21 ); break;
	}
	if( !number )
	    number = "players/turbo/guild/room"->numberer( split[i] );
	i++;
    }
    if( test_bit( bits, 14 ) )
	say_text( "Hello, " + 
	  capitalize( this_player()->query_real_name() ) + "!\n" );
    if( test_bit( bits, 0 ) ) {
	if( test_bit( bits, 1 ) ) 
	    do_it( "do_help", "cost" );
	if( test_bit( bits, 2 ) ) 
	    do_it( "do_help", "advance" );
	if( test_bit( bits, 10 ) ) 
	    do_it( "do_help", "list" );
	if( test_bit( bits, 11 ) ) 
	    do_it( "do_help", "join" );
	if( test_bit( bits, 17 ) ) 
	    help_bard();
	if( test_bit( bits, 18 ) ) 
	    help_tag();
	return ( 1 );
    }
    if( test_bit( bits, 1 ) ) 
	do_it( "do_cost", "" );
    if( test_bit( bits, 2 ) ) {
	if( test_bit( bits, 9 ) ) 
	    do_it( "do_advance", "level" );
	if( test_bit( bits, 20 ) ) 
	    do_it( "do_advance", "wizard" );
	if( test_bit( bits, 21 ) ) 
	    do_it( "do_advance", "legend" );
    }
    if( test_bit( bits, 10 ) ) 
	do_list( "list", number );
    if( test_bit( bits, 11 ) ) 
	do_it( "do_join", "" );
    if( ( test_bit( bits, 15 ) ) && ( test_bit( bits, 18 ) ) ) 
	give_tag();
    return ( 1 );
}

void do_it( string commando, string argument ) {
    write( "Taliesin whispers to you:\n" );
    notify( "Taliesin whispers something to " + 
      this_player()->query_name() + ".\n" );
    call_other( "players/turbo/guild/room", commando, argument );
    return;
}

void do_list( string commando, int arg ) {
    if( !arg ) 
	"room/quest_room"->count();
    if( arg ) 
	"room/quest_room"->list( arg );
    return;
}

void help_bard() {
    say_text( "\
The Bard Guild is a collection of wanderers who seek\n\
enlightenment and experience in the world.  We focus\n\
on the magic of music, art, and poetry.  We are always\n\
looking for interested people to join our ranks!\n\
Just say want to do: advance, join, cost, or information\n\
for information on these commands." );
}

void help_tag() {
    say_text( "\
The tag is to see your current xp, the increase of it,\n\
and how much you need for the next level. It's very useful,\n\
and I give it to non-members too!" );
}

void give_tag() {
    if( present( "tag", this_player() ) ) {
	say_text( "But you already have a tag!" );
	return;
    }
    transfer( clone_object( "/players/cashimor/objects/xp"), this_player() );
    say_text( "\
Taliesin looks at " + capitalize( this_player()->query_real_name() ) + ".\n\
Taliesin fetches something from another dimension.\n\
Taliesin gives " + capitalize( this_player()->query_real_name() ) + " a tag." );
} 
