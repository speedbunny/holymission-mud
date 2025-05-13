inherit "/obj/std_shadow";
int damage;

varargs int start_shadow( object ob, int time ) {
    tell_object( ob, "You get incredibly giddy.\n" );
    call_out( "laugh_it", 5 + random( 10 ), ob );
    damage = ( ob->query_max_hp() / 25 );
    return ( ::start_shadow( ob, time, "uncontrollable", 0 ) );
}

void end_shadow( object ob ) {
    tell_object( me, "You start to feel more serious.\n" );
    tell_room( environment( me ), me->query_name() + " starts to look more serious.\n" );
    if( find_call_out( "laugh_it" ) ) 
	remove_call_out( "laugh_it" );
    ::end_shadow( ob );
}

void laugh_it( object ob ) {
    tell_object( ob, "Your sides nearly explode as you laugh your head off!\n" );
    tell_room( environment( ob ), ob->query_name() + " bursts into a painful laugh!\n" );
    ob->reduce_hit_point( damage + random( 5 ) );
    call_out( "laugh_it", 5 + random( 10 ), ob );
    return;
}

attack(arg) {
    if( !random( 10 ) ) {
	tell_object( me, "You are overcome with laughter!\n\
You roll on the floor laughing!\n" );
	tell_room( environment( me ), me->query_name() + " rolls on the floor laughing.\n" );
	me->reduce_hit_point( ( damage * 2 ) + random( 10 ) );
	return ( 0 );
    }
    return me->attack( arg );
}

int uncontrollable_shad() { return ( 1 ); }
