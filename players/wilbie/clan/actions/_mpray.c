#define TP this_player()
 int _mpray(string arg){

 object target;
if(!arg){
say(TP->query_name()+" says a prayer for your souls.\n");

write("You say a prayer for these foolish souls.\n");
return 1;
}
else

target = present(arg,environment(TP) );
 if(!target) return printf(capitalize(arg) + " is not here.\n"),1;

tell_object(target, TP->query_name()+" says a prayer for your foolish soul.\n");
write("You bow gracefully to "+arg+" with an aire of arrogant grandeur.\n");
say(TP->query_name()+" says a prayer for "+arg+".\n");
return 1;
}





