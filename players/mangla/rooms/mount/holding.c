inherit "room/room";

#include "/players/mangla/defs.h"

int ACK = 0;

void tempchange() {

    int i,sipl,temp;
    object *pllist;
    object ob;

/*
    sscanf(arg,"%d",temp);
    ACK = temp;
*/
    ACK = 1;
    TELL(find_living("mangla"),"Changing around stuff.\n");
    if (ACK) {
        ob = find_object("/players/mangla/rooms/mount/rock");
        pllist = ALL(ob);
        sipl = sizeof(pllist);
        for(i=0 ; i < sipl ; i++)
            MOVE(pllist[i],TO);
        destruct(ob);
        pllist = ALL(TO);
        call_other("/players/mangla/rooms/mount/rock", "???");
        ob = find_object("/players/mangla/rooms/mount/rock");
        for(i=0 ; i < sipl ; i++)
            MOVE(pllist[i],ob);
    }
    return;
}

int tempstore() {

    return ACK;
}


void reset(int arg) {

    ::reset();
/*
    replace_program("room/room");
*/
}
