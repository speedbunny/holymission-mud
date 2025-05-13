
/* 930131 mud@mud.edvz.uni-linz.ac.at Herp aka Herbert Rosmanith */
/* Short() stolen from llort */
/* Stolen and Modified by Blade */

object mud_victim;

start_shadow(object obj,int s) {
  mud_victim=obj;
  shadow(obj,1);		/* Start shadowing now */
  call_out("remove_shadow",s);
}

remove_shadow() {
  object env;
  if (mud_victim){ 
    tell_object(mud_victim,"You take off the mask.\n");
    say(mud_victim->query_name()+" takes off his mask.\n",mud_victim);
    destruct(this_object());
    return 1;
  }
}

look_info(flag){
  if(flag) return "a masked man";
  return "a masked man";
}

string short(){ return "a masked man"; }

id(string arg){
  if(arg=="a masked man")
    return 1;
  else
    return 0;
}

string query_name(){
  return "a masked man";
}


