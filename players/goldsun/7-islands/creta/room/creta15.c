inherit "/players/goldsun/7-islands/creta/room/genCoast";
#define PATH "players/goldsun/7-islands/creta/room/"

reset(arg){
 ::reset(arg);
 if (arg) return;
 long_desc=
   "You are standing on the coast of the Creta. The ground\n"+
   "consists of rock and sand. Huge waves are rolling towards\n"+
   "the island and you get a peaceful feeling. You can see tall\n"+
   "Idhe to the west and a town to the north.\n";
  
 items-=({"mountains","Madaros and Idhe. They are very high"});
 items+=({"mountain","Tall mountain to the west. It's named Idhe",
	  "town","A town to the east",
          "idhe","It is tall mountain to the west"});
 
 dest_dir=({ PATH+"creta14","north",
             PATH+"creta11","northwest",
	     PATH+"creta16","south",
	     PATH+"creta17","east"
	   });
  
}
