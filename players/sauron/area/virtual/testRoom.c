inherit "/players/sauron/inherit/virtualRoom";

#include "/players/sauron/include/include.h"

string variableLong() {
    string sMsg, *saDirs;
    int    iTmp, i, j, d;

    saDirs=m_indices(queryVirtualExits());
    iTmp=(sizeof(query_dest_dir())/2)-sizeof(saDirs);
    switch(sizeof(saDirs)) {
        case 0:
            sMsg="\
You appear to be trapped in here as there are no virtual exits leading \
from this room!"
+(iTmp?
    " It's a good job that there "
    +(iTmp==1?
        "is 1 exit":
        "are "+iTmp+" exits")
    +" to the real world here...":
    "");
            break;
        case 1:
            sMsg="\
You have reached a dead end in the virtual area you are exploring."
+(iTmp?
    " However, there "
    +(iTmp==1?
        "is 1 exit":
        "are "+iTmp+" exits")
    +" to the real world here...":
    "");
            break;
        case 2:
            i=dirName(saDirs[0]);
            j=dirName(saDirs[1]);
            d=j-i;
            if(d<0)
                d=-d;
            sMsg="\
You are walking down a passageway in the virtual area you are exploring. \
The passageway "
+(d==4?
    "runs "+saDirs[0]+"-"+saDirs[1]+".":
    (d==3 || d==5?
       "curves slightly.":
       (d==2 || d==6?
          "bends at right angles.":
          (d==1 || d==7?
             "almost doubles back on itself.":
             "doubles back on itself? That can't be right!"))))
+(iTmp?
    " There "
    +(iTmp==1?
        "is 1 exit":
        "are "+iTmp+" exits")
    +" to the real world here...":
    "");
            break;
        default:
            sMsg="\
You have arrived at a "
+sizeof(saDirs)+"-way junction in the virtual area you are exploring."
+(iTmp?
    " There "
    +(iTmp==1?
        "is also 1 exit":
        "are also "+iTmp+" exits")
    +" to the real world here...":
    "");
            break;
    }

    return sMsg+"\nThere isn't much here right now... sorry. :)\n";
}

void reset(int iArg) {
    if(!iArg) {
        set_light(1);
        short_desc="A virtual room.";
        long_desc="@@variableLong@@";
    }
    ::reset(iArg);
}
