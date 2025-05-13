/*     EXAMPLE OF BOAT alias dragon alias xyz ...
*/
#define CENTRAL_HARBOUR "players/goldsun/gen/room/central_harb"

inherit "players/goldsun/gen/obj/boat";

reset(arg){
 ::reset();
 if (arg) return;
  set_name("atlanta");   

  /* if you want to make dragon, set_name(<name of your dragon>) &
     set_alt_name("dragon") !!!
  */

  set_long("This is Great Atlanta the boat.\nYou can enter it.\n");

  voyage=({"players/goldsun/lank/room/coast1",53,  
    
	   "players/goldsun/example/my_harbour",58});

  destination("players/goldsun/example/my_aboard"); /* where we move traveler */
  anchor_time=40; /* anchoring time in every harbour */
  arr_time=8;     /* time to arrive from central harbour */

  msgin=capitalize(name)+" arrives to harbour.\n";
  msgout=capitalize(name)+" leaves.\n";
  sailor_msgout=capitalize(sailor_name)+" says: We are leaving.\n";
  sailor_msgin=capitalize(sailor_name)+" says: We are landing.\n";

   /* next function is optional. */

  set_preinfo(capitalize(sailor_name)+" says: "); 
                  /* if you use this function, message between " " */
	 	  /* +SHORT_DESC of harbour will written after sailor_msgin.*/
  transfer(this_object(),CENTRAL_HARBOUR); /* to start this boat */
 }


