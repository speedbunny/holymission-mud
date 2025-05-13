#define IsFile(str) (file_size(str)>=0)
#define inventorya all_inventory
#define error(str) return (int)notify_fail(str)
#define IsDir(str)  (file_size(str)==-2)
#define exists(str) (file_size(str)!=-1)
#define abs(x) (x>=0?x:-x)

#pragma strict_types
#pragma save_types

/* declarations */
string pad(string str, int len, int char);
int IsPlayer(object ob);
string wfile(object ob);
string write_var(mixed var, int offset);
string Write_var(mixed var, int offset);
string process(string str);
string *get_files(string str);
mixed super_find(string str);
int index(mixed *arr, mixed a);
mixed *deletea(mixed *arr, int n);
string allocate_string(int size);

string allocate_string(int size) {
  string ret;
  int i;
  ret="";
  for(i=0;i<size;i++) ret+=" ";
  return ret;
}

mixed *deletea(mixed *arr,int n) {
  mixed *ret;
  int i;
  if(!sizeof(arr)) {
    write("*File: Array has no size.");
    return 0;
  }
  if(!pointerp(arr)) {
    write("*File: Bad array.");
    return 0;
  }
  if(!intp(n))
    return 0;
  ret=({});
  if(n>0)
    for(i=0;i<n;i++)
      ret+=({arr[i]});
  if(n<sizeof(arr)-1)
    for(i=n+1;i<sizeof(arr);i++)
      ret+=({arr[i]});
  return ret;
}

int index(mixed *arr,mixed a) {
  int i;
  for(i=0;i<sizeof(arr);i++)
    if(arr[i]==a)
      return i;
  return -1;
}

string pad(string str,int len,int char) {
  string ret;
  int i,size;
  size=abs(len);
  ret=allocate_string(size);
  if(strlen(str)>=size) len=size;
  if(len>= 0) {
    for(i=0;i<size;i++) {
      if(i<strlen(str)) ret[i]=str[i];
      else ret[i]=(char ? char : 32);
    }
  }
  else {
    for(i=0;i<size;i++) {
      if(strlen(str)+i<size)
      ret[i]=(char?char:32);
      else ret[i]=str[i-size+strlen(str)];
    }
  }
  return ret;
}

int IsPlayer(object ob) {
  string str;
  str=file_name(ob);
  if(sscanf(str,"obj/player#%s",str))
    return 1;
}

string wfile(object ob){
  string pname,ret;
  if(!ob)
    return "NULL_OBJECT: []";
  catch(pname=capitalize((string)ob->query_name()));
  if(!pname)
    pname="Un-Named";
  if(IsPlayer(ob)) {
    ret=(ob->query_level()<30?"PLAYER":"WIZARD");
    ret+=": <"+ob->query_level()+"> ";
    ret+=capitalize((string)ob->query_real_name());
    if(!interactive(ob))
      ret+=" (NET-DEAD)";
    else if(query_idle(ob)>=60)
      ret+=" ("+(query_idle(ob)/60)+"m)";
    else if(query_idle(ob))
      ret+=" ("+(query_idle(ob))+"s)";
  }
  else if(ob->query_npc())
    ret="MONSTER: "+pname;
  else if(ob->query_living())
    ret="LIVING: "+pname;
  else if(ob->query_name())
    ret="OBJECT: "+pname;
  else if(ob->short() && !environment(ob))
    ret="ROOM:";
  else if(function_exists("sh_init",ob))
    ret="SHADOW:";
  else
    ret="NAMELESS:";
  ret+=" ["+file_name(ob)+"]";
  return ret;
}
 
string write_var(mixed var,int offset) {
  int i;
  mixed *k;
  string *lines,ret;
  if(!var)
    return("0");
  if(intp(var) || floatp(var))
    return ""+var;
  if(stringp(var)) {
    lines=explode(var,"\n");
    var=implode(lines,"\\n\"+\n\"");
    return "\""+var+"\"";
  }
  if(objectp(var))
    return wfile(var);
  if(pointerp(var)) {
    ret="({ ";
    for(i=0;i<sizeof(var);i++) {
      if(pointerp(var[i]))
        ret+=write_var(var[i],offset+3)+
          (i<sizeof(var)-1?",\n":"\n")+
          pad("",offset+3,0);
      else ret+=write_var(var[i],offset+3);
      if(i<sizeof(var)-1 && !pointerp(var[i]))
        ret+=", ";
    }
    return ret+" })";
  }
}

