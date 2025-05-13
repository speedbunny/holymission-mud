inherit "room/room.c";

#include "/players/patience/guild/skill_id.h"
#include "/players/sauron/std_defs.h"
#include "/players/sauron/calanport/path_defs.h"

void exit() {
  object ob;
  if(ob=present("puri_check",TP))
    DE(ob);
}

int do_wash(string str){
  object obj;
  if(!str) {
    WRITE("What do you want to wash?\n");
    return 1;
  }
  else if(TP->query_ghost()) {
    WRITE("As a ghost ?\n");
    return 1;
  }
  if(str=="hands") {
    obj=present("puri_check",TP);
    if(!obj) {
      obj=CO(TPLOBJ+"puri_check");
      MOVEO(obj,TP);
    }
    obj->set_hands_washed();
    WRITE("You wash your hands. You feel the deities appreciating it.\n");
    return 1;
  }
  else if(str=="hand") {
    WRITE("Only one?\n");
    return 1;
  }
  WRITE("You wash your "+str+".\n");
  say(lw(CTPN+" washes "+HIS+" "+str+".\n"));
  return 1;
}

int do_rinse(string str) {
  object obj;
  if(!str) {
    WRITE("What do you want to rinse?\n");
    return 1;
  }
  else if(TP->query_ghost()) {
    WRITE("As a ghost ?\n");
    return 1;
  }
  if(str=="mouth") {
    obj=present("puri_check",TP);
    if(!obj) {
      obj=CO(TPLOBJ+"puri_check");
      MOVEO(obj,TP);
    }
    obj->set_mouth_rinsed();
    WRITE("You rinse your mouth. You feel the deities appreciating it.\n");
    return 1;
  }
  WRITE("You rinse your "+str+".\n");
  say(lw(CTPN+" rinses "+HIS+" "+str+".\n"));
  return 1;
}

int do_meditate(string str) {
  object obj;
  if(TP->query_ghost() && TP->query_religion()=="Amaterasu") {
    obj=CO(TPLOBJ+"puri_check");
    MOVEO(obj,TP);
  }
  else {
    obj=present("puri_check",TP);
    if(!obj || !(obj->query_hands_washed()) ||
           !(obj->query_mouth_rinsed())) {
      WRITE("The deities won't show. Have you done the purification?\n");
      say(lw(CTPN+" tries to meditate but fails.\n"));
      return 1;
    }
  }
  WRITE("You kneel down and begin to meditate.\n");
  say(lw(CTPN+" kneels down and begins to meditate.\n"));
  obj->start_meditate();
  return 1;
}

int do_drink(string str) {
  if(str=="water" || str=="water from pool") {
    WRITE("As you drink some water from the pool, you get a bad feeling.\n");
    say(lw(CTPN+" drinks some water.\n"));
    TP->add_poison(3);
    return 1;
  }
  NF("Drink what?\n");
  return 0;
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="Inside a Jingu";
    long_desc="You are inside a strange looking stone. The walls are"
             +" shimmering in a faint yellow color. Beside the opening,"
             +" a place is set aside for purifucation rituals and near"
             +" the south wall is a place for meditation. A small stream"
             +" flows down the northern wall, the water collecting in a"
             +" small pool and running out through a hole at the base of"
             +" the western wall.\n";
    dest_dir=({
      TPLRMS+"jingu_out","out",
    });
    items=({
      "walls","They are shimmering in a faint yellow color",
      "wall","It shimmers in a faint yellow color",
      "opening","The opening faces east",
      "stream","It is a small stream of water flows down the north wall",
      "water","It flows down the northern wall, collecting in a small"
             +" pool, then out through a hole at the base of the west"
             +" wall",
      "pool","A small pool of water which has collected from the water"
            +" running down the north wall. The water runes out through"
            +" a hole in the west wall",
    });
    property=({"no_teleport"});
  }
}

void init() {
  ::init();
  add_action("do_wash","wash");
  add_action("do_rinse","rinse");
  add_action("do_meditate","meditate");
  add_action("do_drink","drink");
}
