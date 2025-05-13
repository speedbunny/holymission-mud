inherit "/room/room";
#include "/players/goldsun/stand.h"

reset(arg){
if (!arg){
 set_light(1);
 short_desc=("On a meadow");
 long_desc=
   ("You are standing on the beautiful green meadow. The grass is\n"+
    "waving in the wind and the drops of dew are shining in the sunbeams.\n"+
    "Fresh air gives you a pleasant feeling. If you didn't know you\n"+
    "are on the Green Island, you would think you are in the paradise.\n");

 smell="You smell fresh air.";

 items=({"grass","A very nice grass with drops of dew",
	 "drops","The drops of dew. They looks like diamonds"
	  
         });
  }
 ::reset(arg);
}

 init(){
  ::init();
  add_action("lsten","listen");
  }

 lsten(){
      write("You can hear a sheep sound.\n"); 
  return 1;
  }              

