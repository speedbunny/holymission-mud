inherit "/players/qclxxiv/library/shelf";
object ind;

get()	{ return 0; }
set_color(str) { color = str; }
id(str) { return str=="table" || str == color+" table" || str == "qlib_table"; }
short() { return "A large "+color+" table"; }

long() {  
	int i;
	object obj;
	write( "A large "+color+" table.");
	obj = all_inventory(this_object());
	if (sizeof(obj)) {
		write( " On it:\n");
		for (i=0; i<sizeof(obj); i++)
			if (obj[i]->short()) write(obj[i]->short()+".\n");
	}
	else write(" Nothing is on it.\n");
}

reset(arg) {
	if (!ind && !(environment() && present("index",environment()) ) 
			&& !present("index") ) {
		ind = clone_object("/players/qclxxiv/library/index");
		move_object(ind, this_object());
	}
	if (arg) return;
	books = 0;
	color = "wooden";
}
