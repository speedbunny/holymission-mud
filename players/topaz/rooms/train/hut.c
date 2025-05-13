inherit "room/room";

#include "/players/topaz/defs.h"

reset(arg) {
  if(!arg) {
    short_desc="A small hut";
    long_desc="This hut is a training area for adventurers who want to\n" +
              "get experience fighting.\n" +
              "It is a small hut.  You wonder how everything that you've\n" +
              "heard about can take place here.  Maybe you should try to\n" +
              "find out.\n" +
              "There is a sign on the back wall and an ordinary looking\n" +
              "door next to it.\n";

    dest_dir=({ATTACH + "road5","east",
    });
    items=({"hut","This hut is used to train adventurers in the art of fighting",
            "sign","You should read it",
            "door","A normal, yet somehow powerful looking door",
    });
    set_light(1);
return 1;
  }
}

init() {
    ::init();
    add_action("_train","enter");
    add_action("_read","read");
    add_action("_wiz","wizenter");
}

_read(str) {
    if(!id(str)) {
    write("Read what?\n");
    return 1;
    }
    if(str=="sign") {
    write("The sign reads:\n");
    write("    A training area has been chosen for you according to your\n");
    write("    level.  Hopefully you will find things to your liking.\n");
    write("    To get to your preselected training area, just\n");
    write("    \"enter door\"\n");
    return 1;
    }
}

int _train(string arg) {
    if(arg=="door" || arg=="doorway") {
      if(TP->query_level() < 6) {
        write("You walk through the doorway.\n");
        say(TP->NAME + "walks through the doorway.\n");
        MP("through the doorway#players/topaz/rooms/train/1_1");
        return 1;
      }
      if(TP->query_level() > 5 && TP->query_level() < 11) {
        write("Sorry.  Your area is not completed yet.\n");
        write("Please try back later.\n");
        return 1;
      }
      if(TP->query_level() > 10 && TP->query_level() < 18) {
        write("Sorry.  Your area is not completed yet.\n");
        write("Please try back later.\n");
        return 1;
      }
      if(TP->query_level() > 17 && TP->query_level() < 24) {
        write("Sorry.  Your area is not completed yet.\n");
        write("Please try back later.\n");
        return 1;
      }
      if(TP->query_level() > 23 && TP->query_level() < 30) {
        write("Sorry.  Your area is not completed yet.\n");
        write("Please try back later.\n");
        return 1;
      }
      if(TP->query_level() > 29) {
        write("You silly wizard!  Your fighting skills don't need training!\n");
        write("But, if you must have a look at what I've done,\n");
        write("commands are as follows:\n");
        write("   'wizenter newbie' (for players of levels 1-5)\n");
        write("   'wizenter lowmid' (for players of levels 6-10)\n");
        write("   'wizenter middle' (for players of levels 11-17)\n");
        write("   'wizenter highmid' (for players of levels 18-23)\n");
        write("   'wizenter high' (for players of levels 24-29)\n");
        return 1;
      }
    }
    else {
      write("Enter what?\n");
      return 1;
    }
}

int _wiz(string arg) {
  if(arg=="newbie") {
    write("You walk through the doorway to the newbie area.\n");
    MP("through the doorway#players/topaz/rooms/train/1_1");
    return 1;
  }
  else {
    write("Only the newbie area is operable at the moment.\n");
    return 1;
  }
}
