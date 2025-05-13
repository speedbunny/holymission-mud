inherit "obj/monster";

void reset( int arg ) {
    ::reset( arg );
    if( arg ) 
	return;
    set_name( "hydra" );
    set_level( 30 );
    set_hp( 4000 );
    set_al( 0 );
    set_gender( 0 );
    set_race( "hydra" );
    set_short( "The Blue Hydra" );
    set_long( "\
This is unbelievable!  The hydra is back, and this time it has two\n\
identical heads!  Its two pair of eyes are locked on you, and its\n\
razor sharp teeth are foaming.  No wonder they call this the most\n\
powerful beast ever known!\n" );
    /*
	set_dead_ob( this_object() );
    */
    set_prevent_poison( 1 );
    set_no_ears( 1 );
    set_number_of_arms( 4 );
    set_wc( 45 );
    set_ac( 60 );
    set_size( 5 );
    set_aggressive( 1 );
    load_a_chat( 5, ( {
	    "The hydra howls in fury!\n",
	    "The hydra stamps its feet angrily.\n",
	    "The hydra bangs its tail off the walls.\n"
	} ) );
}

/*
monster_died(ob) {
if(this_player()->query_immortal()) return;
shout(this_player()->query_name()+" just killed the dreaded LAGBEAST!\n");
}
*/

int hit_player( int dam ) {
    int w, h;
    string *what, *how;

    what = ( { "left claw", "right claw", "tail", "horns" } );
    how = ( { "slashes at", "pounds", "massacres", "tears at", "crushes" } );
    w = random( 4 );
    h = random( 5 );
    printf( "The hydra %s you with its %s!\n", how[ h ], what[ w ] );
    say( "The hydra " + how[ h ] + " " + this_player() -> query_name() +
      " with its " + what[ w ] + "!\n", this_player() );
    this_player() -> hit_player( random( 45 ) + 30 );
    return ( ::hit_player( dam ) );
}
