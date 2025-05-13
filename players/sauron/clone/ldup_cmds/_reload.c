inherit "/players/sauron/clone/ldup_cmds/extras";

#pragma strict_types
#pragma save_types

string emess,name,altstr;
int i,j,r,junk;
object ob,env;
object *inv,*pl;

int _reload2(int k,int a,int b,int c,int d,int e,int f,
             string *files,string path) {
  if(d<k+10) {
    for(i=k;i<d;i++) {
      if(file_size(path+files[i])==-2 || !sscanf(files[i],"%s.c",altstr)) {
        printf("*Ignored: %s\n",path+files[i]);
        e++;
        continue;
      }
      else if(!ob=find_object(path+files[i])) {
        if(!emess=catch(call_other(path+files[i],"???"))) {
          if(ob=find_object(path+files[i])) {
            printf("*Loaded: %s\n",wfile(ob));
            f++;
            continue;
          }
        }
        else {
          if(ob=find_object(path+files[i])) {
            printf("%s\n*Warning in loading: %s\n",emess,wfile(ob));
            a++;
            continue;
          }
          else {
            printf("%s\n*Failed to load: %s\n",emess,path+files[i]);
            b++;
            continue;
          }
        }
      }
      pl=({});
      inv=all_inventory(ob);
      env=environment(ob);
      name=file_name(ob);
      r=sscanf(name,"%s#%d",name,junk);
      for(j=0;j<sizeof(inv);j++) {
        if(interactive(inv[j])) {
          if(inv[j]!=this_player())
            tell_object(inv[j],"Your environment was updated by "
              +this_player()->query_name()+".\n");
          pl=pl+({inv[j]});
        }
        else destruct(inv[j]);
      }
      for(j=0;j<sizeof(pl);j++)
        move_object(pl[j],"/room/void");
      destruct(ob);
      if(!ob=find_object(path+files[i])) {
        emess=catch(call_other(name,"load_object"));
        if(!r) ob=find_object(name);
        else ob=clone_object(name);
        if(!ob) {
          for(j=0;j<sizeof(pl);j++) {
            if(pl[i]!=this_player()) {
              tell_object(pl[j],"The room failed to reload, "
                               +"and you are sent to the void.\n");
            }
          }
          printf("%s\n*Failed to reload: %s.\n",
          emess,path+files[i]);
          b++;
        }
        if(env) move_object(ob,env);
        else {
          if(emess) {
            printf("%s\n*Warning in reloading: %s.\n",
            emess,wfile(ob));
            a++;
          }
          else {
            printf("*Reloaded: %s.\n",wfile(ob));
            c++;
          }
          for(j=0;j<sizeof(pl);j++)
            move_object(pl[j],name);
        }
      }
      else printf("*Cannot update: %s\n",wfile(ob));
    }
    write("\n");
    if(f) printf("*Total: %3d out of %3d files loaded.\n",
            f,d);
    if(c) printf("*Total: %3d out of %3d files updated and reloaded.\n",
            c,d);
    if(a) printf("*Total: %3d out of %3d files loaded, but gave a warning.\n",
            a,d);
    if(b) printf("*Total: %3d out of %3d files failed to load.\n",
            b,d);
    if(e) printf("*Total: %3d out of %3d files ignored.\n",
            e,d);
    return 1;
  }
  else {
    for(i=k;i<k+10;i++) {
      if(file_size(path+files[i])==-2 || !sscanf(files[i],"%s.c",altstr)) {
        printf("*Ignored: %s\n",path+files[i]);
        e++;
        continue;
      }
      else if(!ob=find_object(path+files[i])) {
        if(!emess=catch(call_other(path+files[i],"???"))) {
          if(ob=find_object(path+files[i])) {
            printf("*Loaded: %s\n",wfile(ob));
            f++;
            continue;
          }
        }
        else {
          if(ob=find_object(path+files[i])) {
            printf("%s\n*Warning in loading: %s\n",emess,wfile(ob));
            a++;
            continue;
          }
          else {
            printf("%s\n*Failed to load: %s\n",emess,path+files[i]);
            b++;
            continue;
          }
        }
      }
      pl=({});
      inv=all_inventory(ob);
      env=environment(ob);
      name=file_name(ob);
      r=sscanf(name,"%s#%d",name,junk);
      for(j=0;j<sizeof(inv);j++) {
        if(interactive(inv[j])) {
          if(inv[j]!=this_player())
            tell_object(inv[j],"Your environment was updated by "
              +this_player()->query_name()+".\n");
          pl=pl+({inv[j]});
        }
        else destruct(inv[j]);
      }
      for(j=0;j<sizeof(pl);j++)
        move_object(pl[j],"/room/void");
      destruct(ob);
      if(!ob=find_object(path+files[i])) {
        emess=catch(call_other(name,"load_object"));
        if(!r) ob=find_object(name);
        else ob=clone_object(name);
        if(!ob) {
          for(j=0;j<sizeof(pl);j++) {
            if(pl[i]!=this_player()) {
              tell_object(pl[j],"The room failed to reload, "
                               +"and you are sent to the void.\n");
            }
          }
          printf("%s\n*Failed to reload: %s.\n",
          emess,path+files[i]);
          b++;
        }
        if(env) move_object(ob,env);
        else {
          if(emess) {
            printf("%s\n*Warning in reloading: %s.\n",
            emess,wfile(ob));
            a++;
          }
          else {
            printf("*Reloaded: %s.\n",wfile(ob));
            c++;
          }
          for(j=0;j<sizeof(pl);j++)
            move_object(pl[j],name);
        }
      }
      else printf("*Cannot update: %s\n",wfile(ob));
    }
    call_out("_load2",2,k+10,a,b,c,d,e,f,files,path);
    write("\n");
    if(f) printf("*Total: %3d out of %3d files loaded.\n",
            f,d);
    if(c) printf("*Total: %3d out of %3d files updated and reloaded.\n",
            c,d);
    if(a) printf("*Total: %3d out of %3d files loaded, but gave a warning.\n",
            a,d);
    if(b) printf("*Total: %3d out of %3d files failed to reload.\n",
            b,d);
    if(e) printf("*Total: %3d out of %3d files ignored.\n",
            e,d);
    return 1;
  }
}

