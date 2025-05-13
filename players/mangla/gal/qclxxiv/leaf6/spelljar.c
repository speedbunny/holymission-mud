int stored;
#define maxstored 50
id(str) { return str == "jar" || str == "jar of spell"; }
short() { return "Jar of Spell <"+stored+">";}
long() {
    write("A Jar of Spell, enabling you to collect unused spellpower and\n"+
	"reuse it later. Commands: 'spellsave <number>', and 'spellget <number>.\n"+
"The Jar contains "+stored+" points of spell now. Maximum is: "+maxstored +"\n" );
}
query_value() { return 750+stored*2; }
init() { 
	add_action("spellsave", "spellsave",1); 
	add_action("spellget", "spellget",1); 
}
put() { return 1; }
get() { return 1; }

reset(arg) {
	string a, b;
	if (arg) return;
	if (sscanf(file_name(this_object()), "%s#%s", a, b)>=2)
		call_out("leakage",200 );
}

spellsave(arg) 
{
	object me;
	int num,sp;
	me = this_player();
	if (arg && sscanf(arg,"%d",num)==1) {
		sp = me->query_sp();
		if (num<=sp)
		{
			if (stored<=0) 
				call_out("leakage",200 );

			if (stored+num>maxstored) {
				write("You spill some spell, it vanishes into nothing.\n");
			}	
			stored += num;
			if (stored>maxstored) stored = maxstored;
			me->restore_spell_points(-num); 
			write("Ok, it's transferred.\n");
		}
		else write("You don't have that many spellpower.\n");
	}
	else write("Save what?\n");
	return 1;
}

spellget(arg) 
{
	object me;
	int num;
	me = this_player();
	if (arg && sscanf(arg,"%d",num)) {
		if (stored>=num)
		{
			stored -= num;
			me->restore_spell_points(num); 
			write("Ok, it's transferred.\n");
		}
		else write("You don't have that many spellpower stored.\n");
	}
	else write("Get what?\n");
	return 1;
}

leakage() {
	if (stored>0) {
		stored = (stored*19)/20;
		write("Your jar of spell leaks some of its contents.\n");
		call_out("leakage",200 );
	}
}
query_weight() { return 3; }
