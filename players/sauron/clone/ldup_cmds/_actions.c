inherit "/players/sauron/clone/ldup_cmds/extras";

#pragma strict_types
#pragma save_types

int _actions(string str) {
  int i,j,k,tmp,start,block;
  string q,w,e,fname,file,bytes;
  string *allfile;
  object *inv,*env;
  j=0;
  start=0;
  block=50000;
  file="";
  if(!str || str=="here") 
    fname=file_name(environment(this_player()));
  else {
    sscanf(str,"%s.c",str);
    inv=all_inventory(this_player());
    env=all_inventory(environment(this_player()));
    for(k=0;k<sizeof(inv);k++) {
      if(inv[k]->id(str) && !fname)
        fname=file_name(inv[k]);
      else
        continue;
    }
    for(k=0;k<sizeof(env);k++) {
      if(env[k]->id(str) && !fname)
        fname=file_name(env[k]);
      else
        continue;
    }
    if(!fname)
      fname=lib_fn_expand(str);
  }
  sscanf(fname,"%s#%d",fname,tmp);
  fname=fname+".c";
  if(fname[0..0]!="/")
    fname="/"+fname;
  if(file_size(fname)==-1) {
    printf("You can't seem to read the file %s.\n",fname);
    return 1;
  }
  while(start<file_size(fname)) {
    bytes=read_bytes(fname,start,block);
    if(!bytes) {
      printf("*File: Error reading file %s at byte %i\n",
        fname,start);
      return 1;
    }
    file+=bytes;
    start+=block;
  }
  allfile=explode(file,"\n");
  printf("Looking for add_actions in %s:",fname);
  for(i=0;i<sizeof(allfile)-1;i++) {
    if(sscanf(allfile[i],"%sadd_action(%s)%s",q,w,e)>0) {
      if(!j)
        write("\n");
      printf("\nAdd_action found on line %d:\n%s",i+1,allfile[i]);
      j++;
    }
    else if(sscanf(allfile[i],"%sAA(%s)%s",q,w,e)>0) {
      if(!j)
        write("\n");
      printf("\nAdd_action found on line %d:\n%s",i+1,allfile[i]);
      j++;
    }
    else
      continue;
  }
  printf("\n\n%i add_action%s found.\n",j,(j==1?"":"s"));
  return 1;
}