// Original code by Sherman of Holy Mission //
// Re-coded and enhanced by Jewel of Holy Mission, May 1996 //

/* Cashimor, 5-2-1993, I moved your castle a little southward, to make
   the clash with Padrone's castle a little less... The church was
   lying right next to the peaceful pool... */

inherit "room/room";

int open;

reset(arg) {
    ::reset();
    if(open) {
        close_door();
        "players/jewel/quest/tunnel1"->close_door();
    }
    if(arg) return;
    set_light(1);
    short_desc="At a small hill";
    long_desc=
        "You are at the top of a small hill.\n"+
        "All around you are trees and bushes. The only way out seems\n"+
        "to be the path where you entered. It's strangely quiet here!\n";
    items = ({
        "hill","The hill is covered with grass and bushes",
        "trees","The trees are thick and green, hiding everything",
        "tree","A beautiful oak",
        "path","The path is leading west through the bushes",
        "top","There are some bushes at the top of the hill",
        "bush","There are several bushes",
        "bushes","There are several bushes, but one bush at the\n"+
                 "top of the hill seems to be darker than the others",
        "dark bush","A thick strange, ominous dark bush at the top of the hill",
            });
    dest_dir = ({"/room/south/sforst16","west"});
}

init() {
    ::init();
    add_action("west","west");
    add_action("search","search");
    add_action("down","down");
    add_action("open","open");
    add_action("close","close");
}

open(arg) {
    if(arg!="trapdoor") return;
    if(open) write("It is already open.\n");
    else {
        write("You open the trapdoor\n");
        say(this_player()->query_name()+
            " moves something inside the bushes.\n");
        "players/jewel/quest/tunnel1"->open_door();
        open=1;
    }
    return 1;
}

close(arg) {
    if(arg!="trapdoor") return;
    if(!open) write("It is already close.\n");
    else {
        write("You close the trapdoor\n");
        say(this_player()->query_name()+
            " moves something inside the bushes.\n");
        "players/jewel/quest/tunnel1"->close_door();
        open=0;
    }
    return 1;
}

close_door() {
    open=0;
    tell_room(this_object(),"Something moves behind the bushes.\n");
}

open_door() {
    open=1;
    tell_room(this_object(),"Something moves behind the bushes.\n");
}

west() {
    write("You struggle through the bushes.\n");
    this_player()->move_player("through the bushes#room/south/sforst16");
    return 1;
}

search(arg) {
    if(arg=="dark bush") {
        write("You notice a trapdoor hidden in the bush.\n");
        return 1;
    }
}

down() {
    if(!open) return;
    this_player()->move_player("disappears into the bushes#"+
                               "players/jewel/quest/tunnel1");
    return 1;
}

query_open() { return open; }

