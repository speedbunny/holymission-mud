/* One specific note with a list of wanted items for qquest/old man */
int wantedlistnr;
int nr_items;
string item_count;
string item_name;
string item_amount;

index2name(i) {
	return "/players/qclxxiv/leaf3/gennote"->wanted_items(i);
}

reset(arg) {
	if (arg) return;
	wantedlistnr = random(10);
	nr_items ="/players/qclxxiv/leaf3/gennote"->nr_list_items(wantedlistnr);
	item_count = allocate(nr_items); /* rely on all fields 0 at start */
	item_name = allocate(nr_items);
	item_amount = allocate(nr_items);
	if (!item_count || !item_name || !item_amount) {
		self_destruct();
	}
	if ("/players/qclxxiv/leaf3/gennote"->get_names(wantedlistnr, item_name)
	&& "/players/qclxxiv/leaf3/gennote"->get_amounts(wantedlistnr, item_amount))
	{
	}
	else self_destruct();
}

id(str) { return str == "list" || str == "aqlist" ; }
short() { return "A list"; }
get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 0; }

init()  { 
	add_action("read", "read" );
}

long()  { write("A list of numbers and things.\n"); }

count2stripes(i) { 
	switch(i) {
	case 0: return "";
	case 1: return "I";
	case 2: return "II";
	case 3: return "III";
	case 4: return "IIII";
	case 5: return "IIIII";
	}
	return "many";
}

read(arg) {
	int t;
	if (arg=="list") {
		for (t=0; t<nr_items; t++) {
			write(item_amount[t]+" "+index2name( item_name[t])+" "
						+count2stripes(item_count[t])+"\n" );
		}
		write("\n");
		return 1;
	}
	return 0;
}

is_done() {
	return 1;
}

check_list( obj ) {
	int t;
	if (!obj) return 0;
	for (t=0; t<nr_items; t++)  {
		if (obj->id( index2name(item_name[t]) ) ) {
			item_count[t]++;
			return 1;
		}
	}
	return 0;	
}

self_destruct() {
	write("The list crumbles to dust.\n");
	destruct( this_object() );
}
