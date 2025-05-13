inherit "room/room";

#include "/players/sauron/std_defs.h"

void remove_hat() {
  WRITE("You take off your hat, respecting Illuvatar.\n");
  say(lw(CTPN+" takes off "+HIS+" hat in the church.\n"));
  command("remove helmet",TP);
}

int remove_ghost(string str) {
  string belief;
  object church;
  belief=TPREL;
  if(!belief || belief!="Illuvatar") {
    notify_fail("You are not a follower of Illuvatar!\n");
    return 0;
  }
  if(!TP->remove_ghost()) return 0;
  TP->set_smell("Smells as if just reborn.");
  return 1;
}

int try_attack(object ob) {
  TELLO(ob,lw("The gods are angry about your sacrilege. You feel bad.\n"));
  say(lw("A flash strikes "+CAP(ob->NAME)+".\n"),ob);
  ob->REDHP(random(100)+1);
  return 1;
}

string display_clock() {
  if("obj/tick"->qry_timer_value()<0)
    return "The clock shows midnight, and appears to have stopped";
  return "It is labeled in gothic lettering, from I to XII.\n"
        +"It currently shows the time to be "
        +ctime(82800-"obj/tick"->qry_timer_value())[11..15]
        +".\nBelow it is inscribed: The world endeth at midnight";
}

void light_text(string str) {
  WRITE("You hold the "+str+" into the holy candles of the altar to light it.\n");
  say(lw(CTPN+" lights a "+str+",\n"
    +"using the holy candles of the altar.\n"));
  if(TPREL=="Illuvatar") {
    WRITE("You feel very bad about doing this at the altar of your own god!\n"
         +"His revenge might take you one day!\n");
  }
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="Village church";
    long_desc="You are in the local village church. The church has the"
             +" service of reviving ghosts. Dead people come to church and"
             +" pray. Back on the north wall is an entrance to the new Holy"
             +" Mission Wedding Chapel. In the east wall you notice the"
             +" entrance to a small side room, the church portal opens to the"
             +" south. You feel the peace and holiness of this place and"
             +" you are sure the gods would punish the sacrilege of shedding"
             +" blood here. There is a sideroom to the west.\n";
    dest_dir=({
      "players/moonchild/wedding/chapel","north",
      "room/vill_green","south",
      "players/herp/room/father","east",
      "players/cashimor/rooms/sideroom","west"
    });
    items=({
      "clock","@@display_clock@@",
      "candles","They are secured by your conscience",
      "altar","The altar is golden and is lit by long white candles",
      "wall","Which of the walls",
      "walls", "Which of the walls",
      "portal", "Daylight falls in from the south side",
      "west wall", "In the west wall is an exit to a sideroom",
      "hole", "It leads to a vertical shaft in the west wall",
      "east wall", "It has a small entrance to the east",
      "north wall","You see a beautiful golden altar and white candles"
                  +" burning on it. In the wall there is an entrance to the"
                  +" wedding chapel to the north. Over the altar you see a"
                  +" big church clock",
      "entrance","The north entrance leads to the wedding chapel.\n"
                +"The east entrance leads to a praying room"
    });
    property=({
      "no_fight",
      "no_steal",
      "has_fire"
    });
    smell="The smell of burning incense and candles hangs here.";
  }
}

void init() {
  object hat;
  ::init();
  if(TPREL=="Illuvatar") {
    if(hat=present("helmet",TP)) {
      if(hat->query_worn())
      call_out("remove_hat",1);
    }
  }
  add_action("remove_ghost","pray");
}
