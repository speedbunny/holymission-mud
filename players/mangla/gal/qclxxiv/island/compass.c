id(str) { return str == "compass"; }
short() { return "A compass"; }
long()  { write(
"A round, copper compass. Its needle is vibrating continuously, making read\n"
+"out slightly difficult.\n"); }
get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 30; }
query_quest_item() { return 1; }

init()  { 
	add_action("read", "read" );
}

read(str) {
	object ob;
	int myx, myy, hisx, hisy;
	string dir;
	if (!id(str)) return 0;
	if (!present(str, this_player())) return 0;
	ob=find_living("islanddragon");
	if (ob) {
		if ( environment(this_player())
			&& environment(this_player())->query_qisland()
			&& environment(ob) && environment(ob)->query_qisland() ) {
			myx = environment(this_player())->query_x();
			myy = environment(this_player())->query_y();
			hisx = environment(ob)->query_x();
			hisy = environment(ob)->query_y();
			hisx = hisx - myx;
			hisy = hisy - myy;	
			myx = (hisx>0) ? hisx : -hisx;
			myy = (hisy>0) ? hisy : -hisy;
			if (myx>=2*myy) {
				if (hisx>0) dir = "east";
				else dir = "west";
			}
			else if (myy>=2*myx) {
				if (hisy>0) dir = "south";
				else dir = "north";
			}
			else if (hisx>0) {
				if (hisy>0) dir = "southeast";
				else dir = "northeast";
			}
			else {
				if (hisy>0) dir = "southwest";
				else dir = "northwest";
			}
			write("The needle is pointing to the "+dir+".\n");
		}
		else write("The needle keeps spinning around.\n");
	}
	else {
		write("The needle keeps spinning around.\n");
	}
	say(this_player()->query_name()+" is reading a compass.\n", this_player());
	return 1;
}
