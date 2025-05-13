inherit "/room/room";
#include "../cellar.h"
#include "/obj/door.h"
#define HOLE ROOM+"c7"

object obj_1,obj_2,key;
int ok;

reset(arg) {
    ok=1;

    if (!arg) {
        set_light(0);
        short_desc= "In a cellar";
        long_desc=
                  "You are in the dark cellar of the Mages Tower.\n"+
                  "It's cold and wet here and the smell of cheese\n"+
                  "gets stronger and stronger. There is a little\n"+
                  "hole in the eastern wall. The corridor leads \n"+
                  "further to the north and west.\n";
   
        dest_dir = ({
                   ROOM+"c1","north",
                   ROOM+"c5","west"
                   });
   
        items = ({
                  "vault","An old oak-wooden vault",
                  "hole","A little dark hole in the eastern wall\n"+
                         "looking like a rat hole",
                  "wall","A grey stone wall",
                  "walls","Grey stone walls",
                  "bottom","A dark stone bottom"
                 });
         MAKE_DOORS(ROOM+"c6","west",ROOM+"c5","east","iron","cellardoor",
               "It looks like a normal wooden cellar door.\n", 1, 1, 1);
    } 
    if(obj_1) {
        obj_1->set_closed(1);
        obj_1->set_locked(1);
        obj_1->set_both_status();
    }
}

init() {
    ::init();
    if (this_player()->query_npc() && this_player()->id("rat")) 
        add_action("east","east");
    else add_action("enter","enter");
    add_action("use","use");
}

enter(arg) {
    if(arg=="hole") {
        if(this_player()->query_size()!=1) {
            write("You're much too fat to enter the rathole.\n");
            say(this_player()->query_name()+
                " tries foolishly to squeeze into the rathole.\n");
	} else {
            write("You squeeze yourself into to rathole.\n");
            this_player()->move_player("into the rathole#"+ROOM+"c7");
        }
        return 1;
    }
}

east() {
   return enter("hole"); 
}

chk_cheese() {
    if(!present("cheese",this_player())) {
        write("You have no cheese.\n");
        return 0;
    }
    return 1;
}

use(arg) {
    object it,rats,hole;
    string item;
    int i,rnr;

    if(arg=="cheese") {
        if(!chk_cheese()) return 1;
        write("On What ?\n");
        return 1;
    }
    if(arg=="cheese on rathole" || arg=="cheese on hole") {
        if(!chk_cheese()) return 1;
        if(hole=find_object(HOLE))
           rats=all_inventory(hole);
        for(i=rnr=0;i<sizeof(rats);i++) if(rats[i]->query_npc()) rnr++;
        if(rnr<1) {
            write("Nothing happens.\n");
            say(this_player()->query_name()+" uses some cheese on the rathole "+
                "but nothing happens.\n");
        } else {
            tell_room(this_object(),"You hear some squeeking.\n");
            for(i=0;i<sizeof(rats);i++) {
                if(random(2) && rats[i]->query_npc()) 
                    rats[i]->move_player("west#"+ROOM+"c6");
            }
        }
        return 1;
    }
    if(arg && sscanf(arg,"%s on rathole",item)==1) {
        if(!(it=present(item,this_player()))) {
            write("You don't have the "+item+".\n");
            return 1;
        }
        write("You can't use the "+it->short()+" on the rathole.\n");
        say(this_player()->query_name()+" tries to use the "+it->short()+ 
            " on the rathole.\n");
        return 1;
    }
}
