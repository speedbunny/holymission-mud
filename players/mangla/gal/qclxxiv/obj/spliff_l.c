inherit "players/qclxxiv/spliff";
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_sort( "collie herb" );
	set_value( 42 );
	set_strength( 42 );
	set_maxdraws( 7 );
	return 1;
}
