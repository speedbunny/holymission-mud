inherit "/players/sauron/clone/ldup_cmds/extras";

#pragma strict_types
#pragma save_types

string junk,*tmp;
int z;

int get_dir_filter(string file) {
  return file[<2..<1]==".c";
}

int _update(string str) {
  string path,altstr,name,emess,*files,*exstr;
  int a,b,c,d,e,f,i,j,r;
  object ob,env,*inv,*pl;

  if(!str || str == "")
    return _update("/"+file_name(environment(this_player())));
  else if(sscanf(str, "-l %s", str)) {
    ob = find_object(str);
    if(!ob)
        printf("'%s' not found.\n", str);
    else {
      for(i = sizeof(inherit_list(ob))-1; i >= 0; i--)
        _update("/"+inherit_list(ob)[i]);
    }
    return 1;
  }
  files=tmp=({});
  exstr=explode(str,"\"");
  str=exstr[0];
  if(sscanf(str,"%s.c",altstr)==1)
    str=altstr;
  str=lib_fn_expand(str);
  exstr=explode(str,"/");
  altstr=exstr[<1];
  exstr[<1]="";
  path=implode(exstr,"/");

  tmp=filter_array(get_dir(str+".c"),"get_dir_filter",this_object());
  for(i=0;i<sizeof(tmp);i++)
    if(member_array(path+tmp[i],files)==-1)
      files+=({path+tmp[i]});

  tmp=filter_array(get_dir(str),"get_dir_filter",this_object());
  for(i=0;i<sizeof(tmp);i++)
    if(member_array(path+tmp[i],files)==-1)
      files+=({path+tmp[i]});

  if(file_size(str)==-2 && str[<1..<1]!="*") {
    path+=(altstr+"/");
    tmp=filter_array(get_dir(str+"/."),"get_dir_filter",this_object());
    for(i=0;i<sizeof(tmp);i++)
      if(member_array(path+tmp[i],files)==-1)
        files+=({path+tmp[i]});
  }

  if(!sizeof(files)) {
    printf("*File: %s.c does not exist.\n",str);
    return 1;
  }

  z=0;
  for(j=0;j<sizeof(files);j++) {
    if(files[j]=="." || files[j]=="..") {
      z++;
      continue;
    }
    else if(file_size(files[j])==-2 || !sscanf(files[j],"%s.c",altstr)) {
      printf("*Ignored: %s\n",files[j]);
      a++;
      continue;
    }
    else if(!ob=find_object(files[j])) {
      printf("*Already up to date: %s\n",files[j]);
      f++;
      continue;
    }
    pl=({});
    inv=all_inventory(ob);
    env=environment(ob);
    name=file_name(ob);
    r=sscanf(name,"%s#%s",name,junk);
    for(i=0;i<sizeof(inv);i++) {
      if(interactive(inv[i])) {
        if(inv[i]!=this_player()) {
          tell_object(inv[i],"Your environment was updated by "
            +this_player()->query_name()+".\n");
        }
        pl=pl+({inv[i]});
      }
      else destruct(inv[i]);
    }
    for(i=0;i<sizeof(pl);i++)
      move_object(pl[i],"/room/void");
    destruct(ob);
    if(!ob=find_object(files[j])) {
      printf("*Updated: %s\n",files[j]);
      c++;
      if(sizeof(pl)) {
        emess=catch(call_other(name,"load_object"));
        if(!r)
          ob=find_object(name);
        else
          ob=clone_object(name);
        if(env)
          move_object(ob,env);
        if(!ob) {
          for(i=0;i<sizeof(pl);i++) {
            if(pl[i]!=this_player()) {
              tell_object(pl[i],"The room failed to reload, and you are \
sent to the void.\n");
            }
          }
          printf("%s\n*Failed to reload : %s (player present when \
updated).\n",emess,files[j]);
          c--;
          d++;
        }
        else {
          if(emess) {
            printf("%s\n*Warning in reloading : %s (player present when \
updated).\n",emess,wfile(ob));
            c--;
            b++;
          }
          else {
            printf("*Reloaded : %s (player present when updated).\n",
                   wfile(ob));
            c--;
            e++;
          }
          for(i=0;i<sizeof(pl);i++)
            move_object(pl[i],name);
        }
      }
    }
    else printf("*Cannot update: %s\n",wfile(ob));
  }
  write("\n");
  if(c)
    printf("*Total: %3d out of %3d files updated.\n",
           c,(sizeof(files)-z));
  if(f)
    printf("*Total: %3d out of %3d files already up to date.\n",
           f,(sizeof(files)-z));
  if(e)
    printf("*Total: %3d out of %3d files updated and reloaded.\n",
           e,(sizeof(files)-z));
  if(b)
    printf("*Total: %3d out of %3d files updated but gave a warning in \
reloading.\n",b,(sizeof(files)-z));
  if(d)
    printf("*Total: %3d out of %3d files updated but failed to reload.\n",
           d,(sizeof(files)-z));
  if(a)
    printf("*Total: %3d out of %3d files ignored.\n",
           a,(sizeof(files)-z));
  return 1;
}
