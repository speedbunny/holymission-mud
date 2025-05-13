inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
 if (arg) return;
 long_desc=
   "You are standing on the coast of the Creta. The ground\n"+
   "consists of rock and sand. Huge waves are rolling towards\n"+
   "the island and you get a peaceful feeling. You can see tall\n"+
   "Idhe to the south and a town to the east.\n";
  
 items-=({"mountains","Madaros and Idhe. They are very high"});
 items+=({"mountain","Tall mountain to the southt. It's named Idhe",
          "idhe","It is tall mountain to the south",
          "town","A town to the east"});
 
 dest_dir=({ PATH+"creta8", "west",
	     PATH+"creta15", "southeast",
	     PATH+"creta14", "east"
	   });
  
}
