inherit"room/room";
#include "/players/wilbie/def.h"
/*Wilbie*/

reset(arg){

   if(!arg){

   set_light(1);

   short_desc="Inside an ancient church";

   long_desc="You stand in the center of a huge open cathedral.  The "+
             "floor here is stained with recently dried blood.  "+
             "It looks like something - or someone - was killed here.  "+
             "The cathedral looms oppressively on all sides, and to the "+
             "north is a massive stone idol\n";


   items=({"walls","They are ancient walls of granite",
           "idol","It is the statue of a large demon of some sort..",
           "floor","It is covered in almost dried blood",
           "center","It is where you are standing",
           "someone","They are no longer with us",
           "something","It was probably dragged away by what killed it",
           "cathedral","You are in the cathedral",
           "pillars","They are of black polished granite",
           "cathedral","It is a very large cathedral of granite",
           "hallway","It is too dark to see very far..",
           "blood","There is a lot of it dried all over the place",
             });

    dest_dir=({
               GPATH+"nave1","south",
               GPATH+"w_nave2","west",
               GPATH+"e_nave2","east",
               GPATH+"nave3","north",
       });
  clone_list=({
  1,1,"spirit","/players/wilbie/graveyard/monsters/spirit",0,


 -1,1,"letter","/players/wilbie/graveyard/obj/letter",0,

  });
  ::reset();
   }
::reset(arg); replace_program("/room/room");
 }
