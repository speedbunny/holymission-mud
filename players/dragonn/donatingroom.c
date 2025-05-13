// Mangla: Changed double so it is not sent to test chars
#include "naming.h"
#define TP	this_player()
inherit "players/qclxxiv/shop";
int value;
int mssg;
int maxmssg;
string mssgtxts;
string name_of_item;
string longstart;
string longend;
object assort_store;
object food_store;
object local_store;
object bmap;
string *doubles_sent_by; // moonchild 130893

query_qnewbie() { return 1; }
query_newbiehint() { 
	return "Try the command   food     here, to see what take-away foods\n"
			+"and drinks and smokes can be bought here...\n";
}
clean_up(arg) { return 0; }

reset(arg) {
  ::reset(arg);
  doubles_sent_by=({});
  if (!bmap || environment(bmap)!=this_object()) {
	bmap = clone_object("/players/qclxxiv/obj/gnote");	
	if (!bmap) {
		return;
	}
	bmap->set_short("A shiny note");
	bmap->set_name("A shiny note");
	bmap->set_alt_name("note");
	bmap->set_long("A shiny note, circa 14 by 21 cm in size.\n" );
	bmap->set_alias("bmap");
	bmap->set_read(
	"\n"+
	"  labyrinth   G    village    Not too deep \n"+
	"       .      |     .+pub   into A & B are \n"+
	"        E     O    F       many easy preys. \n"+
	"         \\  / | \\ /      (deeper->tougher)\n"+
	"           O  |  O    \n"+
	"skum     /    |    \\    fields with \n"+
	"....A.-O   center   O-.B...crops and \n"+
	"        \\         /      insects \n"+
	"          O      O    \n"+
	"        /  \\   /  \\ \n"+
	"      .      O      . \n"+
	"     C       |       D \n"+
	" dwarfen     .        herbie hills \n"+
	"  forest     | library \n"+
	"             O O 0    \n"+
	"             | | |shops\n"+
	"       wait. O-O-O->to Rasta's Realm \n"+
	"       room    ^ V to root-system \n"
				);
	move_object(bmap, this_object());
  }
  if (arg) return;

  longstart =
NAME+"'s luxury shop. You can buy various luxury goods here.\n"+
"Especially try the luxury 'assortment'. But we buy and sell anything.\n"+
"A shopkeeper behind the counter provides the following services:\n"+
"    buy item, sell item, sell all [from bag], value item, assort, food,\n"+
"    list [armours|weapons|item], farlist [armours|weapons], farbuy item.\n"+
"A board gives more detailed information on the shop commands.\n"+
"A display screams: ";
  longend = 
"\nTo the south there is an opening with a warning on top of it. To the north\n"
+"is the Custom Weapons & Armours shop. East leads to Rasta's irie Ital Bar.\n"
+"There is a brand new bell at the counter.\n"
+"    There are four obvious exits: north, west, south and east\n" ;

  mssgtxts = ({ 
"TRY OUR ITAL SPLIFFS AND TAKE_AWAY FOODS/DRINKS!\n",
"TAKE A LOOK AT OUR LUXURY ASSORTMENT! TRY COMMAND: assort\n",
"FOR A REAL PARTY ONE GOES TO THE FISHING VILLAGE PUB!\n",
"CUSTOM WEAPONS, ARMOUR, and CLOTHING SHOP TO THE NORTH\n",
"RASTA's ITAL BAR IS A NICE WALK EAST AND THEN SOUTH. IRIE!\n",
"TRIED THE KEGS OF GUINNESS YET? GUINNESS IS GOOD FOR YOU!\n",
"GAMBLING!!: 1, 10, 25, and 100 COIN STAKES IN CIRCULAR ROOM!!\n",
"YOU DON'T HAVE A QMUNICATOR YET??? BUY ONE NOW!! LOW-PRICED!!\n",
"COMMENTS/COMPLAINTS/SUGGESTIONS? USE TYPO/BUG/IDEA commands!\n",
"FISHING VILLAGE PUB: W-W, N THRU STEM, NE-NE-NW-NE-NE-NE-NE-N\n",
      	});
  maxmssg = sizeof(mssgtxts)-1;
  set_short(NAME+"'s luxury shop");
  set_nodig(1);
  local_store = "/players/qclxxiv/mystore";
  set_store_room(local_store);
  assort_store = "/players/qclxxiv/astore";
  food_store = "/players/qclxxiv/foodstore";
  set_store_exit("northeast");
  set_exits(({"players/qclxxiv/entrance","west",
				"players/qclxxiv/hall/hall1","east",
				"players/qclxxiv/customshop","north",
				"players/qclxxiv/root/enter","south", }));
  set_light(1);
  items = ({ "counter", "A clean, polished black marble counter",
        "shopkeeper", "A modest looking man is standing behind the counter",
		"opening", "You expect that the shop's store is behind it",
		"doorway", "You expect that the shop's store is behind it",
		"assortment","You can get the list by command: 'assort'",
		"board","A large board showing help on the shop's commands. Read it.",
		"lanthorns", 
"Shining copper oil-burning lanthorns, spreading their yellowish light",
		"bell",
		"A bell with a small sign on it. It seems one can ring the bell",
		"sign", "A small sign mounted on the bell",
		
      	});
	property=({ "has_fire" });
}

long(arg) { 
	if (arg) {
		::long(arg);
		return;
    }
	write(longstart + mssgtxts[mssg] + longend);
}

