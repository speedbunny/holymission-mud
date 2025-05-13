int stored;
#define maxstored 10

id(str) { return str == "jar" || str == "jar of health"; }
short() { return "Jar of Health <"+stored+">";}
long() {
    write("A Jar of Health, enabling you to collect unused health and\n"+
"reuse it later. Commands: 'healthsave <number>', and 'healthget <number>.\n"+
"The Jar contains "+stored+" points of health now. Maximum is: "+maxstored +"\n" );
}
query_value() { return 750+stored*2; }
init() { 
	add_action("healthsave", "healthsave",1); 
	add_action("healthget", "healthget",1); 
}
put() { return 1; }
get() { return 1; }

reset(arg) {
	string a, b;
	if (arg) return;
	if (sscanf(file_name(this_object()), "%s#%s", a, b)>=2)
		call_out("leakage",200 );
}

healthsave(arg) 
{
	object me;
	int num,hp;
	me = this_player();
	if (arg && sscanf(arg,"%d",num)==1) {
				if (stored<=0)
					call_out("leakage",200 );
				if (stored+num>maxstored) {
					write("You spill some health, it vanishes into nothing.\n");
				}	
				stored += num;
				if (stored>maxstored) stored = maxstored;
				me->hit_player(num,7);
				write("Ok, it's transferred.\n");
	}
	else write("Save what?\n");
	return 1;
}

healthget(arg) 
{
	object me;
	int num;
	me = this_player();
	if (arg  && sscanf(arg,"%d",num)) {
		if (stored>=num)
		{
			stored -= num;
                        me->reduce_hit_point(-num);
			/* give back what has been put into by users */
			/*  very seldom this object will be obtained by ONE player */
			/* also the stored (limited) points DO leak:-) */
			write("Ok, it's transferred.\n");
		}
		else write("You don't have that many health points stored.\n");
	}
	else write("Get what?\n");
	return 1;
}

leakage() {
	if (stored>0) {
		stored = (stored*19)/20;
		write("Your jar of health leaks some of its contents.\n");
		call_out("leakage",200 );
	}
}
query_weight() { return 3; }
