#define length_of_curse (60 * 5)
#define An (call_other(this_player(), "query_real_name", 0) == "animal")
 
int start_time;
 
query_scurse_time(){
  return "Super_Curse started at " + start_time +
         "this curse will end at " + (start_time+length_of_curse) +
         "time now is currently  " + time();
}
 
start(ob){
  move_object(this_object(), ob);
  start_time = time();
  tell_object(ob,"You have incurred one of the most horrible curses!\n");
}
query_auto_load() { return "players/animal/obj/scurse:0"; }
 
id(str){
  return (str == "super_curse@animal@091490" || str == "scurse");
}
 
long(){
   write("Super_Curse started at " + start_time+ "\n" +
         "this curse will end at " + (start_time+length_of_curse)+ "\n" +
         "time now is currently  " + time() +"\n");
 
}
 
drop(){
  return 1;
}
 
init(){
       if An return 1;
 if (call_other(this_player(), "query_level", 0) > 699) {
          return 1;  
     }else{
    add_action("do_something");  add_xverb("");
}
}
 
do_something(){
  if (time() < start_time + length_of_curse){
    write("You pissed someone off eh? Well too bad, cause now you cannot do that!\n");
    return 1;
    }
  else {
    destruct(this_object());
    write("You feel VERY relieved.  Since you have been good, the curse has\n");
    write("automatically been removed.\n");
    return 0;
    }
}
 
extra_look(){
  return "they seem to be having difficulty do things";
}
 
destroy_this_curse(){
  destruct(this_object());
  write("You must have groveled enough, because the curse is now lifted!\n");
}