light_text(str) {
	write("You light the "+str+" on one of the lanthorns.\n");
	say(this_player()->query_name()+" lights a "+str+",\n"
			+ "on one of the lanthorns.\n");
}

init() {
	object I;
	if (++mssg>maxmssg) mssg = 0;	/* next mssg for advertisement board */
  ::init();
  add_action("assort","assort");
  add_action("farbuy","farbuy");
  add_action("assort","assortment");
  add_action("listfood","food");
  add_action("farlist","farlist");
  add_action("read_sign", "read");
	add_action("ring","ring");
	if (I = find_player("qclxxiv")) {
		if (I!=this_player()) {	
			tell_object(I, ">>>>>>>>>>>>> "+
				this_player()->query_name()+" entered the luxury shop.\n");
		}
	}
}

/* buy_result:  -2, -1, 0, 1 on : too expensive, too heavy, not present, ok*/
buy(str) {
  if (!str) return;
  if (TP->query_ghost()) {
     write("You have no body to carry items with you.\n");
     return 1;
  }
  if (buy_food(str)) {
	 return 1;
  }
  else if (buy_assorted(str)) {
	if (buy_result==1)
	 write(
"The shopkeeper tells you: Congratulated with your good taste.\n");
	 return 1;
  }
  else if (local_store->is_present(str)) {
	::buy(str);
  	return 1;
  }
  else  {
	write("Sorry we don't have it. But we'll check the main shop.\n");
	write("Please wait a moment.\n");
 	"/room/main_shop"->buy(str); 
  	return 1;
  }
  write("Sorry but we don't have it. Maybe later?\n");
  return 1;
}

farbuy(str) {
	if (!str) return;
	if (TP->query_ghost()) {
		write("You have no body to carry items with you.\n");
		return 1;
	}
	write("Please wait a moment.\n");
 	"/room/main_shop"->buy(str); 
	return 1;
}

buy_assorted(item) { 
	buy_result = assort_store->buy(item); 
	/*return (buy_result==1) ? 1: 0;*/
	return buy_result;
}

buy_food(item) { 
	buy_result = food_store->buy(item); 
	/*return (buy_result==1) ? 1: 0;*/
	return buy_result;
}

assort(str) {
	assort_store->inventory(str);
	return 1;
}

listfood(str) {
	food_store->inventory(str);
	return 1;
}

list(arg) {
	write("Also take a look at the luxury assortment!!!\n");
	::list(arg);
	write(
	"If we don't have it, try 'farlist'. You can buy from main shop too!\n");
	return 1;
}

farlist(str) {
	"/room/store"->inventory(str);
	return 1;
}


read_sign(str) {
    if (str=="board") { 
    	write("\n");
    	write( "Commands and explanations for the Luxury Shop:\n\n"+
"assort         show the assorted luxury goodies sold in this shop\n"+
"list           show the 'normal' goodies in store (bought from customers)\n"+
"list armours, list weapons    show stored armours or weapons only\n"+
"list item      show all stored things called 'item'.  I.e.: list sword\n"+
"farlist        show all things stored in the main, central shop in the village\n"+
"farlist armours, farlist weapons   show only armours or weapons\n"+
"food           show the special assortment of take-away foods and drinks\n"+
"value item     show value of an item (you want to sell for instance)\n"+
"sell item      sell an item to the shop (will be in list thereafter)\n"+
"sell all from bag  (or rucksack or suitcase etc.)\n"+
"buy item       buy something from any of the shop's stores or assortments\n"+
					"\n");
    	return 1;
	}
	else if (str=="sign") {
		write("Ring this bell if you want to stand drinks all around.\n");
		write("The special gift-quality double beer is 16 coins a bottle.\n");
		write("The round will be mud-wide. You may only stand drinks once\n");
		write("per game reset.\n"); // moonchild 130893
		return 1;
	}
	else if (str=="warning") {
		write( "ROOT PERSONNEL ONLY!\n{,,. ('{=,++'! ,+!;\n" );
		return 1;
	}
	return 0;  
}

ring(str) {
	object u,b; 
	int i, cost;
	if (str!="bell") return 0;
	if(member_array(this_player()->query_real_name(), doubles_sent_by)!=-1)
		{
		write("You have already stood drinks recently.\n");
		return 1;
	}
	doubles_sent_by+=({ this_player()->query_real_name() });
	u=users();
	cost = 2*sizeof(u) * "/players/qclxxiv/obj/rounddouble"->query_value();
    if (call_other(this_player(), "query_money", 0) < cost) {
		write(
"A round would cost you "+cost+" gold coins, which you don't seem to have.\n");
		return 1;
    }
	write("This round is gonna cost you "+cost+" gold coins.\n");
	cost = 2*"/players/qclxxiv/obj/rounddouble"->query_value();
	for (i=0; i<sizeof(u); i++) {
//                if (u[i]->query_level()>30) continue;
                if (u[i]->query_level()>30 || u[i]->query_testchar())
                                         continue;
		tell_object(u[i], str+"\n");
		b = clone_object("/players/qclxxiv/obj/rounddouble");
		if (!b) break;
		b->set_giver(this_player());
		if (transfer(b, u[i])==0) {
			write("You give a double to "+u[i]->query_name()+".\n");
			tell_object(u[i],this_player()->query_name()
						+" stands drinks and sends you a double beer.\n");
    		call_other(this_player(), "add_money", -cost);
		}
		else {
			write("You fail to give a double to "+u[i]->query_name()
						+", perhaps it is too heavy now. Nothing charged.\n");
			destruct(b);
		}
	}
	return 1;
}
