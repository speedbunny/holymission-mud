#include "../params.h"

int cmd_free(string str) {
    object ob;
    if(!str) return 0;
    if(!(ob = find_player(str))) return 0;
    move_object(ob, "/room/church");
    destruct(present("pcurse", ob));
    return 1;
}
