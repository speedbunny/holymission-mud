inherit "players/qclxxiv/spliff";
reset(arg) {
	::reset(arg);
	if (arg) return;
	SORT = "Size Negusa" ;
	set_sortkey( "spliff_long");
	VALUE = 0 ;
	STRENGTH = 0 ;
	set_draws( 210 );
	set_maxdraws( 210 );
}
