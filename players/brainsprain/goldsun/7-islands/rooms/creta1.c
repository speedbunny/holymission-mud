inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";

#include "/players/brainsprain/goldsun/7-islands/isdef.h"
void reset(int arg){
 ::reset(arg);
if (arg) return;
 short_desc=("Cape Krios");
 long_desc=
"You are standing on the northern coast of Creta Island.  This section "+
"is called the Cape of Krios.  The ground consists of rock and "+
"sand.  Huge waves are rolling towards the island and you get a peaceful "+
"feeling.  Far inland you can see tall mountains.\n";
 dest_dir = ({
    ir+"/creta2","south",
    ir+"/creta5","southeast",
	   });
  
}
