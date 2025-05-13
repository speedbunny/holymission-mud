inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
 if (arg) return;
 long_desc=
  ("You are standing on the coast of the Creta. The ground\n"+
   "consists of rock and sand. Huge waves are rolling towards\n"+
   "the island and you get a peaceful feeling. Far inland\n"+
   "you can see tall mountains. The coast runs past white cliffs\n"+
   "to the north.\n" 
  );
 
 items+=({"cliff","A cliff to the north"});
 dest_dir=({ PATH+"creta20", "north",
	     PATH+"creta18", "southwest"
	   });
  
}
