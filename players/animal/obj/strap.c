#define length_of_curse (60 * 1)
#define An (call_other(this_player(), "query_real_name", 0) == "animal")
 
int start_time;
 
short() { return "Straps"; }
 
reset(arg){
     if(arg) return 0;
     start_time = time();
}
 
id(str){
  return (str == "strap" || str == "gag");
}
 
long(){
   write("These are straps on the chair, they are VERY tight!\n");
}
 
drop(){
  return 1;
}
 
init(){
       if An return 1;
       if (call_other(this_player(), "query_level", 0) > 50) {
          return 1;  
     }else{
       add_action("do_something","",1);
}
 
do_something(){
  if (time() < start_time + length_of_curse){
    write("You are strapped securley in the chair! You cannot do that!\n");
    return 1;
    }
  else {
    destruct(this_object());
    write("You managed to break out of the straps!\n");
    return 1;
    }
}
 
extra_look(){
  return "they seem to be having difficulty do things";
}
 
destroy_this_curse(){
  destruct(this_object());
  write("You must have groveled enough, because you are freed!\n");
}
