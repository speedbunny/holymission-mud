#define TP this_player()

int _timeout(string arg){


say(TP->query_name()+" holds up "+TP->query_possessive()+
     " hands in a T and calls TIMEOUT!.\n");

write("You go TIMEOUT.\n");
return 1;
}



