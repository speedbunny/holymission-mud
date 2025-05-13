inherit "/players/qclxxiv/jackpot";

reset(arg) {
	::reset(arg);
	if (!arg) set_factor( 0 );
}

at_0_prize( tp ) {
	tell_room(environment(this_object()), 
		"The jackpot machine opens up....and swallows "+tp->query_name()+".\n");
	tp->move_player( "into machine", "/players/qclxxiv/circular/in_jackpot" );
}
