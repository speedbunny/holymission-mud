inherit "/obj/std_shadow";

status wander( object ob );
status runaway( object ob );
status do_attack( object ob );
status do_peace( object ob );

varargs int start_shadow( object ob, int time ) {
    tell_object( ob, "You feel CHAOS taking over your soul!\n" );
    call_out( "confuse_em", 5 + random( 20 ), ob );
    return ::start_shadow( ob, time, "confusion", 0 );
}

void confuse_em( object ob ) {
    tell_room( environment( ob ), ob->query_name() + " looks a little insane.\n" );
    tell_object( ob, "You feel a little insane.\n" );
    switch( random( 10 ) ) {
    case 0..2: wander( ob );    break;
    case 3..5: runaway( ob );   break;
    case 6..7: do_attack( ob ); break;
    case 8..9: do_peace( ob );  break;
    default:
    }
    call_out( "confuse_em", 5 + random( 20 ), ob );
}

void end_shadow( object ob ) {
    if( !random( 15 ) ) {
	tell_object( ob, "You regain your sanity.\n" );
	tell_room( environment( ob ), ob->query_name() + " looks a bit more sane.\n" );
	if( find_call_out( "confuse_em" ) ) 
	    remove_call_out( "confuse_em" );
	::end_shadow( ob );
    }
}

status wander( object ob ) {
    ob->random_move();
    return ( 1 );
}

status runaway( object ob ) {
    ob->run_away();
    return ( 1 );
}

status do_attack( object ob ) {
    object *them;
    int i;

    them = all_inventory( environment( ob ) );
    i = random( sizeof( them ) );
    if( living( them[i] ) && !( them[i] == ob ) ) {
	them[i]->attacked_by( ob );
    }
    return ( 1 );
}

status do_peace( object ob ) {
    object them;

    them = ob->query_attack();
    ob->stop_fight();
    ob->stop_fight();
    ob->stop_hunter( 1 );
    if( !them ) 
	return ( 1 );
    them->stop_fight();
    them->stop_fight();
    them->stop_hunter( 1 );
    return ( 1 );
}

int confusion_shad() { return ( 1 ); }
