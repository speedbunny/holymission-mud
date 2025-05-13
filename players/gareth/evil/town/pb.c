#include "/players/gareth/define.h"
inherit "room/room";
  object bag;

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_light(1);
     short_desc = "Priest's Bed Chamber";
     long_desc = 
       "This is the private chamber of the evil priest. There\n"+ 
       "are lavish furnishings here, although none are of \n"+ 
       "particular value. The room is decorated with a blood red\n"+ 
       "carpet, furniture of black wood with velvet upholstery\n"+
       "of scarlet, and a large bed covered with silken covers of\n"+
       "black and red cushions and pillows. A spider idol leers\n"+
       "from the wall to the north, directly over the bed.\n";
     
     dest_dir = ({
       ETOWN+"temple","west",
  
     });
  MO((CO(ITEM+"bag3")), TO);

}
}
