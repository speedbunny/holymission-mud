inherit "obj/thing";
#include "path.h"
object vendor;


reset(arg) {
  if(!arg) {
    set_name("cart");
    set_short("Ice Cream Cart");
    set_long("This is a little portable ice cream cart the vendor sells"
           + "ice cream out of. There is a sign attached to the side of"
           + "it.\n");
    set_can_get(0);
  }
}



init() {
	::init();
        add_action("buy", "buy");
	add_action("do_read","read");
/*
	if (!vendor) {
		vendor = clone_object(NPC + "ice_vendor");
		move_object(vendor, environment(this_object()));
        }
 
*/
}

int buy(string str) {
/*
	
	vendor = present(vendor,this_player());
	if(!present(vendor,this_object())) {

*/	if(!vendor) {
		notify_fail("Sorry. The vendor is not here to serve you.\n");
		return 0;
	}
	if (!str) {
		notify_fail("Buy what?\n");
		return 0;
	}
	switch(str) {
		case "1" :
			write("one\n");
			return 1;
			break;
		case "2" :
			write("two\n");
			return 1;
			break;
		case "5" :
			write("Ice vendor whispers to you: I'm sorry " + TP->query_real_name(1) +", you don't seem very Ice monster-esque.\n");
			say("Ice vendor whispers something to " + TP->query_real_name(1) +".");
		        return 1;
		        break;
		default :
			write("Buy what?\n");
		        return 1;
		        break;
		}
}


int do_read(string str) {
  if(str!="sign") {
	  return 0;
  }
  write("Soft Ice:\n"+
         "Available in various portions:\n"+
         "1. Very small portion :        20 coins \n"+
         "2. Small portion      :        40 coins \n"+
         "3. Big portion        :        60 coins \n"+
         "4. Very big portion   :        80 coins \n"+
         "5. Monster's portion  :       100 coins \n"+
         "Just type 'buy (num)' and the ice will be consumed at once.\n");
  return 1;
}
