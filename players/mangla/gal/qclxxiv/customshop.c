#include "naming.h"
#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

int sold;
query_sold() { return sold; }
query_qnewbie() { return 1; }

clean_up(arg) { return 0; }
extra_reset(arg) {
  if (arg) return;
  set_nodig(1);
  items = ({ "counter", "A large low counter, scratched by armours and weapons",
        "shopkeeper", "A friendly smiling lady is standing behind the counter",
        "lady", "A friendly smiling lady; obviously she's the shopkeeper here",
		"board", "A board with product information. Maybe you should read it",
				"lanthorns", 
"Shining copper oil-burning lanthorns, spreading their yellowish light",
      	});
	property=({ "has_fire" });
}

light_text(str) {
	write("You light the "+str+" on one of the lanthorns.\n");
	say(this_player()->query_name()+" lights a "+str+",\n"
			+ "on one of the lanthorns.\n");
}

ONE_EXIT("players/qclxxiv/myshop", "south",
NAME+"'s Custom Weapon, Armours, and Clothing shop",
NAME+"'s Custom Weapons, Armours, and Clothing shop. Lightened by lanthorns.\n"+
"You can buy all types of armour and clothing here in a range of qualities,\n"+
"likewise you can choose from a range of weapons in all qualities. The VERY\n"+
"SPECIAL thing is that we only sell fully customizable material.\n"+
"A board shows more info on the customization properties of our products.\n"+
"A shopkeeper behind the counter awaits your commands.\n"+
"Commands are: 'buy item', 'weapons', 'mails', 'helmets', 'shields',\n"+
"'cloaks', 'boots', 'gloves', 'rings', and 'amulets'.\n"
,1 )

init() {
  ::init();
  add_action("buy", "buy");
  add_action("no_sell", "sell");
  add_action("mails", "mails");
  add_action("helmets", "helmets");
  add_action("shields", "shields");
  add_action("cloaks", "cloaks");
  add_action("gloves", "gloves");
  add_action("boots", "boots");
  add_action("rings", "rings");
  add_action("amulets", "amulets");
  add_action("weapons","weapons");
  add_action("read_sign", "read");
}

no_sell() {
	write("You can sell in the general shop just south of here.\n");
	return 1;
}

buy(str) {
	string name, names, rest;
	if (!str) return;
	if (this_player()->query_ghost()) {
		write("You have no body, so you can't carry items with you.\n");
		return 1;
	}
	if (sscanf(str, "%s %s", name, rest)==2 ) {
		names = (name[strlen(name)-1]!=115) 
				? name + "s" : name;
		if (names=="weapons") { buy_weapon(rest); }
		else if (names=="mails") { buy_mail(rest); }
		else if (names=="helmets") { buy_helmet(rest); }
		else if (names=="shields") { buy_shield(rest); }
		else if (names=="boots") { buy_boots(rest); }
		else if (names=="gloves") { buy_gloves(rest); }
		else if (names=="cloaks") { buy_cloak(rest); }
		else if (names=="rings") { buy_ring(rest); }
		else if (names=="amulets") { buy_amulet(rest); }
		else { write("Sorry but we don't have customizable "+names+".\n"); }
	}
	else { write("But which "+str+" do you want to buy?\n"); }
	return 1;
}

read_sign(str) {
    if (str=="board") { 
    	write("\n");
		write(
"All weapons and armours (incl. clothes) sold in this shop are fully\n"
+"customizable in prefix and suffix to the basic name.\n"
+"For instance such a weapon is just a 'lance' when sold.\n"
+"A prefix: Bloodstained, and a postfix: of Jupiter, will\n"
+"give you a weapon: Bloodstained lance of Jupiter, which can be wielded:\n"
+"wield lance or wield qweapon.\n"
+"All armours behave similar. \n"
+"With cool prefix and postfix and some imagination you can have all you\n"
+"always wanted to wear but never could find in this world.\n"
+"Of course you can modify the products as often as you please. Also our\n"
+"weapons can be 'unwielded' and our armours 'unworn'.\n"
+"Oh yes, needless to say of course, all products are of the highest quality\n"
+"but if you have any complaints or ideas, leave them here by using the\n"
+"commands 'bug', 'typo', or 'idea'. \nThanks, have fun. Q174.\n" 
);
		write("\n");
		return 1;
	}
	return 0;
}

