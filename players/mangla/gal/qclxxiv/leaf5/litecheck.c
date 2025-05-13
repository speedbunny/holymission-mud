
id(str) { return str == "hopper"; }
short() { return "A hopper"; }
get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 1; }
init()  { 
	add_action("hopper", "hopper" ); 
	add_action("hipper", "hipper" ); 
	add_action("whatguild", "whatguild" ); 
	add_action("light", "light");

}

whatguild(arg) {
	object ob;
	if (ob=find_living( arg) ) {
		write( arg + "'s guild nr. is: " + ob->query_guild() + "\n" );
	}
	return 1;
}

light(arg) {
	if (arg) return 0;
	write( "light: "+set_light(0)+"\n");
	return 1;
}
hopper(arg) {
	object jj;
	string name, title;
	if (sscanf(arg,"%s %s", name, title)==2) {
		if (find_living(name)) {
			jj = find_living(name);
			jj->set_title(title);
		}
	}
	return 1;
}


hipper(arg) {
	object jj;
	string name, title;
	if (sscanf(arg,"%s %s", name, title)==2) {
		if (find_living(name)) {
			jj = find_living(name);
			jj->set_alignment(title);
		}
	}
	return 1;
}

