inherit "/obj/std_shadow";

varargs int start_shadow( object ob, int time ) {
    tell_object( ob, "You are overcome with fear!\n" );
    call_out( "scare_me", 5 + random( 10 ), ob);
    return ::start_shadow( ob, time, "nightmare", 0);
}

void end_shadow( object ob ) {
    tell_object( me, "You start to feel brave again.\n" );
    tell_room( environment( me ), me->query_name() + " looks braver.\n" );
    if( find_call_out( "scare_me" ) ) 
	remove_call_out( "scare_me" );
    ::end_shadow( ob );
}

void scare_me( object ob ) {
    tell_object( ob, "You cower in fear!\n" );
    tell_room( environment( ob ), ob->query_name() + " cowers in fear!\n" );
    call_out( "scare_me" , 5 + random( 10 ), ob );
}

varargs int hit_player( int dam, int kind, mixed *elem ) {
    int damage;

    if( dam > 200 ) 
	return ( me->hit_player( dam, kind, elem ) );
    switch( random( 20 ) ) {
    case 0..7:
	damage = dam + dam / 10;
	break;
    case 8..11:
	damage = dam + dam / 5;
	break;
    case 12..14:
	damage = dam + dam / 4;
	break;
    case 15..17:
	damage = dam + dam / 3;
	break;
    default:
	damage = dam + dam / 2;
    }
    tell_object( me, "You howl in pain and anguish!\n" );
    tell_room( environment( me ), me->query_name() +
      " howls in pain and anguish!\n" );
    return ( me->hit_player( dam, kind, elem ) ) ;
}

int nightmare_shad() { return ( 1 ); }
