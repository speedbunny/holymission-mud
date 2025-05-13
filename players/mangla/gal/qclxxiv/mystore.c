#include "naming.h"
inherit "players/qclxxiv/store";

reset(arg) {
  ::reset(arg);
  set_shop_room("/players/qclxxiv/myshop");
  set_shop_exit("south");
	if (!present("matchbox")) {
		object mb1, mb2, mb3;
		mb1 = clone_object("/players/galadriel/fire/matchbox");
		if (mb1) move_object(mb1, this_object() );
		mb2 = clone_object("/players/galadriel/fire/matchbox");
		if (mb2) move_object(mb2, this_object() );
		mb3 = clone_object("/players/galadriel/fire/matchbox");
		if (mb3) move_object(mb3, this_object() );
	}
}

long() { return "You are in "+NAME+"'s luxury shop's store.\n"; }
short() { return NAME+"'s small luxury shop's store."; }

is_present(arg) { return present(arg); }

