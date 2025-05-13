inherit "obj/treasure";

#include "/players/topaz/defs.h"
string temp,oldlook,looker="Topaz the Wizard";

reset(arg) {
  ::reset();

    set_id("statue");
    set_name("statue");
    set_short("A statue");
    set_value(0);
    set_weight(200);
}

init() {
    ::init();
    add_action("look_statue","look");
    add_action("look_statue","exa");
    add_action("look_statue","examine");
    add_action("look_statue","l");
}

look_statue(str) {
    if(str=="statue" || str=="the statue" || str=="at statue" || str=="at the statue") {
      if(temp==CAP(TP->query_real_name())) {
      }
      else {
        temp=CAP(TP->query_real_name());
        oldlook=looker;
        looker=temp;
      }
    write("This is a statue of a brave adventurer.\n");
    write("It is excellent workmanship!  It looks very life-like.\n");
    write("It looks just like " + oldlook + ".\n");
    write("You hope that someday there will be a statue that looks like you.\n");
    say(TP->query_name() + " looks at the statue and says: Wow!\n",TP);
    return 1;
    }
    else {
      write("You are so enthralled by the statue that you can\n");
      write("look at nothing else!\n");
      return 1;
    }
}
