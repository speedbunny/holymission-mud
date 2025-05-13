inherit "room/room";

#include "/players/darastor/include/defs.h"
#include "/players/darastor/include/linewrap.h"

string listen_str;

int _listen(string str)
{
    if(str)
        return 0;
        
    TELL_OBJECT(TP,listen_str);
    say(CNAME+" listens intently.\n",TP);
    return 1;
}

void init()
{
    ::init();
    add_action("_listen","listen");
}
