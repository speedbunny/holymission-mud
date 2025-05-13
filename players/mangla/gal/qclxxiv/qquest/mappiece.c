string map, backside, extraid;
int pieceno;
string owner;
set_owner(o) { owner = o; }
int piece_no() { return pieceno; }
int its_a_qmap_piece() { return 1; }
id(str) { return str == "map" || str == "piece" || str == extraid
				|| str == "piece of map"; }
short() { return "A piece of map"; }
get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 100; }

qmap(i) { return map[i]; }
qback(i) { return backside[i]; }

init() {
	if (!owner && this_player() && living(this_player())) 
		owner = this_player()->query_real_name();
	add_action("read", "read" );
	add_action("putmap", "put" ); 
	add_action("join", "join" );
}

long() {  
	int t;
	if (!map) {
		setup_map(this_player());
	}
	write("A piece of map: \n"); 
	for (t=0; t<7; t++)
		write( map[t]+"\n" );
	write("Something is written on the backside.\n");
}

read(arg) {
	int t;
	if (id(arg) || arg=="backside") {
		if (environment(this_object())==this_player()) {
			write("You read:\n");
			for (t=0; t<7; t++)
				write( backside[t]+"\n" );
			return 1;
		}
		if (!present("piece of map",this_player())
			&& !present("qquest_map",this_player()) ) {
			write("You can't read the backside while it's laying upside up.\n");
			return 1;
		}
	}
	return 0;
}

putmap(arg) {
	if (arg=="map together" || arg=="pieces together" 
			|| arg=="pieces of map together" )
		return join("map");
	return 0;
}

join(arg) {
	if (arg=="map" || arg=="pieces" || arg=="pieces of map") {
		do_join();
		return 1;
	}
	return 0;
}

do_join() {
	object ob1, ob2, ob3, ob4,themap;
	if ( (ob1=present("upper right piece",this_player()) )
		&& (ob2=present("upper left piece",this_player()) )
		&& (ob3=present("lower left piece",this_player()) )
		&& (ob4=present("lower right piece",this_player()) ) )
	{
		if (ob1->its_a_qmap_piece() && ob2->its_a_qmap_piece()
			&& ob3->its_a_qmap_piece() && ob4->its_a_qmap_piece() )
		{
			themap = clone_object("/players/qclxxiv/qquest/themap");
			if (!themap) write("MAP ERROR!\n");
			themap->join( ob1, ob2, ob3, ob4, this_player() );	
			if (transfer(themap, this_player())!=0) {
				move_object(themap, environment(this_player()) );
				write("You can not carry that much.\n");
			}
			else {
				write("You join the four pieces of a map together.\n");
				write(
"Of course you could destroy the map again, for instance if you might have\n"
+"added wrong pieces (like easily found, bought, or given ones). But then\n"
+"you loose it all unfortunately...however a wrong map is of little use.\n");
			}
			if (ob1!=this_object()) destruct(ob1);
			if (ob2!=this_object()) destruct(ob2);
			if (ob3!=this_object()) destruct(ob3);
			if (ob4!=this_object()) destruct(ob4);
			destruct(this_object());
		}
		else write("One or more of the pieces does not fit.\n");
	}
	else write("You don't have all four corners of a map.\n");
	
}

#define MM "/players/qclxxiv/island/mastermap"

setup_map(tp) {
	int t;
	if (!map && tp && living(tp)) {
		map = allocate(7);
		switch(pieceno) {
			case 1:
				map[0] = "____________ ";
				for (t=1; t<7; t++)
					map[t] = MM->halfrow(t-1,2,tp);
				break;
			case 2:
				map[0] = " _____________";
				for (t=1; t<7; t++)
					map[t] = MM->halfrow(t-1,1,tp);
				break;
			case 3:
				for (t=0; t<6; t++)
					map[t] = MM->halfrow(t+6,1,tp);
				map[6] = " ------------";
				break;
			case 4:
				for (t=0; t<6; t++)
					map[t] = MM->halfrow(t+6,2,tp);
				map[6] = "-------------";
				break;
			default: write(
"Some awfull curse has rendered this map unreadable, better call Qclxxiv!\n");
				map[0] = "!!!!!!!!!!!!!!!!!\n";		
				map[1] = "Some awfull curse\n";		
				map[2] = "has rendered this\n";		
				map[3] = "unreadable, \n";		
				map[4] = "better call \n";		
				map[5] = "Qclxxiv!\n";		
				map[6] = "!!!!!!!!!!!!!!!!!\n";		
		}	
	}
}

