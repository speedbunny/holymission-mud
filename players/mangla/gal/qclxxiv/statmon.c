id(str) { return str == "statmon"; }
short() { return "A statmon"; }
get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 1; }
init()  { 
	add_action("statmon", "statmon");
	add_action("inspect","inspect");
	add_action("items","items");
	add_action("objects","objects");
}

statmon(arg) {
	object obj;
	if (environment()!=this_player()) return 0;
	obj = present(arg, environment(this_player()) );
	if (obj && living(obj)) {


	}
	else write("Can't find a ny living "+arg+" here.\n");
	return 1;
}

inspect(arg) {
	object env;
	string items;
	int i;
	object obj;
	env = environment();
	if (env!=this_player()) return 0;
	if (env) {
		env = environment(env);
		if (!env) return 1;	/* now env must be env of carrier of titler */
		items = (string *) env->query_room("items");	
		if (items) {
			write("Items:\n");
			for (i=0; i<sizeof(items)-1; i++) {
				write(items[i]+": ");
				i++;
				write(items[i]+".\n");
			}
		}
		obj = all_inventory(env);
		if (obj) {
			write("Objects:\n");
			for (i=0; i<sizeof(obj); i++)
				if (obj[i]->short()) write(capitalize(obj[i]->short())+".\n");
		}
	}
	return 1;
}

items(arg) {
	object env;
	string items;
	int i;
	object obj;
	env = environment();
	if (env!=this_player()) return 0;
	if (env) {
		env = environment(env);
		if (!env) return 1;	/* now env must be env of carrier of titler */
		items = (string *) env->query_room("items");	
		if (items) {
			write("Items:\n");
			for (i=0; i<sizeof(items)-1; i++) {
				write(items[i]+": ");
				i++;
				write(items[i]+".\n");
			}
		}
	}
	return 1;
}

objects(arg) {
	object env;
	string items;
	int i;
	object obj;
	env = environment();
	if (env!=this_player()) return 0;
	if (env) {
		env = environment(env);
		if (!env) return 1;	/* now env must be env of carrier of titler */
		obj = all_inventory(env);
		if (obj) {
			write("Objects:\n");
			for (i=0; i<sizeof(obj); i++) {
				write(obj[i]->query_name()+": ");
				obj[i]->long();
			}
		}
	}
	return 1;
}

