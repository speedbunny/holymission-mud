/* islgen 1.0 clean - island room 2-10 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/whirl";

extra_reset(arg) {
	::extra_reset(arg);
	if (arg) return;
	destination = "players/qclxxiv/island/i_2_11";
	x = 2;
	y = 10;
}
