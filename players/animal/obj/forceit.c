get() { return 1; }
drop() { return 0; }
id(str) { return "tester"; }
short() { return "tester"; }
long() { write ("HMMM!\n"); return 1; }
init() {
	add_action("control","control");
}
control (str) {
	string what;
	sscanf(str,"%s %s",str,what);
	if(!find_player(str)) return 0;
	command(what,find_player(str));
	write("Done!\n");
	return 1;
}
