inherit "players/qclxxiv/spliff";
reset(arg) {
	::reset(arg);
	if (arg) return;
	SORT = "sensimilla" ;
	set_sortkey( "spliff_s");
	VALUE = 130 ;
	STRENGTH = 63 ;
	set_draws( 7 );
}
