inherit "/room/room";
#include "../cellar.h"
object ob;
int i;

reset(arg) {
    if (!arg) {
        set_light(0);
        short_desc= "In a cellar";
        long_desc=
                  "You are in the dark cellar of the Mages Tower.\n"+
                  "It's cold and wet here. The smell of cheese is\n"+
                  "now so strong, that you can feel some drops of\n"+
                  "salive running down your mouth. There is a wooden\n"+
                  "shelf on the western wall. The corridor leads \n"+
                  "to the east.\n";
   
        dest_dir = ({
                   ROOM+"c6","east",
                   });
   
        items = ({
                  "vault","An old oak-wooden vault",
                  "shelf","A brown wooden shelf",
                  "wall","A grey stone wall",
                  "walls","Grey stone walls",
                  "bottom","A dark stone bottom"
                 });
    } 
    if (!ob) {
         ob=clone_object(MONST+"big_rat");
         move_object(ob,this_object());
     }
}

init() {
    ::init();
    add_action("search","search");
}

search(str) {
    object ob,cheese;

    ob=present("rat",this_object());
    if (str=="shelf" || str=="in shelf") {
        write("You found a piece of cheese.\n");
        cheese=clone_object(OBJ+"cheese");
        if(transfer(cheese,this_player())) {
            write("You are carrying too much.\n");
            destruct(cheese);
            return 1;
        }
        if(ob) {
            this_player()->attacked_by(ob);
            return 1;
        }
        return 1;
    }
}

