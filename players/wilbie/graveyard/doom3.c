inherit "/room/room";
#include "/players/wilbie/def.h"

object ob;
int counter;
reset(arg){
if (!arg) {
smell="It smells like death";

set_light(1);
short_desc="Depths of hell";
long_desc=
"You stand before a grotesque looking tree.  It bears oddly inviting "+
"fruit that you are somehow drawn towards with strange hunger.  "+
"Perhaps it could be of value to you?\n";

items=({
"fruit","It is actually rather inviting",
"tree","A grotesque looking thing",
});

dest_dir=({
GPATH+"doom2","east",


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
                      if(counter<=6) {
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
