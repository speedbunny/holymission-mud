#include "/players/tatsuo/guild/ndef.h"

main() {

    if(!TP->query_immortal())
   TP->move_player("quits","/players/tatsuo/guild/room");
    return 0;
}
