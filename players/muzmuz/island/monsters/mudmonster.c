inherit "obj/monster";
/* #include "/players/sourcer/define.h"

int holdtime, charges, startCharges,throw; // don't make the holdtime too high.. 
int last_init; */

reset(arg) {
	/* if(!startCharges) charges = 2;
	else charges = startCharges;i */
	if(arg) return;
	::reset(arg);

/*	last_init = time(); */
	set_name("mudmonster");
   set_aggressive (1);
   set_wimpy (-1);
	set_alias("monster");
	set_short("The mudmonster is partly buried in mud");
	set_long("It's a really ugly monster, over and over covered\n"+
		 "with cruelsome smelling mud, it`s looking evilly at you.\n");
	set_level(30);
        add_money (400+random(200));
/*
	if(!throw) throw = 90;
	if(!holdtime) holdtime = TOL * 2 / 10;  */	
	}


init() {
	::init();
/*
	charges += ( time()-last_init)  / 100;
	if(charges > 2) charges = 2;
	TS("I have "+charges+" now\n"); */
	}
/*
set_throw(int value) {
	if(value < 0) throw = 0;
	else if(value > 100) throw = 100;
	else throw = value;
	return throw;
	}

q_throw() {
	return throw;
	}

set_charge(int value) {
	if(!value) startCharges = 2;
	else startCharges = value;
	return value;
	}

q_charge() {
	return charges;
	}

set_hold(int value) {
	if(value < 1) return 1;  // using standart value
	else holdtime = value;
	return holdtime;
	}

q_hold() { return holdtime; }

do_throw() {
	if(charges > 0 ) {
		tell_room(file_name(E(TO)),
		   "The mudmonster throws a pile of mud into "+TO->query_attack()
		   ->query_name()+"'s face.\n");
		TO->query_attack()->hold(TO,random(holdtime/3)+random(holdtime/3));
		tell_object(TO->query_attack(),"You CAN'T SEE with all the mud in your eyes.\n");
		charges--;
		}
	return 1;
	}


heart_beat() {
	if(this_object()->query_attack() && (E(TO->query_attack()) == E(TO))) {
		if(random(throw) > random(100)) {
			do_throw();
			}
		}
	return ::heart_beat();
	}
*/
detect_invis()
{
    return 1;
}

