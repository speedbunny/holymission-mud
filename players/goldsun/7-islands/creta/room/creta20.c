inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
if (arg) return;
 short_desc=("Cape Syderos");
 long_desc=
   "You stand on the white cliff on the northeastern coast of Creta. This\n"+
   "place is called 'Cape Syderos'. The cliff is 200 feets high and there\n"+
   "are no trees or bushes on it. Only small bunches of grass are growing\n"+
   "up on same places. Huge waves are rolling towards the cliff. Far\n"+
   "the inland you can see tall mountains. Your hair is waving in the breeze.\n";
  
 items+=({"cliff",long_desc,
          "cape",short_desc,
          "grass","A bunch of green grass. It is waing in the wind"
         });
 dest_dir=({ PATH+"creta19", "south"
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
