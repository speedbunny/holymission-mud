inherit "obj/alco_drink";
id(str) { return (str=="qpub_drink" || ::id(str)); }
query_name() { return name; }
query_empty_name() { return empty_container; }

reset(arg) {
  ::reset(arg); /* to close the chain between sub- and super-class. */
}

drink(str) {
	if (!str || !id(str)) return 0;
	if (environment(this_player())->its_a_qpub()) ::drink(str);
	else {
		write(
"For some reason you feel so guilty about the stolen glassware of the pub\n"
+"that you start to shake and spill most of the liquid.\n" );
		say( this_player()->query_name()
+" starts to shake when trying to drink from stolen\n"
+"glassware of the fisher-men's pub, and spills most of the liquid.\n", 
			this_player() );
		full = 0;
	}
	return 1;
}

query_value() {
	if (!full) return 0;
	return ::query_value();
}