string Write_var(mixed var,int offset) {
  int i;
  write(pad("",offset,0));
  if(!var)
    write("0");
  else if(intp(var) || floatp(var))
    write(var);
  else if(stringp(var))
    write("\""+var+"\"");
  else if(objectp(var))
    write(wfile(var));
  else if(pointerp(var)) {
    write("({\n");
    for(i=0;i<sizeof(var);i++)
      write_var(var[i],offset+4);
    write(pad("",offset,0)+"})");
  }
  if(offset)
    write(",\n");
  else
    write(".\n");
}
 
string process(string str) {
  int i;
  string *strs;
  if(!str || str=="")
    str="/"+this_player()->query_path();
  if(sscanf(str,"&%s",str))
    str="/players/"+this_player()->query_real_name()+"/"+str;
  if(sscanf(str,"~%s",str))
    str="/players/"+str;
  if(strlen(str)>0 && str[0]!=47)
    str="/"+this_player()->query_path()+"/"+str;
  strs=explode(str,"/");
  while(strs && (i=index(strs,""))>-1)
    strs=deletea(strs,i);
  while(strs && (i=index(strs,"."))>-1)
    strs=deletea(strs,i);
  while(strs && (i=index(strs,".."))>-1) {
    strs=deletea(strs,i);
    if(i>0) strs=deletea(strs,i-1);
  }
  str="";
  for(i=0;i<sizeof(strs);i++)
    str=str+"/"+strs[i];
  return str;
}
 
string *get_files(string str) {
  string *args,*files,*temp,a,b;
  int i,j,last;
  files=({ });
  args=explode(str," ");
  for(i=0;i<sizeof(args);i++) {
    args[i]=process(args[i]);
    if(sscanf(args[i],"%s*%s",str,str)) {
      temp=get_dir(args[i]);
      for(j=0;j<strlen(args[i]);j++)
      if(args[i][j]==47)
        last=j;
      args[i]=extract(args[i],0,last);
      for(j=0;j<sizeof(temp);j++) {
        if(temp[j]=="..")
          continue;
        temp[j]=args[i]+temp[j];
        if(!IsDir(temp[j]))
          files+=({temp[j]});
      }
    }
    else {
      if(IsFile(args[i]))
        files+=({args[i]});
      else if(IsFile(args[i]+".c"))
        files+=({args[i]+".c"});
      else
        write("*File: "+args[i]+" does not exist.\n");
    }
  }
  return files;
}
 
mixed super_find(string str) {
  mixed mix;
  object pl,ob;
  string args;
  if(!str || str=="" || str=="me")
    return this_player();
  if(str=="here")
    return environment(this_player());
  if(sscanf(str,"%s>%s",str,args)) {
    mix=super_find(str);
    if(!objectp(mix))
      return mix;
    else pl=mix;
    while(args) {
      str=args;
      if(!sscanf(args,"%s>%s",str,args))
        args=0;
      if(ob=present(str,pl))
        pl=ob;
      else
        return "Object "+str+" not found in "+wfile(pl)+".\n";
    }
    return pl;
  }
  if(sscanf(str,"#%s",str)) {
    mix=super_find(str);
    if(!objectp(mix))
      return mix;
    else
      pl=mix;
    if(!environment(pl))
      return "Object "+wfile(pl)+" has no environment.\n";
    return environment(pl);
  }
  if(sscanf(str,"@%s",str)) {
    pl=find_player(str);
    if(!pl)
      return "Player "+capitalize(str)+" not found.\n";
    return pl;
  }
  if( sscanf(str,"$%s",str)) { 
    pl=find_living(str);
    if(!pl)
      return "Living creature "+capitalize(str)+" not found.\n";
    return pl;
  }
  if(sscanf(str,"?%s",str)) {
    pl=present(str,this_player());
    if(!pl)
      pl=present(str,environment(this_player()));
    if(!pl)
      return "Object "+str+" not found in or around you.\n";
    return pl;
  }
  if(sscanf(str,":%s",str) || str[0]==47 || str[0]==126) {
    str=process(str);
    pl=find_object(str);
    if(pl)
      return pl;
    if(sscanf(str,"%s#%s",str,str))
      return "Object not found: "+str+"\n";
    if(!file_size(str+".c")>=0)
      return "No such file or object: "+str+".c\n";
    catch(call_other(str,"load_object"));
    pl=find_object(str);
    if(!pl)
      return "*Error in loading file: "+str+".c\n";
    return pl;
  }
  mix=super_find("@"+str);
  if(!objectp(mix))
    mix=super_find("?"+str);
  if(!objectp(mix))
    mix=super_find("$"+str);
  if(!objectp(mix))
    mix=super_find(":"+str);
  if(!objectp(mix))
    return "Object "+str+" not found ANYWHERE!!!\n";
  return mix;
}