sell( item, player) {
	int price;
	price = 2*(item->query_value());
    if (player->query_money() < price) {
		write("The price is: " + price
				+" gold coins, which you don't seem to have with you.\n" );
		destruct(item);
		return 1;
    }
    if (!player->add_weight( item->query_weight() ) ) {
		write("You can't carry that much.\n");
		destruct(item);
		return 1;
    }
	player->add_money(-price);
	sold += price;
	if (item->query_armour())
		item->set_size(this_player()->query_size());
    move_object(item, player);
    write("Ok, good luck with your "+item->query_name()+".\n");
	write("Please keep naming consistent with this world and time!\n");
    say(player->query_name()+" buys "+item->query_name()+".\n");
	return 1;
}

general() {
	write(
"All our armours and weapons come in two (three) classes: B for the regular,\n"
+"high-quality products, A for the luxury versions, often light-weight or so.\n"
+"Weapons and mails are available in various different qualities, indicated\n"
+"by numbers. To order an item: buy sort class quality, i.e.: buy boots A, \n"
+"or: buy mail A 1, or: buy shield B,\n"
+"or: buy weapon B 4(NOT buy sword B 4, the no. specifies the type of weapon).\n"
		);
}

weapons() {
	write( "Q174's high-quality customizable weapons:\n\n"
+"\t lances     longswords   battleaxes    swords     knifes\n"
+"\tA 5: 9750   A 4: 4000    A 3: 1200    A 2: 400    A 1: 200\n"
+"\tB 5: 4000   B 4: 2000    B 3:  500    B 2: 100    B 1:  50\n"
		+"\n");
	general();
	return 1;
}

/* next should be improved...much too linear still...*/

buy_weapon(str) {
	object ob; string cl,lcl; int qu,val;
	if (sscanf(str, "%s %d", cl, qu)==2) {
		lcl = lower_case(cl);
		if (lcl=="a" || lcl=="b") {
			if (1<=qu && qu<=5) {
				ob = clone_object("players/qclxxiv/obj/qweapon");
				ob->set_class((qu*3)+(qu/5));
				if (lcl=="b") {
					ob->set_weight( qu );
					if (qu>3) { if (qu==4) val=1000; else val=2000; }
					else if (qu==1) val=25;
					else if (qu==2) val=50; else val=250;
				}
				else {
					if (qu<3) ob->set_weight( qu-1 );
					else ob->set_weight( qu-2 );
					if (qu>3) { if (qu==4) val=2000; else val=4875; }
					else if (qu==1) val=100;
					else if (qu==2) val=200; else val=600;
				}
				ob->set_value(val);
				switch (qu) {
					case 1: ob->name_qweapon( "knife" ); break;
					case 2:ob->name_qweapon( "sword" ); break;
					case 3:ob->name_qweapon( "battleaxe" ); break;
					case 4:ob->name_qweapon( "longsword" ); break;
					case 5:ob->name_qweapon( "lance" ); break;
				}
				sell( ob, this_player() );
			}			
			else write("Quality should be a number from 1 to 5.\n");
		}
		else write("Class should be A or B.\n");
	}
	else write("A class (A or B) and a quality (1..5) should be specified.\n");
	return 1;
}

mails() {
	write( "Q174's high-quality customizable mails:\n\n"
+"\tA 4: 4000    A 3: 1200    A 2: 400    A 1: 200    A 0: 100\n"
+"\tB 4: 2000    B 3:  500    B 2: 100    B 1:  50    B 0:  26\n"
		+"\n");
	general();
	return 1;
}

