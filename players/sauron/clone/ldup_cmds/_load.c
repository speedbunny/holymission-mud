inherit "/players/sauron/clone/ldup_cmds/extras";

#pragma strict_types
#pragma save_types

string emess,altstr;
int i,z;
object ob,ob2,ob3;

int get_dir_filter(string file) {
  return file[<2..<1]==".c";
}

int _load2(int k,int a,int b,int c,int d,int e,int f,
             string *files) {
  if(d<k+10) {
    for(i=k;i<d;i++) {
      if(files[i]=="." || files[i]=="..") {
        z++;
        continue;
      }
      else if(file_size(files[i])==-2 || !sscanf(files[i],"%s.c",altstr)) {
        printf("*Ignored: %s\n",files[i]);
        f++;
        continue;
      }
      else if(ob=find_object(files[i])) {
        printf("*Already loaded: %s\n",wfile(ob));
        e++;
        continue;
      }
      else if(!emess=catch(call_other(files[i],"???"))) {
        if(ob2=find_object(files[i])) {
          printf("*Loaded: %s\n",wfile(ob2));
          c++;
        }
        else
          printf("*Odd: %s\n",files[i]);
      }
      else {
        if(ob3=find_object(files[i])) {
          printf("%s\n*Warning in loading: %s\n",emess,wfile(ob3));
          a++;
        }
        else {
          printf("%s\n*Failed to load: %s\n",emess,files[i]);
          b++;
        }
      }
    }
    write("\n");
    if(c)
      printf("*Total: %3d out of %3d files loaded.\n",
             c,(d-z));
    if(a)
      printf("*Total: %3d out of %3d files loaded, but gave a warning.\n",
             a,(d-z));
    if(e)
      printf("*Total: %3d out of %3d files already loaded.\n",
             e,(d-z));
    if(b)
      printf("*Total: %3d out of %3d files failed to load.\n",
             b,(d-z));
    if(f)
       printf("*Total: %3d out of %3d files ignored.\n",
             f,(d-z));
    return 1;
  }
  else {
    for(i=k;i<k+10;i++) {
      if(files[i]=="." || files[i]=="..") {
        z++;
        continue;
      }
      else if(file_size(files[i])==-2 || !sscanf(files[i],"%s.c",altstr)) {
        printf("*Ignored: %s\n",files[i]);
        f++;
        continue;
      }
      else if(ob=find_object(files[i])){
        printf("*Already loaded: %s\n",wfile(ob));
        e++;
        continue;
      }
      else if(!emess=catch(call_other(files[i],"???"))) {
        if(ob2=find_object(files[i])) {
          printf("*Loaded: %s\n",wfile(ob2));
          c++;
        }
        else
          printf("*Odd: %s\n",files[i]);
      }
      else {
        if(ob3=find_object(files[i])) {
          printf("%s\n*Warning in loading: %s\n",emess,wfile(ob3));
          a++;
        }
        else {
          printf("%s\n*Failed to load: %s\n",emess,files[i]);
          b++;
        }
      }
    }
    call_out("_load2",2,k+10,a,b,c,d,e,f,files);
    write("\n");
    if(c)
      printf("*Total: %3d out of %3d files loaded.\n",
             c,(d-z));
    if(a)
      printf("*Total: %3d out of %3d files loaded, but gave a warning.\n",
             a,(d-z));
    if(e)
      printf("*Total: %3d out of %3d files already loaded.\n",
             e,(d-z));
    if(b)
      printf("*Total: %3d out of %3d files failed to load.\n",
             b,(d-z));
    if(f)
      printf("*Total: %3d out of %3d files ignored.\n",
             f,(d-z));
    write("\n");
    return 1;
  }
}

int _load(string str) {
  string path,*files,*exstr,*exstr2,*tmp;
  int a,b,c,d,e,f;
  if(!str)
    return (int)notify_fail("Syntax: load <file(s)>\n");
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
  }

  d=sizeof(files);
  z=0;
  if(d<=10) {
    for(i=0;i<d;i++) {
      if(files[i]=="." || files[i]=="..") {
        z++;
        continue;
      }
      else if(file_size(files[i])==-2 || !sscanf(files[i],"%s.c",altstr)) {
        printf("*Ignored: %s\n",files[i]);
        f++;
        continue;
      }
      else if(ob=find_object(files[i])) {
        printf("*Already loaded: %s\n",wfile(ob));
        e++;
        continue;
      }
      else if(!emess=catch(call_other(files[i],"???"))) {
        if(ob2=find_object(files[i])) {
          printf("*Loaded: %s\n",wfile(ob2));
          c++;
        }
        else
          printf("*Odd: %s\n",files[i]);
      }
      else {
        if(ob3=find_object(files[i])) {
          printf("%s\n*Warning in loading: %s\n",emess,wfile(ob3));
          a++;
        }
        else {
          printf("%s\n*Failed to load: %s\n",emess,files[i]);
          b++;
        }
      }
    }
    write("\n");
    if(c)
      printf("*Total: %3d out of %3d files loaded.\n",
             c,(d-z));
    if(a)
      printf("*Total: %3d out of %3d files loaded, but gave a warning.\n",
             a,(d-z));
    if(e)
      printf("*Total: %3d out of %3d files already loaded.\n",
             e,(d-z));
    if(b)
      printf("*Total: %3d out of %3d files failed to load.\n",
             b,(d-z));
    if(f)
      printf("*Total: %3d out of %3d files ignored.\n",
             f,(d-z));
    return 1;
  }
  else {
    for(i=0;i<10;i++) {
      if(files[i]=="." || files[i]=="..") {
        z++;
        continue;
      }
      else if(file_size(files[i])==-2 || !sscanf(files[i],"%s.c",altstr)) {
        printf("*Ignored: %s\n",files[i]);
        f++;
        continue;
      }
      else if(ob=find_object(files[i])) {
        printf("*Already loaded: %s\n",wfile(ob));
        e++;
        continue;
      }
      else if(!emess=catch(call_other(files[i],"???"))) {
        if(ob2=find_object(files[i])) {
          printf("*Loaded: %s\n",wfile(ob2));
          c++;
        }
        else
          printf("*Odd: %s\n",files[i]);
      }
      else {
        if(ob3=find_object(files[i])) {
          printf("%s\n*Warning in loading: %s\n",emess,wfile(ob3));
          a++;
        }
        else {
          printf("%s\n*Failed to load: %s\n",emess,files[i]);
          b++;
        }
      }
    }
    call_out("_load2",2,10,c,e,b,a,files,d,f);
    write("\n");
    if(c) printf("*Total: %3d out of %3d files loaded.\n",
            c,(d-z));
    if(a) printf("*Total: %3d out of %3d files loaded, but gave a warning.\n",
            a,(d-z));
    if(e) printf("*Total: %3d out of %3d files already loaded.\n",
            e,(d-z));
    if(b) printf("*Total: %3d out of %3d files failed to load.\n",
            b,(d-z));
    if(f) printf("*Total: %3d out of %3d files ignored.\n",
            f,(d-z));
    write("\n");
    return 1;
  }
}
