#include "/players/ted/defs.h"

inherit "room/room";

init() {
    ::init();
    add_action("buy"); add_verb("buy");
    add_action("list"); add_verb("list");
}

reset(arg) {
    ::reset(arg);
    if(!arg) {
	set_light(1);
	short_desc = "Ted's Magic Emporium";
	long_desc =
	"You are in Ted's Magic Emporium. A man in colorful robes\n"+
	"sits behind the counter, ready to serve you.....\n"+
	"Commands are: 'buy item', 'list',\n";
	dest_dir = ({
	  KPATH + "road1","north",
	});
    }
}

buy(item) {
    if (!item)
	return 0;
#if 0
    call_other("players/ted/path/magicstore", "fill");
#endif
    call_other("players/ted/path/magicstore", "buy", item);
    return 1;
}

list() {
#if 0
    call_other("players/ted/path/magicstore", "fill");
#endif
    call_other("players/ted/path/magicstore", "inventory");
    return 1;
}
