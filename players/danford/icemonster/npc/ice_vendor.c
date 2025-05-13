/* Nur ein Eis-Verkaeufer ... */

inherit "obj/monster";

reset(arg) {
::reset(arg);
  if(!arg) {
  	
     set_name("ice vendor");
     set_alias("ice vendor");
     set_alt_name("vendor");
     set_level(5);
     set_hp(100);
     set_al(100);
     set_short("Ice Vendor");
     set_long
("An Ice Vendor stands here, selling ice. Maybe you want to buy one?\n");
     set_wc(8);
     set_ac(4);
     set_aggressive(0);
     load_chat(35, ({
     	              this_object()->query_name() + " says: Soft Ice! Very delicious ice cream!\n",
     	              this_object()->query_name() + " says: Very good Soft Ice!\n",
     	              this_object()->query_name() + " tells you: You wanna buy ice? Read the sign and make your decision!\n"
     	              
     }));
  }
}

init() {
	::init();
//        add_action("buy", "buy");
}

buy(str) {
	string name,short_desc,mess,type;
	int value,cost,strength,soak,heal;
	if (!str) {
		write("Buy what?\n");
		return 1;
	}
	if (str == "1") {
		mess = "That doesn't seem to fill you much";
		str = "very small portion of soft ice";
		heal = 5;
		value = 20;
		strength = 5;
		type = "food";
	} else if (str == "2") {
		mess = "You don't feel very satisfied with your small portion";
		str = "small portion of soft ice";
		heal = 10;
		value = 40;
		strength = 10;
		type = "food";
	} else if (str == "3") {
		mess = "You are quite disappointed. THIS is a big portion? Yes";
		str = "big portion of soft ice";
		heal = 15;
		value = 60;
		strength = 13;
		type = "food";
	} else if (str == "4") {
		mess = "WOW!!! Your Ice-Cream tastes delicious";
		str = "very big portion of soft ice";
		heal = 20;
		value = 80;
		strength = 15;
		type = "food";
	} else if (str == "5") {
		mess = "What a great taste! You know, you've made the right decision";
		str = "giant's soft ice portion";
		heal = 25;
		value = 100;
		strength = 20;
		type = "food";
	} else {
		write("The Ice Vendor says: What do you want?\n");
		return 1;
	}
	if (call_other(this_player(),"query_money",0)<value) {
		write("That costs " + value + " gold coins, which you don't have.\n");
		return 1;
	}
	if (type == "food") {
	int fill;
	fill = (strength / 2) + 2;
	if (fill > (call_other(this_player(), "query_level") + 2)) {
		if (fill > (call_other(this_player(), "query_level") + 5)) {
			say(call_other(this_player(), "query_name", 0) + " orders a " +
			str + ", and immediately throws it up.\n", this_player());
			write("You order a " + str + ", try to eat it, and throw up.\n");
		} else {
			say(call_other(this_player(), "query_name", 0) + " orders a " +
			str + ", and gags on it!\n", this_player());
			write("You order a " + str + ", try to eat it, and gag on it!\n");
		}
		call_other(this_player(), "add_money", - value);
		return 1;
	}
	if (!call_other(this_player(), "eat_food", strength)) {
		write("The bartender says: I think don't think you can eat anymore.\n");
		say(call_other(this_player(), "query_name", 0) + " asks for a " +
		str + "but the Ice Vendor wont give it to him.\n", this_player());
		return 1;
	}
}
 write("You pay " + value + " coins for a " + str + ".\n");
 say(call_other(this_player(), "query_name", 0) + " orders a " + str + ".\n", this_player());
 call_other(this_player(), "add_money", - value);
 call_other(this_player(), "heal_self", heal);
 write(mess + ".\n");
 return 1;
 }
 
