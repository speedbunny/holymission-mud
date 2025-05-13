inherit "players/qclxxiv/spliff";
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_sort( "collie herb" );
	set_sortkey( "spliff_c");
	set_value( 84 );
	set_strength( 42 );
	set_draws( 7 );
}
