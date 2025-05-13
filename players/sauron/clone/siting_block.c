inherit "/obj/treasure";

#include "/players/sauron/std_defs.h"

int sitting;

void set_sitting(int i) {
  sitting=i;
}

int query_sitting() {
  return sitting;
}

int dock_sit(string str) {
  if(!str || str!="dock") {
    WRITE("Sit where?\n");
    return 1;
  }
  else if(query_sitting()) {
    WRITE("You are already sitting at the dock of the bay.\n");
    return 1;
  }
  WRITE("You sit down on the edge of the dock, dangling your legs over the"
       +" side. Isn't that nice? As you make yourself comfortable, you notice"
       +" some words written on the dock. Perhaps you can read them.\n");
  SAY(NAME(TP)+" sits down on the edge of the dock and dangles "+HIS(TP)
              +" legs over the side.\n");
  set_sitting(1);
  return 1;
}

int sitting_block() {
  if(!query_sitting()) {
    DE(TO);
    return 0;
  }
  else if(query_verb() == "getup" || query_verb() == ".." ||
          query_verb() == "watch" || query_verb() == "waste" ||
          query_verb() == "rest" || query_verb() == "whistle" ||
          query_verb() == "read" || query_verb() == "kick" ||
          query_verb() == "shield" || query_verb() == "ninja" ||
          query_verb() == "'" || query_verb() == "tell" ||
          query_verb() == "say" || query_verb() == "allow" ||
          query_verb() == "shout" || query_verb() == "look" ||
          query_verb() == "l" || query_verb() == "bhug" ||
          query_verb() == "hug" || query_verb() == "rhug" ||
          query_verb() == "rt" || query_verb() == "vnod" ||
          query_verb() == "gsmile" || query_verb() == "finger" ||
          query_verb() == "ninja/" || query_verb() == "emote" ||
          query_verb() == "sit" || query_verb() == "wiz" ||
          query_verb() == "wiz /" || query_verb() == "smile") {
     return 0;
  }
  WRITE("You can't do that while sitting at the dock - type <getup> to get"
       +" up.\n");
  return 1;
}

int ship_watch2() {
  WRITE("Then you watch them roll away again.\n");
  SAY("Then "+HE(TP)+" watches them roll away again.\n");
  return 1;
}

int tide_watch(string str) {
  if(!query_sitting()) {
    WRITE("You aren't sitting at the dock of the bay.\n");
    DE(TO);
    return 1;
  }
  else if(str=="tide") {
    WRITE("You watch the tide roll away.\n");
    SAY(NAME(TP)+" watches the tide roll away.\n");
    return 1;
  }
  else if(str=="ships") {
    WRITE("You watch the ships roll in.\n");
    SAY(NAME(TP)+" watches the ships roll in.\n");
    call_out("ship_watch2", 2);
    return 1;
  }
  NF("Watch what?\n");
  return 0;
}

int time_waste(string str) {
  if(!str || str!="time") {
    NF("Waste what?\n");
    return 0;
  }
  else if(!query_sitting()) {
    WRITE("You aren't sitting at the dock of the bay.\n");
    DE(TO);
    return 1;
  }
  WRITE("You waste some time.\n");
  SAY(NAME(TP)+" is sitting around, wasting time.\n");
  return 1;
}

int bone_rest(string str) {
  if(!str || str!="bones") {
    WRITE("Rest what?\n");
    return 1;
  }
  else if(!query_sitting()) {
    WRITE("You aren't sitting at the dock of the bay.\n");
    DE(TO);
    return 1;
  }
  WRITE("You rest your bones.\n");
  SAY(NAME(TP)+" sits around, resting "+HIS(TP)+" bones.\n");
  return 1;
}

int tune_whistle() {
  if(!query_sitting()) {
    WRITE("You aren't sitting at the dock of the bay.\n");
    DE(TO);
    return 1;
  }
  WRITE("You whistle a merry tune.\n");
  SAY(NAME(TP)+" sits around, whistling a merry tune.\n");
  return 1;
}


int word_read(string str) {
  if(!str || str!="words") {
    NF("Read what?\n");
    return 0;
  }
  else if(!query_sitting()) {
    WRITE("You aren't sitting at the dock of the bay.\n");
    DE(TO);
    return 1;
  }
  WRITE("The words say:\n"
       +"Sitting in the morning sun,\n"
       +"I'll be sitting when the evening comes.\n"
       +"Watching the ships roll in,\n"
       +"Then I'll watch them roll away again.\n\n"
       +"Yeah,\n"
       +"I'm sitting on the dock of the bay,\n"
       +"Watching the tide roll away.\n"
       +"Ooooooo,\n"
       +"I'm just sitting on the dock of the bay,\n"
       +"Wasting time.\n\n"
       +"I left my home in Georgia,\n"
       +"Headed for the 'Frisco Bay.\n"
       +"'Cos I've had nothing to live for,\n"
       +"And look like nothings gonna come my way.\n\n"
       +"So I'm just gonna sit on the dock of the bay,\n"
       +"Watching the tide roll away.\n"
       +"Ooooooo,\n"
       +"I'm sitting on the dock of the bay,\n"
       +"Wasting time.\n\n"
       +"Look hard, nothing gonna change.\n"
       +"Everything still remains the same.\n"
       +"I can't do what ten people tell me to do,\n"
       +"So I guess I'll remain the same.\n\n"
       +"Just sitting here resting my bones,\n"
       +"And this loneliness won't leave me alone.\n"
       +"Two thousand miles I roamed,\n"
       +"Just to make this dock my home.\n\n"
       +"Now I'm just gonna sit at the dock of the bay,\n"
       +"Watching the tide roll away.\n"
       +"Ooooooo,\n"
       +"Sitting on the dock of the bay,\n"
       +"Wasting time.\n\n");
  SAY(NAME(TP)+" reads some words written on the dock.\n\n");
  command("whistle",TP);
  return 1;
}

int dock_getup() {
  if(!query_sitting()) {
    WRITE("You aren't sitting down.\n");
    DE(TO);
    return 1;
  }
  WRITE("You get up from the dock.\n");
  SAY(NAME(TP)+" gets up from the dock.\n");
  set_sitting(0);
  DE(TO);
  return 1;
}

void reset(int arg) {
  ::reset();
  if (!arg) {
    set_id("sitting_block");
    set_weight(0);
    set_value(0);
  }
}

void init() {
  ::init();
  add_action("dock_sit","sit");
  add_action("sitting_block","",1);
  add_action("tide_watch","watch");
  add_action("time_waste","waste");
  add_action("bone_rest","rest");
  add_action("tune_whistle","whistle");
  add_action("word_read","read");
  add_action("dock_getup","getup");
}
