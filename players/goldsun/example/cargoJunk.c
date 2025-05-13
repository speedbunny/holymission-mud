/* A cargo junk, recoded from /players/patience/ezo/cargoJunk.c */

inherit "players/goldsun/gen/obj/boat";

#define CENTRAL_HARBOUR "players/goldsun/gen/room/central_harb"


void reset(int arg){
 ::reset();
 if (arg) return;
  set_name("cargo junk");   
  set_short("A cargo junk");
  set_long("You are on a cargo junk. The junk is made of wood and it is in a good\n" +
   "condition. In the middle of the junk can you see the mast with big yards,\n" +
   "great sails and strong shroud. Many sailors are running around and\n" +
   "are busy doing something and at the back of the ship stands the captain.\n");
  sailor_name="captain";

  voyage=({"room/sea",55,
             "players/patience/ezo/coast/c1",65});

  destination("players/patience/ezo/cargoroom"); /* here we move traveler */

  anchor_time=35; /* anchoring time in every harbour */
  arr_time=20;     /* time to arrive from central harbour */

  msgin=capitalize(name)+" arrives.\n";
  msgout=capitalize(name)+" is sailing away.\n";
  sailor_msgout=capitalize(sailor_name)+" says: We are sailing on.\n";
  sailor_msgin=capitalize(sailor_name)+" says: We are landing.\n";

  set_preinfo(capitalize(sailor_name)+" says: ");
                  /* if you use this function, message between " " */
	 	  /* +short_desc of harbour will written after sailor_msgin.*/
	          
  transfer(this_object(),CENTRAL_HARBOUR); /* to start this boat */
 }
