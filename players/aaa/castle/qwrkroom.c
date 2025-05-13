#include "std.h"

inherit "room/room";


void reset(int arg) {
    ::reset(arg);
    if(!arg) {
    set_light(1);
    short_desc="The workroom of a Aaa";
    long_desc="The quasi-workroom of Wizard Aaa. Under construction. \n"+
              "The Elemental of the Earth is doing the foundation works \n"+
              "currently. \n";
    dest_dir=({"/players/aaa/castle/ante_dem.c","down"});
    }
}

void init() {
    ::init();
    add_action("move_up","up");
}
        
int move_up() {
   if (lower_case(this_player()->query_real_name())) 
     this_player()->move_player("up#/players/aaa/workroom.c");
   else { write("You bang Your head on the ceiling! \n");}  
   return 1;
}
                        	
