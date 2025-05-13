inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/
object monst;

reset(arg){

   if(!arg){

   set_light(1);

   short_desc="Before the idol";
   long_desc="You are standing before the ancient altar.  Behind "+
             "the altar stands a massive stone idol.  There are great black "+
             "tapestries all around the altar and idol, which bear runes "+
             "of arcane magical nature.  Some strange writing has been "+
             "scratched into the altar surface, seemingly very recently.\n";
    items=({"writing","It reads: Do not approach the idol...  Death awaits "+
                      "thee if you dare",
   "idol","It is a horrific looking figure with six arms, and has the face "+
                  "and body of a woman.  Each arm holds a black sword",
           "hallway","It is too dark to see very far",
   "thread","It is golden thread, sewn into the tapesties",
           "tapestries","They are covered in arcane runes",
           "altar","It is old stone, with faint stains of red",
           "runes","You cannot make out what the runes say",
             });

    dest_dir=({
               GPATH+"nave3","south",
               GPATH+"altar2","north",
       });
   }
::reset(arg);
 }



void init(){
::init();
add_action("read","read");
}           

int read(string str){
if(str=="writing")     {
write("It reads: Beware the idol!!  Do not approach too near!\n");
return 1;
                       }
if(str=="runes")           {
write("You are suddenly somewhere else!!\n");
this_player()->move_player("in a wift of smoke",GPATH+"w_grave5");
return 1;
                           }
notify_fail("Read what??\n");
return 0;
}
