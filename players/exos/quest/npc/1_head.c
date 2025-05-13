inherit "obj/monster";

void reset( int arg ) {
    ::reset( arg );
    if( arg ) 
	return;
    set_name( "hydra" );
    set_level( 7 );
    set_hp( 1000 );
    set_al( 0 );
    set_gender( 0 );
    set_race( "hydra" );
    set_short( "The Blue Hydra" );
    set_long( "\
This beast is quite large.  Its claws are long enough to cleave\n\
a wagon in two.  Its skin is an irridescent blue that sparkles in\n\
the limited light.  Its beady yellow eyes almost detract from the\n\
scimitar blades it calls teeth.  This must be the legendary Blue Hydra,\n\
the most powerful beast known to man or elf.\n" );
    /*
	set_dead_ob( this_object() );
    */
    set_prevent_poison( 1 );
    set_no_ears( 1 );
    set_number_of_arms( 1 );
    set_wc( 20 );
    set_ac( 25 );
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
    this_player() -> hit_player( random( 20 ) + 7 );
    return ( ::hit_player( dam ) );
}
