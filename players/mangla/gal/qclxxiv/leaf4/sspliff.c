inherit "players/qclxxiv/spliff";
reset(arg) {
	::reset(arg);
	if (arg) return;
	SORT = "super" ;
	set_sortkey( "sspliff");
	VALUE = 1300 ;
	STRENGTH = 700 ;
	set_draws( 7 );
	set_maxdraws( 7 );
}
