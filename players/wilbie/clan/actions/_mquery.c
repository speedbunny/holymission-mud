#define TP this_player()
 int _mques(string arg){

 object target;
if(!arg){
say(TP->query_name()+" tries to figure out what the hell is wrong with "+
"you people.\n");

write("You try to figure out what the hell is wrong with these people.\n");
return 1;
}
else

target = present(arg,environment(TP) );
 if(!target) return printf(capitalize(arg) + " is not here.\n"),1;

tell_object(target, TP->query_name()+" tries to figure out what the hell "+
"is wrong with you.\n");
write("You bow gracefully to "+arg+" with an aire of arrogant grandeur.\n");
say(TP->query_name()"+ looks at "+arg+" and tries to figure out where nature "+
"went wrong.\n");
return 1;
}





