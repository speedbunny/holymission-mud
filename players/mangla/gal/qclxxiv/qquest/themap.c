#define FILENAME "players/qclxxiv/qquest/themap"
/* string map, backside, extraid; */
string map, extraid;
int nomore;
int its_a_qmap() { return 1; }
id(str) { return str == "map" || str == "qquest_map"; }
short() { return "A map" ; }
get() { return 1; }
drop() { 
	if (nomore) {
		return 0;
	}
	return 1; 
}
set_nomore(i) { nomore = i; }
query_quest_item() { return 1; }

query_weight() { return 0; }
query_value() { return 500; }

reset(arg) {
	if (arg) return;
}

init() {
	add_action("read", "read" );
	add_action("dest","destroy");
}

long() {  
	int t;
	write("A map: \n"); 
	for (t=0; t<14; t++)
		write( map[t]+"\n" );
	write("Something is written on the backside.\n");
}

#define MM "/players/qclxxiv/island/mastermap"

read(arg) {
	int t;
	if (id(arg) || arg=="backside") {
		write("You read:\n");
		write(
" ________________________ \n"+
"|  Island of the Dragon   |\n"+
"|  @ whirl   & mail       |\n"+
"|  . beach   | lance      |\n"+
"|  - dell    $ poison     |\n"+
"|  ^ dune    # compass    |\n"+
"|  + forest  ^dig(4x)     |\n"+
"|                         |\n"+
"|  H hut    !dont dig     |\n"+
"|  W well   elsewhere!    |\n"+
"|  F firehouse            |\n"+
"|  S statue   Q: here u   |\n"+
"|  C chest  enter island  |\n"+
" ------------------------- \n"  );
	/* lets not put to much in player.o files. 
		for (t=0; t<14; t++)
			write( backside[t]+"\n" );
	*/
		return 1;
	}
	return 0;
}

/* ob1..4 MUST be mappieces 1.4. */
join(ob1, ob2, ob3, ob4, tp) {
	int t;
	map = allocate(14);
	/* backside = allocate(14); */
	for (t=0; t<7; t++) {
		map[t] = ob2->qmap(t) + ob1->qmap(t);
		/* backside[t] = ob1->qback(t) + ob2->qback(t); */
		map[t+7] = ob3->qmap(t) + ob4->qmap(t);
		/*backside[t+7] = ob4->qback(t) + ob3->qback(t); */
	}
}

query_auto_load() { 
	string temp;
	int i;
	if (nomore) return 0;
	temp = map[0] + "~";
	for (i=1; i<14; i++) {		/* so better not use tilde in map:-) */
		temp = temp + map[i] + "~";
	}
	return FILENAME+":"+temp; 
}

init_arg(arg) {
    int	count;
    string	line, the_rest;
    if (!arg) return;
	the_rest = "";
	map = allocate(14);
	if (sscanf(arg, "%s~%s", line, the_rest) == 2) {
		map[0] = line;
		count=1;
	   	while(the_rest && the_rest != "" && count<14) {
			arg = the_rest;
			if(sscanf(arg, "%s~%s", line, the_rest) >= 1) {
				map[count] = line;
				count++;
	   		}
		}
	}
}

dest(arg) {
	if (arg=="map")  {
		destruct(this_object());
		return 1;
	}
	return 0;
}
