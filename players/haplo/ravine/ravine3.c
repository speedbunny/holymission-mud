inherit "room/room";
#include "/players/haplo/defs.h"

object ob;

reset(arg)
{
    if(arg) return;

    set_light(1);
    short_desc= "Ravine";
    long_desc=
     "This part of the ravine is somewhat rougher and the cliff walls are not\n"+
     "as smooth here. There is debris littering the path which has fallen\n"+
     "from the cliffside. There are tiny holes covering the walls. The path\n"+
      "continues in both a north and south direction.\n"; 
    items=({
       "debris","The debris has been falling for years, hope nothing falls on you!!",
    "walls","The cliff is covered in holes which you might use to climb the cliff",
   "cliffs","The cliff is covered in holes which you might use to climb the cliff",
      "holes", "Holes in the wall that could allow oyu to climb",
      "cliffside", "Has some holes in it that might allow oyu to climb the cliff",
    });

  property=  ({
          });
    dest_dir=({
       "/players/haplo/ravine/ravine2","south",
        "/players/haplo/ravine/ravine4","north"
    });
      ob=clone_object("/players/haplo/ravine/skeleton");
     move_object(ob,this_object());
}

init(){
    ::init();
      add_action("_climb","climb");

}
    _climb(string str){
     if (str=="cliff" || "wall"){
      move_object(this_player(),"/players/haplo/ravine/clifftop");
      write("You shimmy up the side of the cliff using small hand holds.\n");
      return 1;
     }
   else{
    notify_fail("You can't climb that!\n");
    }
   }

