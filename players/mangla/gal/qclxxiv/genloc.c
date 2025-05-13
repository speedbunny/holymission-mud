inherit "/players/qclxxiv/qtool";

reset(arg) {
	::reset();
	if (arg) return;
	set_name("genloc");
	set_short("A genloc");
	set_long("Use genloc <livingname>  to locate livings.\n"+
			"Use objloc <name> to locate things.\n" );	
	hidden=1;
}

get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 1; }

init()  { ::init(); 
	add_action("genloc", "genloc" ); 
	add_action("objloc", "objloc" ); 
}

genloc(arg) {
	object jj;
	if (find_living(arg)) {
		jj = find_living(arg);
		jj = environment(jj);
		if (jj) write( "Found in: "+file_name(jj)+  ".\n");
		else write("Found, but it has no environment.\n");
	}
	else write("Not found.\n");
	return 1;
}

objloc(arg) {
	object jj;
	if (find_object(arg)) {
		jj = find_object(arg);
		jj = environment(jj);
		if (jj) write( "Found in: "+file_name(jj)+  ".\n");
		else write("Found, but it has no environment.\n");
	}
	else write("Not found.\n");
	return 1;
}

