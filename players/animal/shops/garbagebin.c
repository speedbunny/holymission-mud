
#include "room.new.h"

ONE_EXIT(
"players/animal/closed/lobby", "south",
"This is where ALL garbage gets dumped!",
"Garbage Bin\n\n\n"
+ "\tThis is where the garbage goes, it stinks\n"
+ "\tin here REAL bad......REALLY BAD!\n"
+ "\n\n",
1, 4)

query_long() { return long_desc; }

query_light() { return 1; }

query_room_maker() { return 102; }

/*
    remove the comments around the "room is modified()" code
    below to prevent changes you have done to this room to
    to be lost by using the room maker
*/
/*
room_is_modified() { return 1; }
*/

/*
 make your additions below this comment, do NOT remove this comment
--END-ROOM-MAKER-CODE--
*/

