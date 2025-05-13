#ifndef __SAURON_FUNCTIONS_C__

#define __SAURON_FUNCTIONS_C__

#include "/players/sauron/include/defs.h"

int s_sort(string str1,string str2);
int i_sort(int i1,int i2);
void OTELLR(object ob,string str,mixed exc);
status INVIS_TO_TP(object ob);
string *cap_array(string *arr);
varargs string list_nicely(string *list,int o);
varargs string dir_or_file(string path,int c);
void my_log_file(string log,string str);
varargs int gausian(int i,int j,int flag,int hits);


int s_sort(string str1,string str2) {
  string s1,s2;
  s1=str1[0..0];
  s2=str2[0..0];
  if(s1==s2) {
    s1=str1[1..1];
    s2=str2[1..1];
  }
  if(s1==s2) {
    s1=str1[2..2];
    s2=str2[2..2];
  }
  if(s1==s2) {
    s1=str1[3..3];
    s2=str2[3..3];
  }
  if(s1==s2) {
    s1=str1[4..4];
    s2=str2[4..4];
  }
  return (s1<s2)?-1:(s1!=s2);
}

int i_sort(int i1,int i2) {
  return (i1<i2)?-1:(i1!=i2);
}

void OTELLR(object ob,string str,mixed exc) {
  object *inv;
  int i;
  inv=all_inventory(ob);
  if(objectp(exc))
    inv-=({exc});
  else if(pointerp(exc)) {
    for(i=0;i<sizeof(exc);i++) {
      if(member_array(exc[i],inv)!=-1)
        inv-=({exc[i]});
      else
         continue;
    }
  }
  for(i=0;i<sizeof(inv);i++) {
    if(interactive(inv[i]))
      tell_object(inv[i],lw(str));
    else
      continue;
  }
}

status INVIS_TO_TP(object ob) {
  return (int)ob->query_invis()>=(int)this_player()->query_level();
}

string *cap_array(string *arr) {
  int i,s;
  if(!pointerp(arr))
    return ({});
  else if(!(s=sizeof(arr)))
    return arr;
  else {
    for(i=0;i<s;i++) {
      arr[i]=capitalize(arr[i]);
    }
  }
  return arr;
}

varargs string list_nicely(string *list,int o) {

// NB. o = 0 -> unordered, uncap list
//     o = 1 -> ordered, uncap list
//     o = 2 -> unordered, cap list
//     o = 3 -> ordered, cap list

  int i,j;
  string ret;
  j=sizeof(list);
  if(o%2)
    list=sort_array(list,"s_sort",this_object());
  if(o/2)
    list=cap_array(list);
  switch(j) {
    case 0:
      return "";
      break;
    case 1:
      return list[0]+".";
      break;
    case 2:
      return list[0]+" and "+list[1]+".";
      break;
    default:
      ret="";
      for(i=0;i<j-2;i++)
        ret+=list[i]+", ";
      return ret+list[j-2]+" and "+list[j-1]+".";
      break;
  }
}

varargs string dir_or_file(string path,int c) {
  string ret;
  switch(file_size(path)) {
    case -2:
      ret="directory";
      break;
    case -1:
      ret="doesn't exist";
      break;
    default:
      ret="file";
      break;
  }
  if(c)
    ret=capitalize(ret);
  return ret;
}

void my_log_file(string log,string entry) {
  mixed *st;
  log=LOG+log;
  entry=lwnl(ctime()[4..<6]+": "+entry);
  if(sizeof(st=get_dir(log,7)) && ((int)st[0][1]>MAX_LOG_SIZE))
    catch(rename(log,log+".old")); // No panic if failure
  write_file(log,entry);
  WROOM->log_notify(log,entry,file_name(this_object()));
  return;
}

varargs int gausian(int i,int j,int flag,int hits) {
  int k,num,ret,*arr;

  if(i<0 || j<0 || i>=j || flag<0 || flag>2)
    return -1;

  if(!hits || hits<=1)
    hits=7;
  arr=allocate(hits);
  for(k=0;k<hits;k++) {
    num=random(j+1-i)+i;
    if(!k)
      ret=num;
    switch(flag) {
      case 0:
        ret<=num?ret:ret=num;
        break;
      case 1:
        arr[k]=num;
        break;
      case 2:
        ret>=num?ret:ret=num;
        break;
    }
  }
  if(flag!=1)
    return ret;
  arr=sort_array(arr,"i_sort",this_object());
  k=(hits/2);
  return arr[k];
}

#endif // __SAURON_FUNCTIONS_C__
