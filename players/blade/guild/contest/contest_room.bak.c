inherit "room/room";

#include "/players/blade/area/blade_defs.h"

object *new_array;
string results, winner_name;
int contest;

reset(arg) {
    if(!arg) {
        set_light(1);
        short_desc="The Thief Contest room";
        long_desc=
"The thief contest room.\n";

   dest_dir=({
	    "/players/blade/test/temple.c","west",
	    "/players/blade/test/plunder_room.c","east",
                 });
   items=({ 
     "trees","Large trees surrounding you",
     "foliage","Green foliage of all types",
     "valley","Mountains rise up on either side of a small valley",
     "mountains","Steep mountains that rise in the north and the south",
   });

        smell = "You smell nothing special.";
	contest=0;
	enable_commands();
    }
}
/*
int end_contest(){
  int i, j;
  results = 0;
  j=sizeof(new_array);
  write("hmm");
  for(i=0;i<j;i++){
    new_array[i]->set_contest(0);
    tell_object(environment(new_array[i]),results);
    tell_object(environment(new_array[i]),"The contest is over.\n");    
  }
  return 1;
}
*/

string query_winner(){return winner_name;}

contest_results(){
  int i, j, k, bag_valu, counter2, counter3, winner;
  object *inv;
  string player_name, ran_string;
  results="\n";
  
  winner=0;
  inv=all_inventory(this_object());
  j=sizeof(inv);
  k=sizeof(new_array);
  (find_object("/players/blade/test/plunder_room.c"))->clean();
  
  for(i=0;i<j;i++){
    if(sscanf(inv[i]->query_name(),"%s barrel",player_name)==1){
      bag_valu=inv[i]->query_bag_value(inv[i]);
   /*   move_object(inv[i],"/players/blade/test/plunder_room.c");  */
      move_object(inv[i],"/players/blade/test/plunder_room");
      ran_string=capitalize(player_name)+" stole "+bag_valu+" in coins.\n";
      if(winner<bag_valu){
	winner=bag_valu;
	winner_name=player_name;
      }
      for(counter2=0;counter2<k;counter2++){
      	tell_object(environment(new_array[counter2]),ran_string);
      }      
    }
  }
  for(counter3=0;counter3<k;counter3++){
    tell_object(environment(new_array[counter3]),"The winner is: "+winner_name+" with "+winner+" coins!\n");
    new_array[counter3]->set_contest(0);
    tell_object(environment(new_array[counter3]),"The contest is over.\n");
  }

  contest=0;
  return 1;
}  

catch_tell(string arg){
  string krap, contestant;
  object contestant_ob, contain;
  int i, j, valid_counter;
  object *inv;
  
  write("You said: "+arg);
  if(!contest){
    write("contest false");
    if(sscanf(arg,"%s says: start %s",contestant,krap)==2){
      
      contest=1;
      if (!first_inventory(this_object())) return 0;
      inv = all_inventory(this_object());
      new_array=all_inventory(this_object());
      valid_counter =0;
      j=sizeof(inv);
      for (i=0; i < j; i++){
	if (living(inv[i])&&(new_array[valid_counter]=present("thiefsoul",inv[i]))){
	  valid_counter++;
	  if(present(contestant,this_object())){
	    if(present(inv[i]->query_real_name()+" barrel",this_object())){
	    tell_object(inv[i],"You are already entered in the contest\n");
	    return 1;
	  }
	    else {
	      contain=clone_object("/players/blade/test/vat.c");
	      move_object(contain,this_object());
	      contain->set_name(inv[i]->query_real_name()+" barrel");
	      contain->set_short(inv[i]->query_real_name()+" barrel");
	      present("thiefsoul",inv[i])->set_contest(1);
	      tell_object(inv[i],"You have been entered in the contest!\n");
	    }
	  }
	}
      }
      call_out("contest_results",15);
      return 1;
    }
  }
}





