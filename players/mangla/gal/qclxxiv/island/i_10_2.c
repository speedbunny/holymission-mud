/* islgen 1.0 clean - island room 10-2 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/whirl";

extra_reset(arg) {
	::extra_reset(arg);
	if (arg) return;
	destination = "players/qclxxiv/island/i_11_2";
	x = 10;
	y = 2;
}
