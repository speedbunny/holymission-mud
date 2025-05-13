inherit "/players/brainsprain/goldsun/7-islands/rooms/cgenCoast";
#include "/players/brainsprain/goldsun/7-islands/isdef.h"

void reset(int arg){
 ::reset(arg);
 short_desc=("Cape Syderos");
 long_desc=
"You stand next to the white cliffs which line the northeastern coast of "+
"Creta. This place is called Cape Syderos.  The cliff is over 200 feet "+
"high and there are no trees or bushes on it.  Only small bunches of "+
"grass are growing on its face.  Far the inland you can see tall "+
"mountains.\n";

 items =({ 
   "cliffs",long_desc,
   "cape",short_desc,
   "grass","A bunch of green grass. It is waving in the wind"
      });
 dest_dir=({ 
   ir+"/creta19", "south"
      });
  
}

init(){
 ::init();
 add_action("lsten","listen");
}

 enter(arg){   return; }

 drink(arg){   return; }

 do_get(str){  return; }

 swim(){       return; }