buy_mail(str) {
	object ob; string cl,lcl; int qu,val;
	if (sscanf(str, "%s %d", cl, qu)==2) {
		lcl = lower_case(cl);
		if (lcl=="a" || lcl=="b") {
			if (0<=qu && qu<=4) {
				ob = clone_object("players/qclxxiv/obj/qmail");
				ob->set_ac(qu);
				if (lcl=="b") {
					ob->set_weight( qu );
					if (qu>2) { if (qu==3) val=250; else val=1000; }
					else if (qu==1) val=25; else val=50;
					if (!qu) { val=13; ob->set_weight(2); }
				}
				else {
					if (0<qu && qu<3) ob->set_weight( qu-1 );
					else if (qu>=3) ob->set_weight( qu-2 );
					if (qu>2) { if (qu==3) val=600; else val=2000; }
					else if (qu==1) val=100; else val=200;
					if (!qu) { val=25; ob->set_weight(1); }
				}
				ob->set_value(val);
				sell( ob, this_player() );
			}			
			else write("Quality should be a number from 0 to 4.\n");
		}
		else write("Class should be A or B.\n");
	}
	else write("A class (A or B) and a quality (0..4) should be specified.\n");
	return 1;
}

shields() {
	write( "Q174's high-quality customizable shields:\n\n"
+"\tA: 800\n" +"\tB: 300\n" +"\tC: 100\n" +"\tD:  50\n" +"\n");
	general();
	return 1;
}

buy_shield(str) {
	object ob; string cl,lcl; int val;
	if (sscanf(str, "%s", cl)==1) {
		lcl = lower_case(cl);
		if (lcl=="a" || lcl=="b" || lcl=="c" || lcl=="d") {
			ob = clone_object("players/qclxxiv/obj/qshield");
			ob->set_ac(1);
			if (lcl=="a") { ob->set_weight( 1 ); val = 400; }
			else if (lcl=="b") { ob->set_weight( 2 ); val = 150; }
			else { ob->set_weight( 3 ); val = 50; }
			if (lcl=="d") { val=25; ob->set_ac(0); ob->set_weight(2); }
			ob->set_value(val);
			sell( ob, this_player() );
		}
		else write("Class should be A or B or C or D.\n");
	}
	else write("A class (A or B or C or D) should be specified.\n");
	return 1;
}

helmets() {
	write( "Q174's high-quality customizable helmets:\n\n"
+"\tA: 350\n" +"\tB: 150\n" +"\tC: 100\n" +"\n");
	general();
	return 1;
}

buy_helmet(str) {
	object ob; string cl,lcl; int val;
	if (sscanf(str, "%s", cl)==1) {
		lcl = lower_case(cl);
		if (lcl=="a" || lcl=="b" || lcl=="c") {
			ob = clone_object("players/qclxxiv/obj/qhelmet");
			ob->set_ac(1);
			if (lcl=="a") { ob->set_weight( 1 ); val = 175; }
			else { ob->set_weight( 2 ); val = 75; }
			if (lcl=="c") { ob->set_ac(0); val=50; }
			ob->set_value(val);
			sell( ob, this_player() );
		}
		else write("Class should be A or B or C.\n");
	}
	else write("A class (A or B or C) should be specified.\n");
	return 1;
}

gloves() {
	write( "Q174's high-quality customizable gloves:\n\n"
+"\tA: 500\n" +"\tB: 150\n" +"\n");
	general();
	return 1;
}

