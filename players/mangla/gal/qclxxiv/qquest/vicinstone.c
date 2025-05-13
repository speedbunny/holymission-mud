#define HOME "/players/qclxxiv/"
inherit "obj/treasure";
string vroom;
int seen;
reset(arg) {
  if(arg) return;
    set_short("A red stone");
    set_long(
	"A red stone. It seems to vibrate very softly. It shines dully.\n");
	set_id("stone");
	set_alias("qvicinstone"); /* just recognizing THE qdragon */
    set_value(0);
  	set_weight(0);
	vroom = ({ "leaf1/l8", "leaf2/n1", "leaf2/n9", "leaf2/n15",
				"leaf6/q3", "leaf6/q7", "leaf6/q9", "leaf7/r6",
			});
}

id(arg) { return (::id(arg) || arg=="red stone"); }

long(arg) {
	if (this_player() && living(this_player()) 
				&& test(this_player())) {
		write(
	"A red stone. It seems to vibrate VERY FAST. It shines bright.\n");
	}
	else ::long(arg);
	if(seen<2) {
		seen++;
		call_out("vision", 7, this_player() );
	}
}

vision(tp) {
	int v;
	v=(HOME+"qquest/qmast")->lock_name2key(3, tp->query_real_name() );
	write("Suddenly you find yourself in a place in a vision:\n");
	(HOME+vroom[v])->ext_long();
	write("Then things turn back normal again.....\n");
	if (seen<3) {
		write("The stone looses some brilliance.\n");
	}
}

test(tp) {
	object ob;
	int myx, myy, hisx, hisy;
	string dir;
	ob=find_living("islanddragon");
	if (ob) {
		if ( environment(tp)
			&& environment(tp)->query_qisland()
			&& environment(ob) && environment(ob)->query_qisland() ) {
			myx = environment(tp)->query_x();
			myy = environment(tp)->query_y();
			hisx = environment(ob)->query_x();
			hisy = environment(ob)->query_y();
			hisx = hisx - myx;
			hisy = hisy - myy;	
			myx = (hisx>0) ? hisx : -hisx;
			myy = (hisy>0) ? hisy : -hisy;
			if (myx<=1 && myy<=1) return 1;
		}
	}
	return 0;
}
