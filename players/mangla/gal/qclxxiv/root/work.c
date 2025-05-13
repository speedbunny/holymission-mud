#include "/players/qclxxiv/root/rootroom.h"
int lastc;
string lastgiven;
int ngiven;

extra_reset(arg) { 
	if (arg) return; 
	items = ({ "opening", "An opening to the actual roots",
			});
	lastgiven=allocate(10);
	for (ngiven=0; ngiven<10; ngiven++)
		lastgiven[ngiven] = 0;
	ngiven = 0;
	mayexit = 0; 
	return 1; 
}

TWO_EXIT(	ROOT+"wentrance","east",
			ROOT+"w1",	"down",
"On top inside of the the massive root system of a giant leaf",
"You are on top inside the massive root system of a giant leaf. Some light\n"+
"shines in here from the east and also from the opening down to the roots.\n"+
"Here root workers can come together for a break, or they can do\n"+
"some light administrative work here to recover from the real job.\n"+
"Just type: work  if you want work. It's easy and each job can give 3 hp.\n"+
"Please do this work one at a time, or else you may bother eachother.\n"+
"Oh yes, if you appear to have come here without a weapon, type: weapon.\n"
, 1)

init() {
	::init();
	add_action("work","work");
	add_action("weapon","weapon");
}

work(arg) {
	int a,b,c, op;
	a = 1+ random(20);
	b = 1+ random(20);
	op = random(3);
	if (op==2) op = random(3); /* reduce change on multiplication:-) */
	if (op==0) {
		c = a + b;
		write(a+" + "+b+" = ?\n");
	}
	else if (op==1) {
		if (a<b) { c=a; a=b; b=c; }
		c = a - b;
		write(a+" - "+b+" = ?\n");
	}
	else {
		c = a * b;
		write(a+" * "+b+" = ?\n");
	}
	input_to("check_work");
	lastc = c;
	return 1;
}

check_work(arg) {
	int answer;
	if (sscanf(arg,"%d",answer)==1) {
		if (answer==lastc) {
			write("Ok.\n");
			this_player()->heal_self(3);  /* NOTE:  this heal is not */
					/* in a portable object,  very low, AND the region */
					/* this room is in, is isolated until all 30 eelworms */
					/* are killed. SO no shops..etc.. giving a good answer */
					/* to the work action requires a second or 2 at least */
					/* so do allow players this very small possibility to */
					/* do the root entirely (without having to quit). */
			return 1;
		}
	}
	write("What?\n");
	return 1;
}

weapon(arg) {
	int i;
	if (!present("cudgel", this_player())) {
		for (i=0; i<10; i++) {
			if (lastgiven[i]==this_player()) {
				write("You already have been given a cudgel today!\n");
				return 1;
			}
		}
		lastgiven[ngiven] = this_player();
		ngiven++;
		if (ngiven>=10) ngiven=0;
		move_object(clone_object(ROOT+"cudgel"), this_player() );	
		write("You receive a nice eelworm cudgel.\n");
	}
	else write("You already have one!\n");
	return 1;
}
