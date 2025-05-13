/*  CENTRAL HARBOUR  Master of travel-network
 

This room is for all objects that are using in travel-net.
Those objects are here to save CPU ...


*/

inherit "/room/room";
#define TP this_player()
#define TO this_object()

string *boat_file;    /*  variable for all 'boats' */


void call_boat(string where, string name_of_boat){
 object boat;
 int i;

   i=member_array(name_of_boat,boat_file);
   if (i==-1){
    write("ERROR: Boat "+name_of_boat+" is not in central_harb.c list.\n"+
          "       That means: boat cannot be called.\n");
    return;
   }      
   if (boat_file[i+1]->query_is_harbour()==2)
     boat_file[i+1]->set_position(where);

/*  if (present(name_of_boat,TO)){
*	   boat= present(name_of_boat,TO);
*	   boat->set_position(where);
*   }
*/  
  return;
}
    
void make_boat(){
 int i;
 for(i=1;i<sizeof(boat_file);i+=2){

/*  move_object(boat_file[i],TO); 
 Boats use transfer in reset(0)
*/ 

 }
}
  
void reset(int arg){

if (!arg){
 set_light(1);
 short_desc=("Central harbour of ESK");
 long_desc="You are in the central harbour of East Sea Kingdom.\n"+
           "This is home harbour for many ships.\n"+
           "If you land here, your transport thing got an accident. Excuse\n"+
           "them.\n";   
 dest_dir=({"/room/church","church"});
 property=({"no_clean_up"});
  /*  here add new boat:    <name> , <file_name>  */

 boat_file=({"atlanta","players/goldsun/example/my_boat",
"pinta","players/goldsun/example/pinta",
	     "cargo junk","players/patience/ezo/cargoJunk" 
            });     

 make_boat();
  }
 ::reset(arg);
}

