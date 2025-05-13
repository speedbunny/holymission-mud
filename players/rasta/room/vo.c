#include "std.h"
 
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_init()
{
}
 
extra_reset()
{
object table;
if (present("voting table")) return;
call_other("wd/thorax/misc/voting_table", "move_me", this_object());
table = call_other("wd/thorax/misc/voting_table", "me");
if (!table) table = clone_object("wd/thorax/misc/voting_table");
move_object(table, this_object());
}
 
ONE_EXIT("room/track2", "east",
	"Voting house",
"You are in a small house where you may go to vote on various subjects.\n", 1)
