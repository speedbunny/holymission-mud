inherit "/obj/key";
object home;
set_home(h) { home = h; }
long() { write("\nThis is a "+type+" key, it has something magic over it.\n"); }
init() { ::init(); add_action("rub", "rub"); } /* mostly intended for leaf3 */
query_value() { return 30; }
rub(arg) {
	if (id(arg)) {
		write("Ok.\n");
		if (home && this_player()) this_player()->move_player("home",home);
		return 1;
	}
	return 0;
}
