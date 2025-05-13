#pragma strict_types
#pragma save_types

int _inv(string str) {
  object obj,*all;
  string your,inv,fname;
  int i;
  if((!str) || !strlen(str)) {
    obj=this_player();
    your="Your";
    inv="inventory";
  }
  else if(str=="here") {
    obj=environment(this_player());
    your="Your";
    inv="environment";
  }
  else {
    obj=find_living(str);
    if(!obj) {
      notify_fail("No player with that name ("+capitalize(str)+")\n");
      return 0;
    }
    your=capitalize((string)obj->query_real_name())+"'s";
    inv="inventory";
  }
  printf("/%s\n",file_name(obj));
  obj->long();
  all=all_inventory(obj);
  printf("\n%s %s contains:\n\n",your,inv);
  if(!sizeof(all))
    write("\tNothing.\n");
  else {
    for(i=0;i<sizeof(all);i++) {
      fname="/"+file_name(all[i]);
      if(fname[0..14]=="/players/sauron")
        fname=sprintf("&%s",fname[15..<1]);
      else if(fname[0..8]=="/players/")
        fname=sprintf("~%s",fname[9..<1]);
      printf("%2i %-40s %-10O %-O\n",
        i,fname,(string)all[i]->query_real_name(),
        all[i]->short());
    }
  }
  return 1;
}