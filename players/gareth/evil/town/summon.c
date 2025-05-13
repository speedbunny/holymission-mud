#include "/players/gareth/define.h"
inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {

     set_light(1);
     short_desc = "Summoning Room";
     long_desc = 
         "This room has been totally cut from the dark surrounding\n"+ 
         "rock. The stone work is much finer here than any other\n"+ 
         "room you've encountered in the underworld. The walls and\n"+ 
         "floors have been polished smooth. There is a large strange\n"+
         "blood red circle with symbols around it. There is an ivory\n"+
         "table in the corner with a statue on it.\n";
     
     items = ({
       "circle","a dark crimson colored circle",
       "floors","black and polished to a shine",
       "walls","black and polished",
       "symbols","^!*%% @)*% #!%!^!^%!( $!(!&!%!$",
       "table","Large Ivory table with a statue on it",
       "statue","made of crome and shaped like a black widow spider",
             });
     
     dest_dir = ({
      ETOWN+"chapel","northeast",
                });

}
}
