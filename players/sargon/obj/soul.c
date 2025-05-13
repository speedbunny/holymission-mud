/* ganjasoul is the device that controls spliff saturation:-) */
#define FILENAME "players/qclxxiv/obj/ganjasoul"
#define MAXLOAD 2
#define BEAT 20
int load;
int maxload;
object myplayer;

id(str) { return str == "qganjasoul"; }
get() { return 1; }
drop() { return 1; }
query_weight() { return 0; }
query_value() { return 0; }

reset(arg) {
	if (arg) return;
	maxload = MAXLOAD;
	if (load) call_out("heartbeat", BEAT);
}

player(pl) {
	if (!myplayer) {
		myplayer = environment();
		if (myplayer) 
			if (!living(myplayer)) {
				destruct(this_object());
				return 0;
			}
	}
	return (pl==myplayer);
}

draw(i) {
	if (!i) i=1;
	if ( (i+load)>MAXLOAD) return 0;
	if (!load) { /* start beat */
		load += i;
		call_out("heartbeat",BEAT);
		return 1;
	}
	load += i;
	return 1;
}

heartbeat() {
	if (load) {
		load--;
		if (myplayer) {
			switch( random(10) ) {
				case 0: case 3: command("smile",myplayer); break;
				case 1: case 5: command("laugh",myplayer); break;
				case 2: case 4: command("giggle",myplayer); break;
				case 6: 
					write("You're having the buzz feeling.\n");
					say(this_player()->query_name()
							+" is having the buzz feeling.\n",
							this_player() );
					break;
				case 7: 
					write("Your knees are wobbling.\n");
					say(this_player()->query_name()+"'s knees are wobbling.\n",
							this_player() );
					break;
				case 8: 
					write("Your belly is rolling.\n");
					say("You hear rolling sounds coming from "
							+this_player()->query_name()+"'s belly.\n",
							this_player() );
					break;
				case 9: 
					write("Your head is spinning.\n");
					say(this_player()->query_name()+"'s head is spinning.\n",
							this_player() );
					break;
			}	
		}
	}
	if (load) call_out("heartbeat", BEAT);	/* continue beat while load */
}

