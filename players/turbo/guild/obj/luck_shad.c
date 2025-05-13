inherit "/obj/std_shadow";
int i, j;
object ob;

int start_shadow( object me, int count ) {
    j = count;
    ob = me;
    tell_object( me, "You feel like you have the Luck O' The Irish!\n" );
    return ( ::start_shadow( ob, 0, "irishluck", 0 ) );
}

varargs int hit_player( int dam, int kind, mixed *elem ) {
    if( dam >= ( ob->query_hp() / 2 ) ) {
	tell_object( ob, "The attack luckily misses you!\n" );
	tell_room( environment( ob ), ob->query_name() + " sidesteps the attack!\n" );
	i++;
	if( i == j )
	    end_shadow( ob );
	return ( 0 );
    }
    return ( ob->hit_player( dam, kind, elem ) );
}

void end_shadow( object ob ) {
    tell_object( ob, "You feel less lucky.\n" );
    ::end_shadow( ob );
    return;
}

int luck_shad() { return ( 1 ); }
