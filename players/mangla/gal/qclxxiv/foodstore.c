#include "naming.h"
inherit "players/qclxxiv/store";

string assorted;

reset(arg) {
	object ob;
	int cnt;
    if (!arg) {
		set_light(1);
  		set_shop_room("/players/qclxxiv/myshop");
  		set_shop_exit("hidden");
		assorted = ({
				"spliff_c", "players/qclxxiv/obj/spliff_c",
				"spliff_s", "players/qclxxiv/obj/spliff_s",
				"spliff_lb", "players/qclxxiv/spliff",
				"cigar_hav", "players/qclxxiv/cigar",
				"cigar_trick", "players/qclxxiv/tcigar",
				"tea", "players/qclxxiv/obj/fishtea",
				"keg", "players/qclxxiv/obj/guinkeg",
				"guinnessbottle", "players/qclxxiv/obj/guinness",
				"goat", "players/qclxxiv/obj/goat",
				"chicken", "players/qclxxiv/obj/chicken",
				"cornbread", "players/qclxxiv/obj/cornbread",
				"fish", "players/qclxxiv/obj/roastfish",
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

long() { return "You are in "+NAME+"'s luxury shop's food store.\n"; }
short() { return NAME+"'s small luxury shop's food store."; }

/* as unassorted buy is called on failure of this buy, no fail mssgs here*/
/* returns:  -2, -1, 0, 1 on : too expensive, too heavy, not present, ok*/
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
	write("Qclxxiv's Food and Drinks Assortment currently contains:\n\n");
	::inventory(str);
	write(
"\nEnjoy it all. All products are strictly ital, so everything is allowable\n"+
"to and good for Rastafarians (well...except for the cigars of course).\n"+
"Of course it's all take-away stuff. But feel free to eat here or in the bar\n"+
"to the east if you are hungry right now.\n");
}

heart_beat() { } /* dunno when its called, but dont dest my assortment*/

