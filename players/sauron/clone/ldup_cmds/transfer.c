#include "/players/sauron/include/include.h"

int _transfer(string str) {
  string s1,s2;
  object ob,ob2;

  if(!str || sscanf(str,"%s to %s",s1,s2)!=2) {
    notify_fail("Usage: transfer <object> to <player>\n");
    return 0;
  }

  else if(!(ob2=present(s1,TP))) {
    notify_fail("You are not carrying an object which answers to '"
                +s1+"'.\n");
    return 0;
  }

  else if(!(ob=find_player(s2))) {
    notify_fail(CAP(s2)+" is not currently logged on.\n");
    return 0;
  }

  else {
    transfer(ob2,ob);
    printf("You trasnfered your %s to %s.\n",CAP(s1),CAP(s2));
    TELLO(ob,sprintf("%s just transfered %s to you.\n",
                     CRNAME(TP),CAP(s1)));
    return 1;
  }
}

