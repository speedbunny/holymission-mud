static variables inherit "/obj/thing";

#include "/players/sauron/include/include.h"

#define DEST	"/room/church"
#define FILE	"/players/sauron/data/treeNames"

string *saNames,*saCards;

void saveTree() {
    save_object(FILE);
}

void restoreTree() {
    if(!restore_object(FILE)) {
        saNames = ({});
        saCards = ({});
        saveTree();
    }
}

void getCard(object oOb) {
    object oCard;

     if(oOb)
        tell_object(oOb, "oOb = "+file_name(oOb)+"\n");                
    if(oOb && interactive(oOb) &&
       member_array(CRNAME(oOb), saCards) == -1) {
        saCards += ({CRNAME(oOb)});  
        oCard = CO(CLONE+"XmasCard");
        MOVE(oCard, oOb);
        TELLO(oOb, "You are given a Christmas card from The Dark Lord \
Sauron. Remember to thank him!\n");
        saveTree();
    }
}

void catch_tell(string sStr) {
    string x;

    if(sscanf(sStr, "%s enters the game.", x) == 1) {
        printf("TP = %s\n", file_name(TP));
        call_out("getCard", 1, TP);
    }
}

void run_away() {
    return;
}

int decorateTree(string sStr) {
    if(!sStr || sStr!="decoration on tree") {
        NF("Hang what on what?\n");
        return 0;
    }
    else if(!TP || !interactive(TP))
        return 0;
    else if(member_array(CRNAME(TP), saNames) != -1) {
        WRITE("You've already hung a decoration on the tree.\n");
        return 1;
    }
    else if(RNAME(TP) == "guest") {
        WRITE("Guest is such an ambiguous name don't you think? \
Perhaps you should think up something more original so people will \
know who you are.\n");
        return 1;
    }
    else if(LEVEL(TP) < 2) {
        WRITE("Maybe you should play a little first so people would know \
who you were.\n");
        return 1;
    }
    else {
        saNames += ({CRNAME(TP)});
        WRITE("You select a nice decoration from the box at the foot of \
the tree and hang it on a branch.\n");
        say(lw(CNAME(TP)+" takes a decoration from the box at the foot of \
the tree and hangs it from a branch.\n"));
        saveTree();
        return 1;
    }
}

void notify_destruct() {
    saveTree();
}

void long() {
    string sRet;
    int    iSz;

    iSz = sizeof(saNames);
    sRet = "Before you stands a large Christmas tree. It has a plethora of \
green branches, all covered with sparkling baubles, shiny tinsle and \
many other beautiful decorations. There is a long string of \
multi-coloured, flashing lights wrapped several times around the tree \
from top to bottom. ";
    if(iSz > 10)
        sRet += "You notice that several players have added a decoration \
to the tree. Each one has their name on it: there is one each for "
+listArray(saNames);
    else if(iSz > 2)
        sRet += "You notice that a few players have added a decoration \
to the tree. Each one has their name on it: there is one each for "
+listArray(saNames);
    else if(iSz > 1)
        sRet += "You notice that two players have added a decoration \
to the tree. Each one has their name on it: there is one each for "
+listArray(saNames);
    else if(iSz)
        sRet += "You notice that only "+saNames[0]+" has added a \
decoration to the tree.";
    else
        sRet += "You notice that no-one has added a decoration to the tree \
yet - maybe you could be the first!";

    sRet += " At the foot of the tree there is a box full of \
decorations. Maybe you could 'hang decoration on tree' yourself.\n";
    WRITE(sRet);
}

void reset(int iArg) {
    ::reset(iArg);
    if(!iArg) {
        id("xmas_tree");
        set_name("A tall Christmas Tree");
        set_alias("tree");
        set_short("A tall Christmas Tree");
        set_weight(1);
        set_value(0);
        set_can_get(0);
        restoreTree();
        MOVE(TO, DEST);
        enable_commands();
    }
}

void init() {
    ::init();
    if(TP && interactive(TP))
        add_action("decorateTree", "hang");
}