mixed *del_array(mixed *array,int index) {
  return array-=({array[index]});
}

string lib_fn_expand(string f1) {
  string oldf1,tmp1,tmp2;
  string *strarr;
  int i,j;
  if(!f1)
    return "/"+this_player()->query_path();
  oldf1=f1;
  /* expand '~/file' to '/players/<wizname>/file' */
  if(sscanf(f1,"~/%s",tmp1)==1)
  f1="/players/"+this_player()->query_real_name()+"/"+tmp1;
  /* expand '~wizname/file' to '/players/wizname/file' */
  if(sscanf(f1,"~%s/%s",tmp1,tmp2)==2) {
    if(file_size("/players/"+tmp1)==-2)
      f1="/players/"+tmp1+"/"+tmp2;
    else {
      write("*File: Error: No such wiz as "+tmp1+".\n");
      return 0;
    }
  }
  /* expand '~wizname' to '/players/wizname' */
  if(sscanf(f1,"~%s",tmp1)==1) {
    if(tmp1=="")
      f1="/players/"+this_player()->query_real_name();
    else if(file_size("/players/"+tmp1)==-2)
      f1="/players/"+tmp1;
    else {
      write("*File: Error: No such wiz as "+tmp1+".\n");
      return 0;
    }
  }

  /* current dir if not starting from root */
  if(f1[0..0]!="/")
    f1="/"+this_player()->query_path()+"/"+f1;
  /* Deal with '..' and '.' */
  strarr=explode(f1,"/");
  for(i=1;i<sizeof(strarr);i++) {
    if(strarr[i]==".") strarr[i]=0;
    if(strarr[i]=="..") {
      strarr[i]=0;
      for(j=i;!strarr[j]&&j;j--);
        if(j)
          strarr[j]=0;
        else {
          write("*File: Error: Tried to access file below root directory.\n");
          return 0;
        }
    }
  }
  f1=implode(strarr,"/");
  return f1;
}

void lib_failed() {
  write("*File: Failed!\n");
  return;
}

int lib_file_exists(string f1) {
  int s1;
  s1=file_size(f1);
  return (s1>=0);
}

string *lib_get_strings(string s) {
  string *sa,*ta,*ta2,ts;
  int j,k,instr;
  if(!s)
    return ({});
  ta=explode(s,"\"");
  sa=({});
  ts="";
  instr=0;
  for(k=0;k<sizeof(ta);k++) {
    if(instr) {
      ts+=ta[k];
      if(!strlen(ts))
        instr=0;
      else if(strlen(ts)>1 && ts[strlen(ts)-1]==92 &&
                              ts[strlen(ts)-2]==92) {
        ts=ts[0..<2];
        sa+=({ts});
        ts="";
        instr=0;
      }
      else if(ts[strlen(ts)-1]==92)
        ts=ts[0..<2]+"\"";
      else {
        sa+=({ts});
        ts="";
        instr=0;
      }
    }
    else {
      ta2=explode(ta[k]," ");
      for(j=0;j<sizeof(ta2);j++)
        if(strlen(ta2[j]))
          sa+=({ta2[j]});
      instr=1;
    }
  }
  return sa;
}