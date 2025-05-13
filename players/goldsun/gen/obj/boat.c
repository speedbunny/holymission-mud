/*     GENERAL BOAT of east sea kingdom coded by: Goldsun  
 
     note: You can use this system in every net-transport like:
     dragon airlines, magic carpet, animal trafics ....
    

  DOCUMENT : 

       variable voyage == list of harbours and time distance

       voyage=({"room/sea1",21,"room/island/coast",14})     
 
                 it means: room/sea1.c         is harbour1
	 		   room/island/coast.c is harbour2
		  
                  time to come from harbour1 to harbour2 is 21 sec    
	   		       from harbour2 to harbour1 is 14 sec    
	          
       anchor_time = how long is the ship in every harbour
       arr_time    = how long is the way from central harbour to harbour
	              in voyage list
                      (central harbour is master object and commands all
				ships in its list
			  !!! if you code new ship, it have to
		              be added into :
	               players/goldsun/gen/room/central_harb.c
	                in variable boat_file !!! )
                     
See EXAMPLE of boat         in [players/goldsun/example/my_boat.c]   
            of harbour      in [players/goldsun/example/my_harbour.c]
            of boat_room (it is a room where we move travelers)
                            in [players/goldsun/example/my_aboard.c]

 Hint: How to make messages like: "A birds pass around" or
				  "Lovely frsh air blows to your face" atc.?
  See example in [players/goldsun/example/my_talker.c]

 Any bug, idea, typo mail to Goldsun.

*/

inherit "/obj/thing";
#define TO this_object()
#define HAR(x,y) tell_room(x,y)
#define CENTRAL_HARBOUR "players/goldsun/gen/room/central_harb"
#define SEA "/players/goldsun/gen/room/rest_sea.c"

mixed   voyage;    
string  sailor_name, msgin, msgout, sailor_msgin, sailor_msgout, dest,
	preinfo;   
int     anchor_time, here, arr_time, is_harbour;


no_clean_up(){ return 1; }

int id(string str) {
  return  str == name || str == alias_name || str == alt_name ||
		str=="object of east sea kingdom";
}


void sailor_s(string str){   /* tell to player(s) on the boat str. If  */
  tell_room(dest,str);       /* you use more than 1 room, owerwrite    */
}                            /* this function in your file.            */
		 	     /* See also: Query_traveler() ! 	       */


object query_boat_environment(){   return environment(TO); }
  
string query_sailor_name(){ return sailor_name; }

int query_is_harbour(){ return is_harbour; } /* 1 is harbour  */
					    /* 2 central_harb */
                                           /* 0 no harbour (sea)   */

int query_traveler(){
		       /* this function returns number of travelers on it */
 int num, i;           /* if you make more than 1 room, owerwrite this    */
 object ob, *all;      /* function. See also: sailor_s()   !		  */

    num=0;
    ob=clone_object("obj/treasure");
    ob->set_alias("tester");
    transfer(ob,dest);
    all=all_inventory(environment(ob));
    for(i=0;i<sizeof(all) ;i++){
      if (living(all[i]	) && !all[i]->query_npc()) num++;
    }
    destruct(ob);
    return num;
}


void destination(string de){    /* set destination (file)                 */
      dest=de;                  /* where to move player when (s)he enters */ 
}

int look_next(){      /* returns 1 if somebody is in harbour else 0    */
 int i;

 for(i=0;i<sizeof(voyage);i+=2)
   if (voyage[i]->query_traveler_in_harbour()) return 1;
 return 0;
}

nomask void set_position(string str){
	    here=0;
    	    here=member_array(str,voyage);
            if (here==-1){
               write("ERROR: no exist harbour calls for boat.\n");
               return;
            }
            is_harbour=0;
            transfer(TO,SEA);
            call_out("arrive",arr_time);
          }

void arrive(){
      HAR(voyage[here],msgin);
      sailor_s(sailor_msgin);
      if (preinfo) sailor_s(preinfo+voyage[here]->short()+".\n");
      is_harbour=1;
      transfer(TO,voyage[here]);
      call_out("leave",anchor_time);
  }

void leave(){
      HAR(voyage[here],msgout);
      sailor_s(sailor_msgout);
      transfer(TO,SEA);
      is_harbour=0;
      if (!query_traveler() && !look_next()){
	transfer(TO,CENTRAL_HARBOUR);
        is_harbour=2;
	return; 
      }
      call_out("arrive",voyage[here+1]);
      here+=2;
      if (here>=sizeof(voyage)) here=0;
  }

void set_msgin(string n){ msgin=n; }

void set_msgout(string n){ msgout=n; }

void set_sailor_msgin(string n){ sailor_msgin=n; }

void set_sailor_msgout(string n){ sailor_msgout=n; }

void set_preinfo(string s){ preinfo=s; }

void reset(int arg){
 if (!arg){
  set_name("boat");
  set_alt_name("boat");
  set_can_get(0);
  sailor_name="John";
  here=0;
  is_harbour=2;
  msgin=capitalize(name)+" arrives to harbour.\n";
  msgout=capitalize(name)+" leaves.\n";
  sailor_msgout=capitalize(sailor_name)+" says: We are leaving.\n";
  sailor_msgin=capitalize(sailor_name)+" says: ";
 }
}



init(){
 add_action("do_enter_boat","enter");
}

int do_enter_boat(string str){
 notify_fail("Enter what?\n");
 if (id(str)){
  this_player()->move_player("into "+capitalize(name)+"#"+dest);
  return 1;
 }
 return 0;
}

