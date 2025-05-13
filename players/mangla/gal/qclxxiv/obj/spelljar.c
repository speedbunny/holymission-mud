int stored;
id(str) { return str == "jar" || str == "jar of spell"; }
short() { return "Jar of Spell <"+stored+">";}
long() {
    write("A Jar of Spell, enabling you to collect unused spellpower and\n"+
	"reuse it later. Commands: 'spellsave <number>', and 'spellget <number>.\n"+
	"The Jar contains "+stored+" points of spell now.\n" );
}
query_value() { return 750+stored*2; }
init() { 
	add_action("spellsave", "spellsave",1); 
	add_action("spellget", "spellget",1); 
}
put() { return 1; }
get() { return 1; }

spellsave(arg) 
{
	object me;
	int num,sp;
	me = this_player();
	if (arg && sscanf(arg,"%d",num)==1) {
		sp = me->query_sp();
		if (num<=sp)
		{
			stored += num;
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
