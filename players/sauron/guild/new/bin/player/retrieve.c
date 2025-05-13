#include "/players/sauron/guild/include/cmd_functions.c"

status main(string str) {
  string what,where;
  object ob,soul;

  if(!str) {
    NF("Retrieve what from where?\n");
    return 0;
  }
  else if(sscanf(str,"%s from %s",what,where)!=2) {
    NF("Retrieve what from where?\n");
    return 0;
  }
  else if(!(soul=query_tmp("monk_soul")) || !(soul->id(where))) {
    NF("Retrieve what from where?\n");
    return 0;
  }
  else if(!(ob=present(what,soul))) {
    NF(sprintf("You don't have a %s in your %s.\n",what,where));
    return 0;
  }
  else if(ob==soul) {
    printf("This should never happen.\n");
    return 1;
  }
  else if(!soul->add_weight(-(int)ob->query_weight())) {
    printf("This should never happen.\n");
    return 1;
  }
  else {
    TR(ob,TP);
    printf("You retrieve your %s from your %s.\n",what,where);
    SAY(sprintf("%s retrieves something from %s %s.\n",
                CRNAME(TP),HIS(TP),where));
    return 1;
  }
}
