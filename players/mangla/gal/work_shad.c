inherit "/players/whisky/obj/std_shadow";
#include "/players/mangla/defs.h"

int catch_tell(string str) {

    string blah,blah1;

    if(sscanf(str,"%s shouts: %s",blah,blah1)==2 ||
       sscanf(str,"%s bellows %s",blah,blah1)==2 ||
       sscanf(str,"%s bellowing %s",blah,blah1)==2 ||
       sscanf(str,"%s bawls: %s",blah,blah1)==2) {
        return 0;
    }
    write(str);
    return 1;
}

int is_invis_for(object pl)
{
    if(pl->LEVEL > me->LEVEL) return 0;
     return 1;
}

int work_shad()
{
    return 1;
}

object work_object()
{
     return this_object();
}