int _reload(string str) {
  string path;
  string *files,*exstr;
  int a,b,c,d,e,f;
  if(!str)
    return (int)notify_fail("Syntax: reload <file(s)>\n");
  exstr=explode(str,"\"");
  str=exstr[0];
  if(sscanf(str,"%s.c",altstr)==1)
    str=altstr;
  str=lib_fn_expand(str);
  exstr=explode(str,"/");
  altstr=exstr[sizeof(exstr)-1];
  exstr[sizeof(exstr)-1]="";
  path=implode(exstr,"/");
  files=get_dir(str);
  if(!sizeof(files))
    files=get_dir(str+".c");
  if(!sizeof(files) || (file_size(path+altstr)==-2
                     && file_size(path+altstr+".c")==-1)) {
    str=str+"/.";
    path=path+altstr+"/";
    files=get_dir(str);
  }
  if(!d=sizeof(files)) {
    str=implode(exstr,"/")+altstr;
    printf("*File: %s.c does not exist.\n",str);
  }
  if(d<=10) {
    for(i=0;i<d;i++) {
      if(file_size(path+files[i])==-2 || !sscanf(files[i],"%s.c",altstr)) {
        printf("*Ignored: %s\n",path+files[i]);
        e++;
        continue;
      }
      else if(!ob=find_object(path+files[i])) {
        if(!emess=catch(call_other(path+files[i],"???"))) {
          if(ob=find_object(path+files[i])) {
            printf("*Loaded: %s\n",wfile(ob));
            f++;
            continue;
          }
        }
        else {
          if(ob=find_object(path+files[i])) {
            printf("%s\n*Warning in loading: %s\n",emess,wfile(ob));
            a++;
            continue;
          }
          else {
            printf("%s\n*Failed to load: %s\n",emess,path+files[i]);
            b++;
            continue;
          }
        }
      }
      pl=({});
      inv=all_inventory(ob);
      env=environment(ob);
      name=file_name(ob);
      r=sscanf(name,"%s#%d",name,junk);
      for(j=0;j<sizeof(inv);j++) {
        if(interactive(inv[j])) {
          if(inv[j]!=this_player())
            tell_object(inv[j],"Your environment was updated by "
              +this_player()->query_name()+".\n");
          pl=pl+({inv[j]});
        }
        else destruct(inv[j]);
      }
      for(j=0;j<sizeof(pl);j++)
        move_object(pl[j],"/room/void");
      destruct(ob);
      if(!ob=find_object(path+files[i])) {
        emess=catch(call_other(name,"load_object"));
        if(!r) ob=find_object(name);
        else ob=clone_object(name);
        if(!ob) {
          for(j=0;j<sizeof(pl);j++) {
            if(pl[i]!=this_player()) {
              tell_object(pl[j],"The room failed to reload, "
                               +"and you are sent to the void.\n");
            }
          }
          printf("%s\n*Failed to reload: %s.\n",
          emess,path+files[i]);
          b++;
        }
        if(env) move_object(ob,env);
        else {
          if(emess) {
            printf("%s\n*Warning in reloading: %s.\n",
            emess,wfile(ob));
            a++;
          }
          else {
            printf("*Reloaded: %s.\n",wfile(ob));
            c++;
          }
          for(j=0;j<sizeof(pl);j++)
            move_object(pl[j],name);
        }
      }
      else printf("*Cannot update: %s\n",wfile(ob));
    }
    write("\n");
    if(f) printf("*Total: %3d out of %3d files loaded.\n",
            f,d);
    if(c) printf("*Total: %3d out of %3d files updated and reloaded.\n",
            c,d);
    if(a) printf("*Total: %3d out of %3d files reloaded, but gave a warning.\n",
            a,d);
    if(b) printf("*Total: %3d out of %3d files failed to reload.\n",
            b,d);
    if(e) printf("*Total: %3d out of %3d files ignored.\n",
            e,d);
    return 1;
  }
  else {
    for(i=0;i<10;i++) {
      if(file_size(path+files[i])==-2 || !sscanf(files[i],"%s.c",altstr)) {
        printf("*Ignored: %s\n",path+files[i]);
        e++;
        continue;
      }
      else if(!ob=find_object(path+files[i])) {
        if(!emess=catch(call_other(path+files[i],"???"))) {
          if(ob=find_object(path+files[i])) {
            printf("*Loaded: %s\n",wfile(ob));
            f++;
            continue;
          }
        }
        else {
          if(ob=find_object(path+files[i])) {
            printf("%s\n*Warning in loading: %s\n",emess,wfile(ob));
            a++;
            continue;
          }
          else {
            printf("%s\n*Failed to load: %s\n",emess,path+files[i]);
            b++;
            continue;
          }
        }
      }
      pl=({});
      inv=all_inventory(ob);
      env=environment(ob);
      name=file_name(ob);
      r=sscanf(name,"%s#%d",name,junk);
      for(j=0;j<sizeof(inv);j++) {
        if(interactive(inv[j])) {
          if(inv[j]!=this_player())
            tell_object(inv[j],"Your environment was updated by "
              +this_player()->query_name()+".\n");
          pl=pl+({inv[j]});
        }
        else destruct(inv[j]);
      }
      for(j=0;j<sizeof(pl);j++)
        move_object(pl[j],"/room/void");
      destruct(ob);
      if(!ob=find_object(path+files[i])) {
        emess=catch(call_other(name,"load_object"));
        if(!r) ob=find_object(name);
        else ob=clone_object(name);
        if(!ob) {
          for(j=0;j<sizeof(pl);j++) {
            if(pl[i]!=this_player()) {
              tell_object(pl[j],"The room failed to reload, "
                               +"and you are sent to the void.\n");
            }
          }
          printf("%s\n*Failed to reload: %s.\n",
          emess,path+files[i]);
          b++;
        }
        if(env) move_object(ob,env);
        else {
          if(emess) {
            printf("%s\n*Warning in reloading: %s.\n",
            emess,wfile(ob));
            a++;
          }
          else {
            printf("*Reloaded: %s.\n",wfile(ob));
            c++;
          }
          for(j=0;j<sizeof(pl);j++)
            move_object(pl[j],name);
        }
      }
      else printf("*Cannot update: %s\n",wfile(ob));
    }
    call_out("_load2",2,10,a,b,c,d,e,f,files,path);
    write("\n");
    if(f) printf("*Total: %3d out of %3d files loaded.\n",
            f,d);
    if(c) printf("*Total: %3d out of %3d files updated and reloaded.\n",
            c,d);
    if(a) printf("*Total: %3d out of %3d files reloaded, but gave a warning.\n",
            a,d);
    if(b) printf("*Total: %3d out of %3d files failed to reload.\n",
            b,d);
    if(e) printf("*Total: %3d out of %3d files ignored.\n",
            e,d);
    return 1;
  }
}