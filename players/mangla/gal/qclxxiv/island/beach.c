inherit "players/qclxxiv/island/iroom";

query_beach() { return 1; }
query_beach_dune_dell() { return 1; }

long(arg) {
	if (!arg) {
		write(long_desc);
		/*show_inventory_pl(arg, this_player());*/
		return 1;
	}
	else return ::long(arg);
	return 0;
}

veg_bar(arg) { write("Vegetation bars your way.\n"); return 1; }
