#define CENTRAL_HARBOUR "players/goldsun/gen/room/central_harb"

inherit "players/goldsun/gen/obj/boat";

reset(arg){
 ::reset();
 if (arg) return;
  set_name("pinta");   

  set_long("Pinta is small boat.\n");

  voyage=({"players/goldsun/lank/room/coast1",53,  
    
	   "players/goldsun/example/my_harbour",58});

  destination("players/goldsun/example/pintaroom"); /* where we move traveler */
  anchor_time=40; 
  arr_time=8;    
  msgin=capitalize(name)+" arrives to harbour.\n";
  msgout=capitalize(name)+" leaves.\n";
  sailor_msgout=capitalize(sailor_name)+" says: We are leaving.\n";
  sailor_msgin=capitalize(sailor_name)+" says: We are landing.\n";
  set_preinfo(capitalize(sailor_name)+" says: "); 
  transfer(this_object(),CENTRAL_HARBOUR); /* to start this boat */
 }


