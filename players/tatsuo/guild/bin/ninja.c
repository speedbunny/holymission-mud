#include "/include/defs.h"
#include "/players/tatsuo/guild/ndef.h"

#define SOMEONE

int main(string arg) {

  if(!arg || arg == "on" || arg == "off") {
    return TP->guild_line(arg);
  }

  if(TPL < 20) {
#ifdef SOMEONE
    CD->do_chat(8, "[* Ninja " + TPN + " *] " + arg + "\n");
#else
    CD->do_chat(8, "[* Ninja " + CAP(TP->RNAME) + " *] " + arg + "\n");
#endif
//    "/players/tatsuo/guild/room"->commune_ninja("[* Ninja "+TPN+" *] "+arg+"\n");
    return 1;
  }

  if(TPRN == "tatsuo" || TPRN == "nobunaga" || TPRN == "wilbie" ) {
#ifdef SOMEONE
    CD->do_chat(8, "[* Ninja " + TPN + "-sama *] " + arg + "\n");
#else
    CD->do_chat(8, "[* Ninja " + CAP(TP->RNAME) + "-sama *] " + arg + "\n");
#endif
    return 1;
//    "/players/tatsuo/guild/room"->commune_ninja("[* Ninja "+TPN+"-sama *] "+arg+"\n");return 1;
  }
#ifdef SOMEONE
  CD->do_chat(8, "[* Ninja " + TPN + "-san *] " + arg + "\n");
#else
  CD->do_chat(8, "[* Ninja " + CAP(TP->RNAME) + "-san *] " + arg + "\n");
#endif
//  "/players/tatsuo/guild/room"->commune_ninja("[* Ninja "+TPN+"-san *] "+arg+"\n");
  return 1;
}

