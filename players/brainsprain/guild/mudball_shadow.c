/* Stolen and Modified by Blade @ Holy Mission */

object mud_victim;

start_shadow(object obj,int s) {
  mud_victim=obj;
  shadow(obj,1);                /* Start shadowing now */
  call_out("remove_shadow",s);
}

remove_shadow(){
object env;
  if (mud_victim){ 
    tell_object(mud_victim,"You wipe your eyes clean.\n");
    say(mud_victim->query_name()+" wipes his eyes clean.\n",mud_victim);
    destruct(this_object());
    return 1;
  }
}

mylook(){
  say(mud_victim->query_name()+
      " tries to look around, but fails.\n",mud_victim);
  return "You are blinded by mud in your eyes!\n";
}

look(){
  say(mud_victim->query_name()+
      " tries to look around, but fails.\n",mud_victim);
  tell_object(mud_victim,"You are blinded by mud in your eyes!\n");
  return 1;
}

look_info(flag){
  if(flag) return 0;
  return ("(covered in mud)");
}

short(flag){
  string tmp;

  tmp = mud_victim->short(flag);
  if (!tmp) return 0;
  if(flag) return tmp;
  return tmp+look_info();
}
 
int query_mudballed(){
return 1;
}

mixed move_player(mixed dir_dest,mixed optional_dest_ob,
                  mixed raw,string income_msg){
  string *exit_array;
  int j;
  
  if(!random(2)){
    exit_array=(string *)(environment(mud_victim)->query_room("dest_dir"));
    if(j=sizeof(exit_array)>2){
      j=random(j/2)*2;
      return mud_victim->move_player(exit_array[j+1],exit_array[j]);
    }
  }
  return mud_victim->move_player(dir_dest,optional_dest_ob,raw,income_msg);
}
  
int exits(){
  say(mud_victim->query_name()+
      " tries to look around, but fails.\n",mud_victim);
  tell_object(mud_victim,"You are blinded by mud in your eyes!\n");
  return 1;
}

/* For those of you nosy wizzes who are reading my code:   */
/* This was never intended to be put in, I am just playing */
/* around with it.  So leave me alone! :>                  */

/* int stat_dam(object weap){
  object vic;
  int count;
  
  if (!count)
    count = 1;
  else if (count < 3)
    count ++;
  else
    count = 0;
  
  write("test");
  
  write("You loose track of your attackers whereabouts!\n");
  say(mud_victim->query_name()+" becomes confused by the mud!\n",mud_victim);
  return (0);
  
}
*/