buy_gloves(str) {
	object ob; string cl,lcl; int val;
	if (sscanf(str, "%s", cl)==1) {
		lcl = lower_case(cl);
		if (lcl=="a" || lcl=="b") {
			ob = clone_object("players/qclxxiv/obj/qgloves");
			ob->set_ac(1);
			if (lcl=="a") { ob->set_weight( 1 ); val = 250; }
			else { ob->set_weight( 2 ); val = 75; }
			ob->set_value(val);
			sell( ob, this_player() );
		}
		else write("Class should be A or B.\n");
	}
	else write("A class (A or B) should be specified.\n");
	return 1;
}

boots() {
	write( "Q174's high-quality customizable boots:\n\n"
+"\tA: 450\n" +"\tB: 200\n" +"\n");
	general();
	return 1;
}

buy_boots(str) {
	object ob; string cl,lcl; int val;
	if (sscanf(str, "%s", cl)==1) {
		lcl = lower_case(cl);
		if (lcl=="a" || lcl=="b") {
			ob = clone_object("players/qclxxiv/obj/qboots");
			ob->set_ac(1);
			if (lcl=="a") { ob->set_weight( 1 ); val = 225; }
			else { ob->set_weight( 2 ); val = 100; }
			ob->set_value(val);
			sell( ob, this_player() );
		}
		else write("Class should be A or B.\n");
	}
	else write("A class (A or B) should be specified.\n");
	return 1;
}


cloaks() {
	write( "Q174's high-quality customizable cloaks:\n\n"
+"\tA: 450\n" +"\tB: 200\n" +"\tC: 100\n" +"\n");
	general();
	return 1;
}

buy_cloak(str) {
	object ob; string cl,lcl; int val;
	if (sscanf(str, "%s", cl)==1) {
		lcl = lower_case(cl);
		if (lcl=="a" || lcl=="b" || lcl=="c") {
			ob = clone_object("players/qclxxiv/obj/qcloak");
			ob->set_ac(1);
			if (lcl=="a") { ob->set_weight( 1 ); val = 225; }
			else { ob->set_weight( 2 ); val = 100; }
			if (lcl=="c") { val=50; ob->set_ac(0); }
			ob->set_value(val);
			sell( ob, this_player() );
		}
		else write("Class should be A or B or C.\n");
	}
	else write("A class (A or B or C) should be specified.\n");
	return 1;
}

rings() {
	write( "Q174's high-quality customizable rings:\n\n"
+"\tA: 3000\n" +"\tB: 1000\n" +"\n");
	general();
	return 1;
}

buy_ring(str) {
	object ob; string cl,lcl; int val;
	if (sscanf(str, "%s", cl)==1) {
		lcl = lower_case(cl);
		if (lcl=="a" || lcl=="b") {
			ob = clone_object("players/qclxxiv/obj/qring");
			ob->set_ac(1);
			if (lcl=="a") { ob->set_weight( 1 ); val = 1500; }
			else { ob->set_weight( 2 ); val = 500; }
			ob->set_value(val);
			sell( ob, this_player() );
		}
		else write("Class should be A or B.\n");
	}
	else write("A class (A or B) should be specified.\n");
	return 1;
}

amulets() {
	write( "Q174's high-quality customizable amulets:\n\n"
+"\tA: 7000\n" +"\tB: 2000\n" +"\tC: 14 (mascot)\n" +"\n");
	general();
	return 1;
}

buy_amulet(str) {
	object ob; string cl,lcl; int val;
	if (sscanf(str, "%s", cl)==1) {
		lcl = lower_case(cl);
		if (lcl=="a" || lcl=="b" || lcl=="c") {
			ob = clone_object("players/qclxxiv/obj/qamulet");
			ob->set_ac(1);
			if (lcl=="a") { ob->set_weight( 1 ); val = 3500; }
			else if (lcl=="b") { ob->set_weight( 3 ); val = 1000; }
			else { ob->set_weight( 0 ); val = 7; ob->set_ac(0); }
			ob->set_value(val);
			sell( ob, this_player() );
		}
		else write("Class should be A or B or C.\n");
	}
	else write("A class (A or B or C) should be specified.\n");
	return 1;
}

