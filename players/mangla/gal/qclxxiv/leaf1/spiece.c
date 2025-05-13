inherit "/obj/treasure";
int mynum;

set_num(n) { mynum = n; }
get_num() { return mynum; }

reset(arg) {
	if (arg) return;
	set_alias("piece");
	set_id("piece of sword");
	set_weight(1);
	set_value(100);
	set_short("A piece of an old large sword"); 
	set_long("A piece of an old large sword.\n" );
}

long() {
	switch(mynum) {
		case 0 :
			write("A piece of an old large sword. It shines weird.\n");
			break;
		case 1:
			write("A piece of an old large sword. It shines weird.\n");
			break;
		case 2:
			write("A piece of an old large sword. It shines weird.\n");
			break;
		case 3:
			write("A piece of an old large sword. It shines weird.\n");
			break;
		case 4:
			write("A piece of an old large sword. It shines weird.\n");
			break;
		case 5:
			write("A piece of an old large sword. It shines weird.\n");
			break;
		case 6:
			write("A piece of an old large sword. It shines weird.\n");
			break;
		case 7:
			write("A piece of an old large sword. It shines weird.\n");
			break;
		case 8:
			write("A piece of an old large sword. It shines weird.\n");
			break;
		default: 
			write("A piece of an old large sword. It shines weird.\n");
	}
}

