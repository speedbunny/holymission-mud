#define TP this_player()
 int _bow(string arg){

 object target;
if(!arg){
say("Grandly, "+TP->query_name()+" bows slowly, with arrogant grace.\n");

write("You bow gracefully, with arrogant grandeur.\n");
return 1;
}
else

target = present(arg,environment(TP) );
 if(!target) return printf(capitalize(arg) + " is not here.\n"),1;

tell_object(target, TP->query_name()+" bows to you gracefully, with an\n"+
            "aire of arrogant grandeur.\n");
write("You bow gracefully to "+arg+" with an aire of arrogant grandeur.\n");
say(TP->query_name()+" bows gracefully to "+arg+" with an aire of\n"+
"arrogant grandeur.\n");
return 1;
}





