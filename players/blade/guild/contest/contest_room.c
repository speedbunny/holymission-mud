/* Coded by Blade on Holy Mission */
/* 12.3.94 */

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
"The thief contest room.  A scroll lies upon a pedestal in the center of\n"+
"the room.\n";

   dest_dir=({
            "/players/blade/guild/temple.c","west",
            "/players/blade/guild/contest/plunder_room.c","east",
                 });
   items=({ 
     "scroll","An old scroll.  Perhaps you should read it",
     "pedestal","A granite pedestal with an ancient scroll lying upon it",
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

string contest_status(){
  int i, j, bag_valu, winner;
  string ran_string, winner_name, player_name;
  object *inv, ob;
  
  inv=all_inventory(this_object());
  j=sizeof(inv);
  
  for(i=0;i<j;i++){
    if(sscanf(inv[i]->query_name(),"%s barrel",player_name)==1){
      bag_valu=inv[i]->query_bag_value(inv[i]);
      move_object(inv[i],"/players/blade/guild/contest/plunder_room");
      ran_string=capitalize(player_name)+" stole "+bag_valu+" in coins.\n";
      if(winner<bag_valu){
        winner=bag_valu;
        winner_name=player_name;
      }
      tell_object(this_player(),ran_string);    
    }
  }
  if(winner_name==(this_player()->get_real_name())){
    tell_object(this_player(),"You are in the lead!!!");
  }
  else{
    if(ob=present(this_player()->query_real_name()+" barrel")){
      tell_object(this_player(),capitalize(winner_name)+" is ahead of you by "+(winner-(ob->query_bag_value(ob)))+" coins.\n");
    }
  }
}

contest_results(){
  int i, j, k, bag_valu, counter2, counter3, winner;
  object *inv;
  string player_name, ran_string;
  results="\n";
  
  winner=0;
  inv=all_inventory(this_object());
  j=sizeof(inv);
  k=sizeof(new_array);
  (find_object("/players/blade/guild/contest/plunder_room.c"))->clean();
  
  for(i=0;i<j;i++){
    if(sscanf(inv[i]->query_name(),"%s barrel",player_name)==1){
      bag_valu=inv[i]->query_bag_value(inv[i]);
      move_object(inv[i],"/players/blade/guild/contest/plunder_room");
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
  



start(string arg){
  string contestant;
  object contestant_ob, contain;
  int i, j, length,  valid_counter;
  object *inv;
  
  if(!contest){
    if(sscanf(arg,"contest for %d minutes",length)==1){
      call_other("/players/blade/guild/contest/plunder_room", "");
      length*=60;
      if(length>(15*60)){
        write("Dont you think that is a little long?\n");
        return 1;
      }
      contest=1;
      if (!first_inventory(this_object())) return 0;
      inv = all_inventory(this_object());
      new_array=all_inventory(this_object());
      valid_counter =0;
      j=sizeof(inv);
      for (i=0; i < j; i++){
       if (living(inv[i])&&(inv[i]->query_guild()==1)){
         new_array[valid_counter]=inv[i];
         valid_counter++;
         if(present(this_player(),this_object())){
           if(present(inv[i]->query_real_name()+" barrel",this_object())){
             tell_object(inv[i],"You are already entered in the contest\n");
             return 1;
           }
           else {
             contain=clone_object("/players/blade/guild/contest/vat.c");
             move_object(contain,
                    find_object("/players/blade/guild/contest/plunder_room"));
             contain->set_name(inv[i]->query_real_name()+" barrel");
             contain->set_short(inv[i]->query_real_name()+" barrel");
             present("thiefsoul",inv[i])->set_contest(1);
             tell_object(inv[i],"You have been entered in the contest!\n");
           }
         }
       }
     }
      call_out("contest_results",length);
      return 1;
    }
  }
}

init(){
  ::init();
    add_action("read","read");
    add_action("start","start");
  }

read(string str_arg){

if(str_arg=="scroll"){
  write("---------------------------------------------------------\n"+
        "                   The Thief Contest                     \n"+
        "---------------------------------------------------------\n"+
        "                        History                          \n"+
        "---------------------------------------------------------\n"+
        "     Ages ago, the most devout followers of Mask would   \n"+
        "gather once a year to revel in their God's power.  This  \n"+
        "mostly consisted of random acts of wanton evil.  Each    \n"+
        "worshipper would vie for the honor of being the one who  \n"+
        "was the most evil.  The Maskians always had a problem    \n"+
        "deciding what was the most evil act, and how these acts  \n"+
        "compared to the other worshipper's acts of evil.  So the \n"+
        "gathering would often end up in large fights and caused  \n"+
        "faction among the Maskians.  So one year, in an effort to\n"+
        "make thier evils more measurable, decided that stealing  \n"+
        "was to be the offical evil to be measure each persons    \n"+
        "devotion to Mask.  Later, a particularly confident       \n"+  
        "Maskian proposed that he would bet all his plunder that  \n"+
        "he was the best evildoer.  The others all matched his    \n"+
        "bet, and this tradition has continued until modern times.\n"+
        "---------------------------------------------------------\n"+
        "                        The Rules                        \n"+
        "---------------------------------------------------------\n"+
        "     These are the rules as stated by mutual agreement   \n"+
        "among Maskians for centuries past.                       \n"+
        "     The ritual must be kept secret.  Noone outside of   \n"+
        "religion must know about it, and only religion members   \n"+
        "are allowed to participate in the ritual.                \n"+
        "     The most evil person receives all the spoils of the \n"+
        "ritual, and the honor of being Mask's most devout        \n"+
        "follower, and thereby hope to receive more power from    \n"+
        "Mask.                                                    \n"+
        "---------------------------------------------------------\n"+
        "                    Contest Syntax                       \n"+
        "---------------------------------------------------------\n"+
        "     start contest for <integer> minutes                 \n"+
        "         to run the contest for <integer> minutes        \n"+
        "     contest                                             \n"+
        "         show who is in the lead                         \n");
  return 1;
}
return 0;
}









