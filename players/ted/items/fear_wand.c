int charges, level;

reset(arg) {
    if(arg) return 1;
    charges = 10;
}

init() {
    if(environment() != this_player()) return 1;
    add_action("fear"); add_verb("scare");
}

short() {
    return "A Bone Wand";
}

long() {
    write("This thin bone wand has strange black carvings all over it.\n");
    return 1;
}

id(str) {
    return (str == "wand" || str == "bone wand");
}

query_charges() { return charges; }
/* Changed by Ethereal Cashimor: No negative value anymore...
   080393 */
query_value() {
    if(charges>0) return 100+charges*100;
    return 0;
}

query_weight() { return 1; }
query_name() { return "Bone Wand"; }
query_info() {
    write("This wand radiates a strong aura of fear. Type 'scare <monster>'\n");
    write("or type 'scare all' to activate it.\n");
    return 1;
}
get() { return 1; }
drop() { return 0; }

fear(str) {
    object ob, nob;
    if(!str) {
	write("What are you trying to scare?\n");
	return 1;
    }
    if(charges<=0) {
	notify_fail("There are no charges left!\n");
	return 0;
    }
    if(str != "all") {
	ob = present(str, environment(this_player()));
	if(!ob) {
	    write("Can't scare something that is non-existant.\n");
	    return 1;
	}
	charges -= 1;
	level = call_other(ob, "query_level");
	if(random(100)+level > 80) {
	    write(str+ " is not effected!\n");
	    return 1;
	}
	write(str+ " runs in terror!\n");
	tell_object(ob, "A tremendous fear takes hold of your body!\n");
	call_other(ob, "run_away");
	return 1;
    }
    ob = first_inventory(environment(this_player()));
    charges -= 2;
    if(!ob) return 1;
    while(ob) {
	nob = next_inventory(ob);
	if(living(ob) && ob != this_player()) {
	    if(call_other(ob,"query_level") < 30) {
		level = call_other(ob, "query_level");
		if(random(100)+level < 80) {
		    write(call_other(ob,"query_name")+" runs in fear!\n");
		    tell_object(ob, "A treamendous fear takes hold of your body!\n");
		    call_other(ob, "run_away");
		    say(call_other(ob,"query_name")+" runs is fear!\n");
		} else {
		    write(call_other(ob,"query_name")+" is not effected.\n");
		}
	    }
	}
	ob = nob;
    }
    return 1;
}
