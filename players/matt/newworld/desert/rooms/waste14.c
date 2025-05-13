#include "/players/matt/defs.h"

inherit NWDESERT + "rooms/waste";

status monsterflag;
object monst;

reset(arg) {
  monsterflag = 0;
  if(arg) return;
  ::reset(arg);
  dest_dir = ({
    NWDESERT + "rooms/shadow14", "west",
    NWDESERT + "rooms/shadow18", "east",
    NWDESERT + "rooms/shadow15", "north",
    NWDESERT + "rooms/waste13", "south",
    NWDESERT + "rooms/shadow17", "northeast",
    NWDESERT + "rooms/shadow12", "southwest",
    NWDESERT + "rooms/shadow19", "southeast",
  });
}

init() {
  ::init();
  if(!monsterflag && !monst && (find_call_out("do_monst") == -1)) {
    call_out("do_monst", 5, 0);
    monsterflag = 1;
  }
}

do_monst(stage) {
  switch(stage) {
  case 0:
    TELLR(TO, "The ground begins to quake.\n");
    break;
  case 1:
    TELLR(TO, "The sand around you shifts and moves violently.\n");
    break;
  case 2:
    TELLR(TO, "Some of the sands begin to coalesce.\n");
    break;
  case 3:
    TELLR(TO, "You see a monstrous form taking shape.\n");
    break;
  case 4:
    TELLR(TO, "A huge sandy beast looms before you. Run while you can!\n");
    break;
  default:
    TELLR(TO, "You now face a gigantic beast of the desert!\n");
    monst = CLONE(NWDESERT + "monsters/sandmonster");
    MOVE(monst, TO);
    return;
  }
  call_out("do_monst", 5, (stage + 1));
}
