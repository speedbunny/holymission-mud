#include "defs.h"
#include "/players/tatsuo/guild/ndef.h"

#define SOMEONE

int main(string arg) {
    if(!arg || arg == "on" || arg == "off")  {
    return TP->guild_line(arg);
    }

#ifdef SOMEONE
  CD->do_chat(8, "[* Ninja *] " + TPN + " " +arg + "\n");
#else
  CD->do_chat(8, "[* Ninja *] " + CAP(TP->RNAME) + " " +arg + "\n");
#endif

return 1;
    }


