#include "/players/brainsprain/guild/headers.h"
/*=============================== Mislead ==================================*/
int main(string arg){
  int counter,i,j;
  object *followers_array, thief;
  string *dest_dir_;
  string mislead_room;
  
  if(!arg){
    write("What direction?\n");
    return 1;
  }
  thief=this_player();
  dest_dir_ = (string *)(environment(thief)->query_room("dest_dir"));
  
  if(dest_dir_ &&((j = member_array(arg, dest_dir_)) != -1)) {
    j=j-1;
  }
  else if(dest_dir_=(string *)(environment(thief)->query_room("hidden_dir"))&&
          (j = member_array(arg,dest_dir_)) != -1){
    j=j-1;
  }
  else{
    write("What direction?\n");
    return 1;
  }
  if(!thief->query_invis()){
    tell_room(environment(thief),
              thief->query_name()+" " +
              thief->query_msgout()+" "+
              arg+".\n");
  }
  if(counter = sizeof(followers_array = thief->query_followers())) {
    for(i=0;i<counter;i++){
      if(present(followers_array[i],environment(thief))){
        followers_array[i]->move_player(arg, dest_dir_[j]);
        tell_object(followers_array[i],"You follow "+thief->query_name()+
                    " "+dest_dir_[j+1]+".\n");
        say(followers_array[i]->query_name()+" "+
            followers_array[i]->query_msgout()+" "+
            dest_dir_[j+1]+".\n");
      }
    }
  }
  else write("No one is following you.\n");
  return 1;
}








