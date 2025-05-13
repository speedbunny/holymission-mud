#define FILENAME "/players/qclxxiv/obj/flu"
int state,open,cycle;
object env;
id(str) { return str == "flu_q174"; }
short() { return 0; }
get() { return 1; }
drop() { return 1; }
/* query_auto_load() { return FILENAME+":"+"not_used"; } */
query_weight() { return 0; }

reset(arg) {
	if (arg) return;
	state = 0;
	env = 0;
	call_out("do_state",20+random(40));		/* incubation time */
	return 1;
}

init() { 
	add_action("oursay","say"); 
}

oursay(arg) {
	if (open) {
		if (cycle<1) {
			do_cough();
			cycle=4+random(2);
		}
		cycle--;
	}
	say( this_player()->query_name()+" says: "+arg+"\n", this_player() );
	write("Ok.\n");
	return 1;
}

set_immune() {
	state = 9;
	return 1;
}

do_state() {
	if (!env) 
		env = environment(this_object());
	if (!env || !living(env)) {
		destruct(this_object());
		return;
	}
	if (state==0) tell_object(env,"You feel like you have caught a flu.\n");
	state++;
	if (state<10) {	
		open = 1;
		do_sneeze();
		call_out("do_state",20+random(20));
	}
	else if (state>15) destruct(this_object());
	else {
		open = 0;
		call_out("do_state",70);	/* immune period */
	}
}

do_sneeze() {
	tell_object(env,"You feel a sneeze coming...\n");
	tell_room(environment(env),"HAAAAAAAAAAACHOOOO. "+env->query_name()
									+" sneezes moisty.\n");
	if (random(4)==3) do_cough();
	else infect_room(environment(env));
	return;
}

do_cough() {
	tell_room(environment(env),"UGH UGH UCH. "+env->query_name()
									+" coughs nastily.\n");
	infect_room(environment(env));
	return;
}

infect_room(aroom) {
	int i;
	object obj;
	obj = all_inventory(aroom);
	for (i=0; i<sizeof(obj); i++) 
		if (living(obj[i]) && !present("flu_q174",obj[i])) 
			infect(obj[i]);
	return 1;
}

infect(obj) { move_object(clone_object(FILENAME),obj); }

