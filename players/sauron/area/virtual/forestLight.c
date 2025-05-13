inherit "/players/sauron/inherit/virtualRoom";

#include "/players/sauron/include/include.h"

string variableLong() {
    string sMsg;

    if(VERB == "look")
        sMsg = "You are standing in ";
    else
        sMsg = "You are wandering in ";

    sMsg+= "a forest. All around you tall oak and leatherleaf \
tower overhead, their gnarled and twisted branches brushing your face. \
Amongst them pine trees force their way through the mass of branches, \
reaching for the sky. Snarls of bramble spread brown webs over stone \
outcrops under the trees. Strangely enough though, no birds sing in the \
forest, no squirrels chitter on the branches and there is no movement \
whatsoever amongst the trees.\n";
    return sMsg;
}

void reset(int iArg) {
    if(!iArg) {
        set_light(1);
        short_desc="Somewhere in a dense wood.";
        long_desc="@@variableLong@@";
    }
    ::reset(iArg);
}
