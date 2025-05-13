#include "/players/sauron/guild/include/cmd_functions.c"

status main(string str) {
  string what,where;
  int ret;
  object ob,soul;

  if(!str) {
    NF("Hide what where?\n");
    return 0;
  }
  else if(sscanf(str,"%s in %s",what,where)!=2) {
    NF("Hide what where?\n");
    return 0;
  }
  else if(!(soul=query_tmp("monk_soul")) || !(soul->id(where))) {
    NF("Hide what where?\n");
    return 0;
  }
  else if(!(ob=present(what,TP))) {
    NF("Hide what where?\n");
    return 0;
  }
  else if(ob==soul) {
    printf("You can't hide your %s in itself.\n",what);
    return 1;
  }
  else if(ob->drop())
    return 1;
  else if(!soul->add_weight((int)ob->query_weight())) {
    printf("You rumage around in your %s but can't find a place to secrete \
your %s.\n",where,what);
    return 1;
  }
  else {
    ret=TR(ob,soul);
    if(!ret) {
      printf("You secrete your %s in your %s.\n",what,where);
      SAY(sprintf("%s hides something in %s %s.\n",
                  CRNAME(TP),HIS(TP),where));
    }
    else
      printf("Transfer returned %d.\n",ret);
    return 1;
  }
}
