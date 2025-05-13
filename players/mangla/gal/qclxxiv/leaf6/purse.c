int stored;
id(str) { return str == "purse"; }
short() { return "Purse";}
long() {
    write("A purse, capacity 10,000 coins.\n"+
	"Commands: 'topurse <number>', and 'frompurse <number>.\n"+
	"The purse contains "+stored+" gold coins currently.\n" );
}
query_value() { return 500+stored; }
init() { 
	add_action("topurse", "topurse",1); 
	add_action("frompurse", "frompurse",1); 
}
put() { return 1; }
get() { return 1; }
add_stored(i) { stored+=i; }

topurse(arg) 
{
	object me;
	int num,money;
    string possessive;
	me = this_player();
	possessive = me->query_possessive();
	if (!possessive) possessive = "its";
	if (arg && sscanf(arg,"%d",num)==1) {
		money = me->query_money();
		if (num<=money)
		{
			if (stored+num<=10000) {
				stored += num;
				me->add_money(-num); 
				write("You put "+num+" gold coins in your purse.\n");
				say(me->query_name()+" puts "+num+" gold coins in "
						+possessive+" purse.\n");
			}
			else {
				write("The purse can only hold up to 10,000 coins.\n");
			}
		}
		else write("But you don't have that much money.\n");
	}
	else write("Put what in purse?\n");
	return 1;
}

frompurse(arg) 
{
	object me;
	int num;
    string possessive;
	me = this_player();
	possessive = me->query_possessive();
	if (!possessive) possessive = "its";
	if (arg && sscanf(arg,"%d",num)) {
		if (stored>=num)
		{
			stored -= num;
			me->add_money(num); 
			write("You take "+num+" gold coins from your purse.\n");
			say(me->query_name()+" takes "+num+" gold coins from "
						+possessive+" purse.\n");
		}
		else write("But there is not that much money in your purse.\n");
	}
	else write("What do you want to take from purse?\n");
	return 1;
}
