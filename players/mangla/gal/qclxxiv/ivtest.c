id(str) { return str == "ivtest"; }
short() { return "An ivtest"; }
get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 1; }
init()  { add_action("ivtest", "ivtest" ); }
ivtest(arg) {
	object jj;
	if (find_living("ishenvendor")) {
		jj = find_living("ishenvendor");
		jj = environment(jj);
		if (jj) write( "found in: "+file_name(jj)+  "\n");
		else write("but it has no environment\n");
	}
	else write("not found\n");
	return 1;
}

