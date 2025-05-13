#include "naming.h"
inherit "players/qclxxiv/store";

int sold;
query_sold() { return sold; }

string assorted;

reset(arg) {
	object ob;
	int cnt;
    if (!arg) {
		set_light(1);
  		set_shop_room("/players/qclxxiv/myshop");
  		set_shop_exit("hidden");
		assorted = ({
				"lanthorn", "players/qclxxiv/lanthorn",
				"notebook", "players/qclxxiv/notebook",
				"sheetbook", "players/qclxxiv/sheetbook",
				"pamphlet", "players/qclxxiv/pamphlet",
				"goose-quill", "players/qclxxiv/obj/quill",
				"ink-bottle", "players/qclxxiv/obj/inkbottle",
/*
				"onyx", "players/qclxxiv/obj/onyx", 
				"jar of spell", "players/qclxxiv/obj/spelljar", 
				"jar of health", "players/qclxxiv/obj/healthjar", 
				"purse", "players/qclxxiv/obj/purse", 
*/
				"lock", "players/qclxxiv/identifier",
				"spade", "players/qclxxiv/obj/spade",
				"box_1", "players/qclxxiv/obj/flybox",
				"smart fly box", "players/qclxxiv/obj/cmdflybox",
				"diagnoser", "players/qclxxiv/shopdiag",
				"suitcase", "players/qclxxiv/obj/suitcase",
				"qmunicator","players/qclxxiv/obj/qmunicator"
		});
	}
	/* make sure all standard assortment is available */
	for (cnt=1; cnt<=(sizeof(assorted)/2); cnt++) {
    	if (!present(assorted[(cnt-1)*2]) ) {
			ob = clone_object(assorted[1+(cnt-1)*2] );
			move_object(ob , this_object());
		}
	}
}

long() { return "You are in "+NAME+"'s luxury shop's assortment store.\n"; }
short() { return NAME+"'s small luxury shop's assortment store."; }

/* as unassorted buy is called on failure of this buy, no fail mssgs here*/
buy(item) {
	object ob;
	int cnt;
    name_of_item = present(item);
    if (!name_of_item) { return 0; }
    value = call_other(name_of_item, "query_value", 0);
    value *= 2;
    if (call_other(this_player(), "query_money", 0) < value) {
		write("It would cost you ");
		write(value); write(" gold coins, which you don't have.\n");
		return -2;
    }
    if (!call_other(this_player(), "add_weight",
		    call_other(name_of_item, "query_weight"))) {
		write("You can't carry that much.\n");
		return -1;
    }
	ob = 0;
	for (cnt=1; cnt<=(sizeof(assorted)/2); cnt++) {
    	if (name_of_item->id(assorted[(cnt-1)*2]) ) {
			ob = clone_object(assorted[1+(cnt-1)*2]);
			break;
		}
	}
    call_other(this_player(), "add_money", -value);
	sold += value;
    move_object(name_of_item, this_player());
    write("The shopkeeper bends over and gives you your "+item+".\n");
    say(call_other(this_player(), "query_name") + " purchases " + item + ".\n");
	if (ob) move_object(ob , this_object());
    return 1;
}

inventory(str) {
	write("Qclxxiv's Luxury Assortment currently contains:\n\n");
	::inventory(str);
/*
	write("YES! The Onyx has come back in restricted form!!!!!.\n");
	write("Try the jar of health or jar of spell. BRAND NEW..GOOD FOR YOU!\n");
*/
	write("The assortment changes oft. Check it regularly therefore!.\n");
}

heart_beat() { } /* dunno when its called, but dont dest my assortment*/

