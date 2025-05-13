/*=========================================================================
        BARBARIAN'S THROW --- ie. attack
=========================================================================*/

#define E       environment()
#define ENV     environment
#define NF      notify_fail

int main( string str ) {

    object next_throw, next_throw_ob;

    string ob_name,mon_name;
    object tmp;

    if(next_throw)
	return 1;
    if(!str) {
	NF("Throw what?\n");
	return 0;
    }
    if((sscanf(str, "%s at %s", ob_name, mon_name))!=2) {
	if(!(tmp=(object)E->query_attack()) || !present(tmp, ENV(E))) {
	    NF("Throw what?\n");
	    return 0;
	}
	ob_name=str;
    }
    else {
	tmp=present(mon_name, ENV(E));
	if(!tmp || !living(tmp)) {
	    NF("Throw the " + ob_name + " at what?\n");
	    return 0;
	}
    }
    if(ENV(E)->query_property("no_fight")) {
	write("It probably wouldn't be an idea to do that here.\n");
	return 1;
    }
    if(!(next_throw=present(ob_name, E))) {
	switch(ob_name[0..0]) {
	case "a":
	case "e":
	case "i":
	case "o":
	case "u":
	case "y":
	    NF("You don't have an " + ob_name + " to throw!\n");
	    break;
	default:
	    NF("You don't have a " + ob_name + " to throw!\n");
	    break;
	}
	next_throw=0;
	return 0;
    }
    if(transfer(next_throw, ENV(E))) {
	NF("You can't throw that!\n");
	next_throw=0;
	return 0;
    }
    transfer(next_throw, E);
    next_throw_ob=tmp;
    return 1;
}

