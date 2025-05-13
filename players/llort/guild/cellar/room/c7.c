inherit "/room/room";
#include "../cellar.h"

object ob;
int i,rnr;

reset(arg) {
    if (!arg) {
        set_light(0);
        short_desc= "In a cellar";
        long_desc=
                  "You have entered the rat hole of the Mages Tower.\n"+
                  "It's the place where the rats flee if they are hunted.\n"+
                  "The whole room smells after bred wood. A little hole\n"+
                  "leads out to another place.\n";
   
        dest_dir= ({
                  ROOM+"c6","west"
                  });
   
        items = ({
                  "vault","An old oak-wooden vault",
                  "hole","A small hole in the western wall",
                  "wall","A grey stone wall",
                  "walls","Grey stone walls",
                  "bottom","A dark stone bottom"
                 });
        for(i=0;i<5;i++) move_object(clone_object(MONST+"rat"),this_object());
    } 
    ob=all_inventory(this_object());
    for(i=rnr=0;i<sizeof(ob);i++) if(ob[i]->query_npc()) rnr++;
    if(rnr<20) {
        for(i=0;i<5;i++) move_object(clone_object(MONST+"rat"),this_object());
    }
}

init() {
    ::init();
    add_action("enter","enter");
    add_action("leave","leave");
    add_action("leave","crawl");
}

enter(str) { 
   if (str=="hole" || str=="the hole") {
       this_player()->move_player("through the hole#"+ROOM+"c6");
       return 1;
   }
}

leave(str) {
    if (str=="hole" || str=="through the hole" || str=="the hole") {
        this_player()->move_player("through the hole#"+ROOM+"c6");
        return 1;
    }
}

