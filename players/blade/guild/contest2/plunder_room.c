inherit "room/room";

#include "/players/blade/area/blade_defs.h"
#define SROOM "/players/blade/guild/contest2/scroll_room"
int contest;
string winner_name;

reset(arg) {
  int mon_numbers;
  if(!arg) {
    set_light(1);
    short_desc="A sparse room";
    long_desc=
  "The walls are unadorned by any decoration.  You hardly notice as you are\n"+
"estatic about winning the thief competition.  Barrels stand in rows in the\n"+
  "center of the room beconing for your to take your treasure!\n";
    
    dest_dir=({
      SROOM, "west",
    });
    items=({ 
      "walls","They are plain and unmarked",
    });
    
    smell = "You smell hard work and its bountiful rewards.";
    winner_name="";
  }
}

init(){
  ::init();
    winner_name=(query_winner());

    if((this_player()->query_real_name()!="blade")){
      if((this_player()->query_real_name())!=winner_name) {
        write("The power of Mask pushes you out of the room.\n");
        write("You do not feel worthy enough to enter the treasure room.\n");
        move_object(this_player(),SROOM);
      }
      else{
        call_out("room_emote",random(10));
      }   
    }
  }

start(string arg){
  object contain, sroomo;
  int i, j, length;
  object *inv;
  
  if(!contest){
    if(sscanf(arg,"contest for %d minutes",length)==1){
      length*=60;
      if(length>(15*60)){
        tell_object(this_player(),"Dont you think that is a little long?\n");
        return 1;
      }
      set_winner("");
      contest=1;
      call_other(SROOM,"");
      sroomo=find_object(SROOM);
      if (!first_inventory(sroomo)) return 0;
      inv = all_inventory(sroomo);
      j=sizeof(inv);
      for (i=0; i < j; i++){
       if (living(inv[i])&&(inv[i]->query_guild()==1)){
         if(present(this_player(),sroomo)){
           if(present(inv[i]->query_real_name()+" barrel",this_object())){
             tell_object(inv[i],"You are already entered in the contest\n");
             return 1;
           }
           else {
             contain=clone_object("/players/blade/guild/contest/vat.c");
             move_object(contain,this_object());
             contain->set_name(inv[i]->query_real_name()+" barrel");
             contain->set_short(inv[i]->query_real_name()+" barrel");
             present("thiefsoul",inv[i])->set_contest(1);
             tell_object(inv[i],"You have been entered in the contest!\n");
           }
         }
       }
     }
      call_out("contest_results",length);
      call_out("clean",length+(5*60));
      return 1;
    }
  }
}

string set_winner(string str_arg){
  winner_name=str_arg;
}

string query_winner(){return winner_name;}
     
int clean(){
  int i, sz;
  object *ob;
  ob = all_inventory(this_object());
  for (sz=sizeof(ob), i=0; i<sz; i++){
    if (!ob[i]->id("castle") && !ob[i]->id("door") &&
        !ob[i]->query_player() && !ob[i]->id("board") ){
      move_object(ob[i],SROOM);
      if(ob[i]->query_vat()) destruct(ob[i]);
    }
  } /* endfor */
  set_winner("");
  return 1;
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

contest_status(){
  int i, j, bag_valu, winner, tp_coins;
  object *inv;
  string player_name, ran_string;

  ran_string="\n";  
  winner=0;
  inv=all_inventory(this_object());
  for(i=0, j=sizeof(inv); i<j; i++){
    if(sscanf(inv[i]->query_name(),"%s barrel",player_name)==1){
      bag_valu=inv[i]->query_bag_value(inv[i]);
      ran_string+=capitalize(player_name)+" stole "+bag_valu+" in coins.\n";
      if(player_name==(this_player()->query_real_name())) tp_coins=bag_valu;
      if(winner<bag_valu){
        winner=bag_valu;
        winner_name=player_name;
      }
    }
  }

  if(winner==tp_coins)
    tell_object(this_player(),ran_string + "You are in the lead!!!");
  else
    tell_object(this_player(),ran_string + capitalize(winner_name) +
                " is ahead of you by " + (winner-tp_coins) +
                " coins.\n");
  return 1;

}

contest_results(){
  int i, j, bag_valu, winner;
  object *inv;
  string player_name, ran_string;

  ran_string="\n";  
  winner=0;
  inv=all_inventory(this_object());
  for(i=0, j=sizeof(inv); i<j; i++){
    if(sscanf(inv[i]->query_name(),"%s barrel",player_name)==1){
      bag_valu=inv[i]->query_bag_value(inv[i]);
      ran_string+=capitalize(player_name)+" stole "+bag_valu+" in coins.\n";
      if(winner<bag_valu){
        winner=bag_valu;
        winner_name=player_name;
      }
    }
  }
  for(i=0, j=sizeof(inv); i<j; i++){
    if(sscanf(inv[i]->query_name(),"%s barrel",player_name)==1){
      tell_object(find_player(player_name), "The contest is over.\n" +
                  ran_string +
                  "The winner is: "+winner_name+" with "+winner+" coins!\n");
      present("thiefsoul",find_player(player_name))->set_contest(0);
    }
  }  
  tell_object(find_player(winner_name),
              "You are the best among thieves!  You have 5 minutes to\n " +
              "collect your winnings two east of the Temple.\n");
  set_winner(winner_name);
  contest=0;
  return 1;
}

room_emote(){
  if(present(this_player(),this_object())){
    switch(random(6)){
    case 1:{
    write("You say a small prayer of thanks to Mask for your good fortune.\n");
    say(this_player()->query_name()+" mumbles something under his breath.\n");
    break;
  }
  case 2:{
    write("A big grin spreads across your face as you look at your treasure.\n");
    say(this_player()->query_name()+" looks around and grins evilly.\n");
    break;
  }
  case 3:{
    write("You throw your head back and laugh loudly.\n");
    write("Your voice echos off the bare walls making an eerie sound.\n");
    say(this_player()->query_name()+" laughs insanely.\n");
    break;
  }
  case 4:{
    write("You stand proudly as you look around the room reserved for the best thieves.\n");
    say(this_player()->query_name()+" stands a little taller.\n");
    break;
  }
  case 5:{
    command("cackle",this_player());
    break;
  }
  case 0:{
    write("Your eyes light up as you look upon all the treasure that is all yours!\n");
    say(this_player()->query_name()+"'s eyes light up as he looks around the room.\n");
    break;
  }
  }
  }
  return 1;
}











