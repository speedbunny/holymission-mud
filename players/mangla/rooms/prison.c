
inherit "room/room";

#include "/players/mangla/defs.h"

object PREV;
int MAIL,QUIT;

int _remove(object play) {

    if(find_call_out("_remove") != -1) {
        remove_call_out("_remove");
    }
    if(ENV(play) == TO) {
        MOVE(play,PREV);
        TELLR(TO,play->NAME + " is removed.\n");
        TELL(play,"You are removed to your previous place.\n");
    }
    return 1;
}

int _comms(string str) {

    string VERB;
    string *st;
    object PL;
    int SET;

    SET = 1;

    VERB = query_verb();
    if(VERB == "say" || VERB == "nod" || VERB == "look"
                   || (VERB == "mail" && MAIL)
                   || (VERB == "quit" && QUIT)
                  || TP->query_immortal()) {
        SET = 0;
    }
if(VERB == "activate") {
/*
    if(VERB == "activate" && TP->query_immortal()) {
*/
        if(str == "mail") {
            MAIL = !MAIL;
            TELL(TP,"Mail has value: %d\n",MAIL);
            SET = 1;
        }
        if(str == "quit") {
            QUIT = !QUIT;
            printf("Quit has value: %d\n",QUIT);
            SET = 1;
        }
    }
        if(VERB == "bringto" &&  TP->query_immortal()) {
            st = explode(str," ");
            PL = find_player(st[1]);
            if(PL) {
                PREV = ENV(PL);
                TELLR(PREV,PL->NAME + " is whisked into the clouds.\n");
                MOVE(PL,"/players/mangla/rooms/prison");
                TELL(PL,"You have been imprisoned for wrong doing.\n");
                TELLR(TO,PL->NAME + " arrives.\n");
                if (TP->LEVEL < 33) {
                    TELL(TP,"You can only hold a player here for 5 minutes.\n");
                    call_out("remove",300,PL);
                }
                SET = 1;
            }
            else {
                write("That players is not on right now.\n");
                return 1;
            }
        }
        else if(VERB == "expel" &&  TP->query_immortal()) {
            st = explode(str," ");
            if(PL=present(st[1],TO)) {
                MOVE(PL,PREV);
                TELLR(TO,PL->NAME + " is removed.\n");
                TELL(PL,"You are removed to the last place you were.\n");
            }
            else printf("That person is not here.\n");
            SET = 1;
        }
    if(VERB == "quit" && QUIT) {
        SET = 0;
    }
    if (SET && !TP->query_immortal()) {
        printf("You are not allowed to do anything except listen\n" +
               "look and nod while you are here.\n");
        SET = 1;
    }
    return SET;
}


reset(arg) {

    if(arg) return;

    set_light(1);

    short_desc = "Prison";

    long_desc = "A prison where players cannot do anything except:\n" +
                "\tlook  say  nod\n";

    property=({"no_teleport","no_sneak","no_steal"});

    MAIL = 0;
    QUIT = 0;
}

init() {

    ::init();
    add_action("_comms","",2);
}



