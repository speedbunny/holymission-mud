int stored;
id(str) { return str == "jar" || str == "jar of health"; }
short() { return "Jar of Health <"+stored+">";}
long() {
    write("A Jar of Health, enabling you to collect unused health and\n"+
"reuse it later. Commands: 'healthsave <number>', and 'healthget <number>.\n"+
	"The Jar contains "+stored+" points of health now.\n" );
}
query_value() { return 750+stored*2; }
init() { 
	add_action("healthsave", "healthsave",1); 
	add_action("healthget", "healthget",1); 
}
put() { return 1; }
get() { return 1; }

healthsave(arg) 
{
	object me;
	int num,hp;
	me = this_player();
	if (arg && sscanf(arg,"%d",num)==1) {
		hp = me->query_hp();
		if (num<=hp) {
			if (hp-num < 25) {
				write("That would bring your hp below 25...You want to die?\n");
			}
			else {
				stored += num;
				me->hit_player(num);
				write("Ok, it's transferred.\n");
			}
		}
		else write("You don't have that many health points left.\n");
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
			me->heal_self(num);	/* the heal_self will always only */
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
