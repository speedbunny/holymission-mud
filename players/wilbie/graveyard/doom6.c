inherit "/room/room";
#include "/players/wilbie/def.h"
object ob;
int counter;

reset(arg){
if (!arg) {

set_light(1);
short_desc="Depths of hell";
long_desc=
"You are standing in the depths of hades.  To the north, a small path "+
"leads to some sort of structure.  West there is a small checkpoint "+
"set up to capture foolish mortals.  Low to the horrid ground there "+
"is a grotesque "+    
"looking tree.\n";



items=({
"fire","It is the fire of hades",
"tree","It bears strange looking fruit",
"fruit","It looks rather inviting",
"path","A small path leading north",
"structure","A small shrine to the evil goddess Sheankala",
"checkpoint","A ragged checkpoint",


});

dest_dir=({
GPATH+"doom7","east",
GPATH+"doom8","north",
GPATH+"doom5","west",


});

}
::reset(arg);
}


void init(){
   ::init();
   add_action("pick","pick");
           }

int pick(string str) {
                     if(str=="fruit") {
                     if(counter<=6)   {
       ob=clone_object("/players/wilbie/graveyard/fruit");
       transfer(ob,this_player());
       write("You picked some fruit.\n");
       counter++;
                                      }
       else write("The tree is empty.\n");
       return 1;
                                      }
       notify_fail("Pick what??\n");
       return 0;
                    }
