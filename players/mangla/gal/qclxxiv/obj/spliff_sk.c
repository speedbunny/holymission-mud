inherit "players/qclxxiv/spliff";
reset(arg) {
	::reset(arg);
	if (arg) return;
	SORT = "skunk" ;
	set_sortkey( "spliff_sk");
	VALUE = 0 ;
	STRENGTH = 0 ;
	set_draws( 10 );
}
