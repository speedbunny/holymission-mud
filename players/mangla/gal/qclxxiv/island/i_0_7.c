/* islgen 1.0 clean - island room 0-7 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/whirl";

extra_reset(arg) {
	::extra_reset(arg);
	if (arg) return;
	destination = "players/qclxxiv/island/i_0_8";
	x = 0;
	y = 7;
}
