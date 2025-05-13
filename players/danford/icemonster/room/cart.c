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
	if (!vendor) {
		vendor = clone_object(NPC + "ice_vendor");
		move_object(vendor, this_object());
        }
 
}

int buy(string str) {
//	vendor = present("ice vendor",this_player());
//	if(!objectp(vendor)) {
	if(!present(vendor,this_player())) {
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
		default :
			write("Buy what?\n");
		        return 1;
		        break;
		}
}
