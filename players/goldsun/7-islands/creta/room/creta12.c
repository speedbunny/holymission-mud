inherit "/players/goldsun/7-islands/creta/room/creta9";
#define PATH "/players/goldsun/7-islands/creta/room/"

void reset(int arg){
 ::reset(arg);
if (!arg){
 long_desc=
  ("You are in the dense forest south of Idhe. Many trees of\n"+
   "undefined kinds grows up to sky. They have to been here for thousands\n"+
   "of years. The ground is covered by grass and moss. A steam in the branches\n"+ 
   "above and sunbeams make fantastic figures.\n"
  );
 items-=({"mountains","Madaros to the west and Idhe to the east",
          "mountain","Madaros to the west. It is very high",
          "idhe","Idhe to the east. It is very high mountain"});

 items+=({"mountain","Idhe to the north. It is very high",
          "idhe","Idhe to the north. It is very high mountain"});

 dest_dir=({ PATH+"creta10", "west",
	     PATH+"creta16","east"
	   });

 }
}

