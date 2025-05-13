inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
if (arg) return;
 short_desc=("Cape Lithinon");
 long_desc=
  ("You are standing on the southern coast of the Creta. This is cape\n"+
   "Lithinon. The ground consists of rock and sand. Huge waves are rolling\n"+
   "towards the island and you get a peaceful feeling. Far in the inland\n"+
   "you can see tall mountains.\n" 
  );
 dest_dir=({ PATH+"creta10", "northwest",
	     PATH+"creta16", "northeast"
	   });
  
}
