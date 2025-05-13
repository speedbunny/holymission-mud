id(str) { return str == "moncon"; }
short() { return 0; }
long()  { write("moncon <monsterlivingname> <command for init_command>.\n");}
get()	{ return 1; }
query_weight() { return 0; }
init()  { add_action("moncon", "moncon" ); }

moncon(str) {
	string mon, cmd;
	object ob;
	if (sscanf(str,"%s %s",mon,cmd)>1) {
		ob = present(mon, environment(this_player()) );
		if (!ob) ob = find_living(mon);
		if (!ob) ob = find_object(mon);
		if (!ob) write("Can't find any "+mon+".\n");
		else command(cmd, ob);
		return 1;
	} 
	return 0; 
}
