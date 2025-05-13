int hidden;
id(str) { return str == "hopper"; }
short() { return (hidden) ? 0 : "A hopper"; }
get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 1; }

reset(arg) {
	if (arg) return;
	hidden = 1;
}

init()  { 
	add_action("hopper", "hopper" ); 
	add_action("hipper", "hipper" ); 
	add_action("whatguild", "whatguild" ); 
	add_action("makethink", "makethink" ); 
	add_action("scantest", "scantest");
	add_action("inspect","inspect");
	add_action("items","items");
	add_action("objects","objects");
	add_action("send","send");
	add_action("hide","hide");
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

hide(arg) {
	if (arg=="titler" || arg=="hopper") {
		if (hidden) hidden = 0;
		else hidden = 1;
		return 1;
	}
	return 0;
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


scantest(arg) {
	string a,b;
	write("Number returned by sscanf(arg, %s#%s, a,b): ");
	write( sscanf(arg, "%s#%s", a, b)+"\n" );
	return 1;
}

whatguild(arg) {
	object ob;
	if (ob=find_living(arg) ) {
		write( arg + "'s guild nr. is: " + ob->query_guild() + "\n" );
	}
	return 1;
}

makethink(arg) {
	object ob;
	string a,b;
	if (sscanf(arg, "%s %s", a, b)<2) {
		write("makethink playername rest of line.\n");
		return 1;
	}
	if (ob=find_living(a) ) {
		tell_object(ob,"You think: "+b+"\n");
		write("Ok.\n");	
	}
	else write("Cant find "+a+"\n");
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

send(arg) {
	object jj, kk;
	string name, thing;
	if (sscanf(arg,"%s %s", name, thing)==2) {
		if (find_living(name)) {
			jj = find_living(name);
			if (present(thing,this_player())) {
				kk = present(thing,this_player());
				if (transfer(kk,jj)==0) {
					tell_object(jj,this_player()->query_name()
							+" sends you "+lower_case(kk->short())+".\n");
					write(thing+" send  to "+name+".\n");
				}
				else write("For some reason can't transfer "
						+thing+" to "+name+".\n");	
			}
			else write("Can't find thing "+thing+".\n");
		}
		else write("Can't find living "+name+".\n");
	}
	return 1;
}

