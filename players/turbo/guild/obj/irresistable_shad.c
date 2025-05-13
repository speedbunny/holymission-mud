inherit "/obj/std_shadow";
int old_ac, old_wc, old_str, old_dex;
int dam;

varargs int start_shadow( object ob, int time ) {
    old_wc = ob->query_n_wc();
    old_ac = ob->query_n_ac();
    old_str = ob->query_str();
    old_dex = ob->query_dex();
    ob->set_n_wc( old_wc / 3 * 2 );
    ob->set_n_ac( old_ac / 4 * 3 );
    ob->set_str( old_str / 4 * 3 );
    ob->set_dex( old_dex / 4 * 3 );
    dam = ( ob->query_max_sp() / 25 );
    tell_object( ob, "You feel the beat of the rhythm of the night.\n" );
    call_out( "dance_me", 5 + random( 10 ), ob);
    return ::start_shadow( ob, time, "irresistable", 0);
}

void end_shadow( object ob ) {
    me->set_n_wc( old_wc );
    me->set_n_ac( old_ac );
    me->set_str( old_str );
    me->set_dex( old_dex );
    tell_object( me, "You start to lose the rhythm.\n" );
    tell_room( environment( me ), me->query_name() + " stops dancing.\n" );
    if( find_call_out( "dance_me" ) ) 
	remove_call_out( "dance_me" );
    ::end_shadow( ob );
}

void dance_me( object ob ) {
    tell_object( ob, "You dance frantically with everyone in the room!\n" );
    tell_room( environment( ob ), ob->query_name() + " sweeps you across the dance floor!\n" );
    ob->restore_spell_points( - dam + random( 5 ) );
    call_out( "dance_me" , 5 + random( 10 ), ob );
}

int irresistable_shad() { return ( 1 ); }
