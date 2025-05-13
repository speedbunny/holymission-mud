inherit "room/room";

#include "/players/mangla/defs.h"

static object obj;
static int called;

int rope() {

    TELLR("players/kelly/rooms/mythwood/plateau1.c",
              "A rope just fell from the cloister down to you. Maybe must\n"+
              "still be someone alive up there.\n");
    obj=clone_object("players/kelly/obj/rope");
    MOVE(obj,TO);
    return 1;
}


int hand_in(string str) {

    if(str!="hand in print") return 0;

    say(TP->NAME + " puts " +TP->POS + " hand into the print.\n");
    if(called==0) {
        write("As you put your hand into the print, you can hear the ringing\n" +
              "of a bell in the cloister above you!\n");
        say("You can hear the ringing of a bell in the cloister.\n");
        call_out("rope",15);
        called=1;
        return 1;
    }
    else {
         write("Nothing happens!\n");
         return 1;
    }
}


reset(arg) {

    if (arg) return;
    set_light(1);
    if (called==1) {
        obj->destru();
    }
    called=0;
    no_castle_flag=1;
    short_desc="A plateau";
    long_desc="A large rocky plateau.\n"+
              "High above you on the top of a mountain, you can see an old cloister.\n"+
              "There is a strange print of a hand in the wall.\n";

    dest_dir=({
               "players/kelly/rooms/mythwood/plateau","northeast",
               "players/kelly/rooms/mountains/plateau","northwest",
             });

   items=({
           "cloister","It seems to be forsaken",
           "print","A powerful person must have pressed his hand into this rock,\n" +
                   "because you can nearly see the fingerprints of this hand",
           "wall","There is a print of a hand in the rock. Maybe your hand would fit",
         });
}

init() {

    ::init();
    add_action("hand_in","put");
}


