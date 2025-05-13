
#include "/players/aaa/defs.h"
#include <std.h>

inherit "room/room";

void reset(int arg) {
    ::reset(arg);
    if(arg) return;
    set_light(1);
    property=({"no_fight","no_teleport"});
    short_desc="Waiting room of a bank";
    long_desc="This is the famous Morgan's bankhouse!\n"+
              "At least the waiting-room of that. The Morgan family "+
              "has been dealing with money for a very long time, and the "+
              "knowledge in this subject that has been accumulated during "+
              "the centuries, passed to sons by fathers, made this bank "+
              "to be the BEST of Holy Mission.\n"+
              "The furniture is simple, uncomfortable but expensive-looking."+
              "The only person in the room is a secretary sitting behind a "+
              "desk. No one seems to guard the enterance to the negotiation "+
              "room, but you have heared of the invisibility-spell...\n"+
              "There is a SIGN on the wall.\n";
    dest_dir=({PA+"stown/road4.c","west",
               PA+"stown/presroom.c","east"});
    items=({"desk","In other banks of Holy Mission it would make for the\n"+
                "president. Made of mahagony, with sophisticated decoration",
            "chair","They are made of massive gold, but despite your "+
            "incompetence in arts, you are sure the material gives the "+
            "lesser part of their value",
            "chairs","There are five of them",
            "sign","This is a platinum plate with some writing. The letters "+
            "are little mozaiks consisting of various precious stones",
            "secretary","A smartly dressed, extreme beauty at her late "+
            "twenties. Somehow you know that she has other qualities as well, "+
            "for example trained in karate or something. Her look is very "+
            "intelligent"});   
}

void init() {
    ::init();
    add_action("read","read");
    add_action("east","east");
}

int read(string str) {
    if (str!="sign") {
        notify_fail("Read what ?\n");
        return 0;
    }
    write("It reads:\nWelcome to the Morgan's bank!\n"+
          "We offer You the next services:\n"+
          "1, Collecting deposits\n2, Checkbook\n3, Bank card\n4, Transfer "+
          "to another banks\nWe hope You will be pleased with us!"+
          "\n\nAnd a bit below, with smaller letters:\n"+
          "Regret, due to administration costs we can only service customers "+
          "who\ndispose of at least 25'000 coins.\n");
    return 1;
}

int east(string str) {
    if (str) {
        write("Pardon ?\n");
        return 1;
    }
    if ((this_player()->query_money()<25000) && 
        (!present("aaa-bank-contract",this_player()))) {
        write("The secretary whispers to you, while discretely pointing "+
              "at the sign:\n"+
              "Sorry, Mr. Morgan is out now... please, try later.\n");
        return 1;
    }

}
