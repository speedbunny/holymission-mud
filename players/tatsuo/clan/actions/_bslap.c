#define TP this_player()
 int _bslap(string arg){

 object target;
if(!arg){
say(TP->query_name()+" repeatedly bitch slaps himself causing a commotion.\n");

write("You bitch slap yourself into next week.\n");
return 1;
}
else

target = present(arg,environment(TP) );
 if(!target) return printf(capitalize(arg) + " is not here.\n"),1;

tell_object(target, "You stand with jaw gaping as "+TP->query_name()+
      " bitchslaps you into next week!\n");

write("You bitchslap the shit out of "+arg+".\n");

say(target->query_name()+" drops "+ target->query_possessive()+" jaw in "+
     "disbelief as "+TP->query_name()+" bitchslaps "+target->query_objective()+"!\n", target);
return 1;
}







