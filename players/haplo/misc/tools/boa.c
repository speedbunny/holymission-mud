/*  THU:04.11.92 .. 09.11.92  THU=Klorathy
 *  THU:04.12.92   Fixing updateing
 *
 *  The Blue Feather Boa (tm) Release 2.01
 *
 *  Thanks to Patience and Llort who helped me.
 *
 *  Typos in the long_desc and help are an offence against seriousity.
 */

/*  known errors:
 *  if directories grow larger than the allowed size, i cannot address the
 *  higher indices...
 */

inherit "/obj/thing";

#define LOGFILE "/log/"+name
#define morelines 20
#define SECURITY0 if (!((int)this_player()->query_immortal())) return 0
#define SECURITY1 if (!((int)this_player()->query_newwiz())) return 0
#define SECURITY2 if (!((int)this_player()->query_wizard())) return 0
#define DEBUG(x) write("debug: "+x+"\n")

static string name;
static int d,dc,tr,wild;
static int moreoffset,moreflag;
static string morefile,morepattern;
static string *strs,*finfo,path,ext,pldir,copypath,copyfile,firstdir;
static string tfile,ext,*pinfo,pat;
static int rec,grepped,grepfiles;

/*--------------------------------------------------------------------------*/
string query_auto_load() {
  return (explode(file_name(this_object()),"#"))[0]+":";
}
/*--------------------------------------------------------------------------*/
string query_creator() {
  return "klorathy";
}
/*--------------------------------------------------------------------------*/
string query_info() {
  return "a powerful tool";
}
/*--------------------------------------------------------------------------*/
void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  long_desc="Brring colourr innto thiss MUD!\n"+
            "Klorathy's magicks and tailloring iss the besst inn the world.\n"+
            "Taip 'help boa' to get an impreshion about thiss ffine tool.\n";
}
/*--------------------------------------------------------------------------*/
int id(string str) {
  return str=="boa";
}
/*--------------------------------------------------------------------------*/
string short() {
  object obj;
  obj=environment(this_object());
/* fucking bullshit! Llort
  if (name && this_interactive()!=obj) {
    if (obj==find_player(name) && (int)obj->query_wizard())
      tell_object(obj,capitalize((string)this_player()->query_real_name())+
                      " checks your inventory ["+query_verb()+"]\n");
  }
*/
  return "a Blue Feather Boa (tm) Release2.04" +
     ((environment(this_object())==find_player(name)) ? " (worn)" : "") ;
}
/*--------------------------------------------------------------------------*/
void init() {
  ::init();
  if (this_player()!=environment(this_object())) return;
  add_action("m_beep", "beep");
    /* beep a player */
  add_action("m_check",  "clone");
  add_action("m_check",  "load");
  add_action("m_check",  "goto");
    /* check errors */
  add_action("m_rm",   "rmfile");
    /* remove files */
  add_action("m_help", "help");
    /* my help command */
  add_action("m_copy", "cp");
  add_action("m_copy", "mv");
    /* copy files */
  add_action("m_up",   "update");
    /* update files */
  add_action("m_ls",   "dir");
  /*add_action("m_ls",   "ls");*/
    /* list directories */
  add_action("m_grep", "grep");
  add_action("m_grep", "rgrep");
    /* the grep */
  add_action("m_stop", "stop");
    /* stop command for longer evaluations */
  
  add_action("m_check","cd");
  add_action("m_check","tail");
  add_action("m_check","ed");
  add_action("m_check","rm");
  add_action("m_check","mmore");
  add_action("m_check","ls");
  add_action("m_check","rmdir");
  add_action("m_check","mkdir");
    /* check filenames and replace "~" */
    
  if (!this_player() || !((int)this_player()->query_immortal())) name=0;
  else name=(string)this_player()->query_real_name();
}
/*--------------------------------------------------------------------------*/
int m_beep(string str) {
  object obj;
  if (!str || !name) {
    notify_fail("Usage: "+query_verb()+" <player>\n");
    return 0;
  }
  SECURITY2;
  if (!(obj=find_player(str))) {
    notify_fail("Cannot find this player.\n");
    return 0;
  }
  tell_object(obj,"   ");
  return 1;
}
/*--------------------------------------------------------------------------*/
mixed *_c_filename(string str) {
  /* transform filenames and paths into internal structure */
  string *paths,*file,*f2,f1;
  int i,j,u;
  
  if (!str) str="/"+(string)this_player()->query_path();
  else {
    f1="f"+str+"f";
    if (sizeof(explode(f1," "))>1 || sizeof(explode(f1,"..."))>1 ||
        sizeof(explode(f1,"//"))>1) return ({0,0,-2});
        
    if (str[0..0]=="~") {
      if (strlen(str)>1 && str[1..1]=="/") 
        str="/players/"+name+"/"+str[2..-1];
      else str="/players/"+str[1..-1];
    }
    else if (str[0..0]!="/")
      str="/"+(string)this_player()->query_path()+"/"+str;
  }
  
  paths=explode(str,"/");
  if (!paths) return ({"/",0,1});
  file=({});
  
  u=sizeof(paths);
  sscanf(paths[u-1],"%s*",f2);
  if (!f2) sscanf(paths[u-1],"%s?",f2);
  /*if (f2) paths[u-1]=f2;*/
  
  for (i=0; i<u; i++) {
    if (paths[i]==".") paths[i]=0;
    else if (paths[i]=="..") {
      if (!i) return ({0,0,-2});
      paths[i]=0;
      j=i-1;
      while (!paths[j]) if (!j) return ({0,0,-2}); else j--;
      paths[j]=0;
    }
  }
  
  if (f2) u--;
  for (i=0; i<u; i++) if (paths[i]) file+=({paths[i]});
  
  pldir= (sizeof(file)>1 && file[0]=="players") ? file[1] : 0;
  
  str="/"+implode(file,"/");
  if (f2) return ({str+(str=="/"?"":"/"),paths[u],0});
  
  i=file_size(str);
  if (i==-2) return ({ (str=="/" ? str : str+"/") ,0,1});
  if (i==-1) return ({str,0,-1});
  file[sizeof(file)-1]=0;
  str="/"+implode(file,"/");
  if (str!="/") str+="/";
  return ({str,paths[u-1],2});
}
/*--------------------------------------------------------------------------*/
int m_more(string str);
int m_goto(string str);

int m_check(string str) {
  SECURITY0;
  if (!name) return 0;
  if (str && str[0..0]=="~") {
    if (strlen(str)>1 && str[1..1]=="/")
      str="/players/"+name+"/"+str[2..strlen(str)-1];
    else str="/players/"+str[1..strlen(str)-1];
    /*write("Changed to "+str+"\n");*/
    command(query_verb()+" "+str,this_player());
    return 1;
  }
  if (query_verb()=="mmore") return m_more(str);
  if (member_array(query_verb(),({"goto","load","clone"}))>=0 && !dc) {
    rm(LOGFILE);
    call_out("error_check",0);
    dc++;
  }
  if (query_verb()=="goto") return m_goto(str);
  return 0;
}
/*--------------------------------------------------------------------------*/
int query_no_steal() { return 1; }
/*--------------------------------------------------------------------------*/
int drop() { return 1; }
/*--------------------------------------------------------------------------*/
int error_check() {
  if (file_size(LOGFILE)>=0) {
    write("\n--- ERRORS: -----------------------------------------------\n");
    cat(LOGFILE);
    write("-----------------------------------------------------------\n");
  }
  dc=0;
  return 1;
}
/*--------------------------------------------------------------------------*/
#define MAX 100
int d_dir(int page) {
  int i,m,a,u,w;
  string line,file;

  if (!tr) return 0;
  
  strs=({});
  write("--- "+path+ (ext=="*" ? "" : ext) +
        (sizeof(finfo)>MAX ? " ["+page+"]" : "")+
        " ---"+
        (!page ? " "+(w=sizeof(finfo))+(w==1? " entry" :" entries")+" ---" : "")+
        "\n");
  m=MAX*(page+1)-1;
  
  if (m>sizeof(finfo)) m=sizeof(finfo);
  for (i=MAX*page; i<m; i++) {
    file=finfo[i];
    if (sizeof(explode(file," "))==1) {
      switch (file_size(path+file)) {
        case -2: file+="/";
              break;
        case -1: file="- ??? -";
                 break;
        default: if (find_object(path+file)) file+="*";
      }
    }
    else file="["+file+"]";
    strs+=({file});
  }
  if (i<sizeof(finfo)) call_out("d_dir",0,page+1);
  else tr=0;
  u=sizeof(strs); m=0;
  for (i=0; i<u; i++) {
    if ((a=strlen(strs[i]))>m) m=a;
  }
  a=80/(m+2); line="";
  for (i=0; i<u; i++) {
     line+=(strs[i]+"                               ")[0..m+1];
     w=0;
     if (!((i+1)%a)) { line+="\n"; w=1; }
  }
  if (!w) line+="\n";
  write(line);
}
/*--------------------------------------------------------------------------*/
int m_ls(string str) {
  mixed *dir;
  
  SECURITY0;  
  if (tr) {
    write("Busy.\n");
    return 1;
  }
  dir=_c_filename(str);

/*
  if (dir[2]==2) {
    path=dir[0]+dir[1];
    write(path+"\nSize="+file_size(path)+"  Date="+ctime(file_date(path))+"\n");
    return 1;
  }
  else 
*/
  if (dir[2]<0  || dir[2]==2) {
    write("Illegal pathname.\n");
    return 1;
  }
  path=dir[0]; ext=(dir[1] ? dir[1] : "*");
  finfo=get_dir(path+ext);
  if (finfo) finfo-=({".",".."});
  if (!finfo) {
    write("--- "+path+(ext=="*" ? "":ext)+" ---\nNo such directory.\n");
    return 1;
  }
  tr=1;
  d_dir(0);
  return 1;
}
/*--------------------------------------------------------------------------*/
int m_help(string str) {
  SECURITY0;
  if (!str) return 0;
  if (this_object()!=present(str)) return 0;
  write(
    "\n---------------------------------------------------------------\n"+
    "                The Blue Feather Boa (tm)\n"+
    "               brought to thou by Klorathy\n"+
    "---------------------------------------------------------------\n"+
    "New commandss:\n"+
    "  * dir replaicess the well-known ls command and hass no\n"+
    "    problemms with laarge direcktoriss\n"+
    "  * cp copiess filess\n"+
    "  * mv movess filess\n"+
    "  * rmfile (wildcardss! so be ssure when thou do thatt...)\n"+
    "  * grep, witch listss the reecult in '.grep' of thouest root\n"+
    "    direcktory\n"+
    "  + the commandss abovve all work with wildcardss and jokerss\n"+
    "  * mmore is more [trie more ~klorathy/obj/boa.c 200]\n"+
    "  * beep to give a player three beepss\n"+
    "  * stop boa, when an evaluashion lastss too long\n"+
    "New featuress:\n"+
    "  * clone, load and goto on thouest own ffiles bringss syntaks\n"+
    "    errorss allmosst immediately automagickally at thouest\n"+
    "    sscreen\n"+
    "  * yousing the '~' in ffilenamess makess it easier to sswitch\n"+
    "    direcktoriss. [Youse ~klorathy/obj/nasenbaer insstead off\n"+
    "    /players/klorathy/obj/nasenbaer]\n"+
    "  * update with wildcardss\n"+
    "New wizardss:\n"+
    "    beep, update, rmfile, mv and cp ar nothinng four thou!\n"+
    "New things:\n"+
    "  * if thou wannt to youse the file commands, inherit the tool!\n"+
    "  * note: iff an error with the boa ockurres, taip stop boa...\n"+
    "---------------------------------------------------------------\n\n");
  return 1;
  /* typos are no offense */
}
/*--------------------------------------------------------------------------*/
int d_cat() {
  int end;
  string f,l;
  
  end=moreoffset+morelines;
  while (moreoffset<end) {
    if(l=read_file(morefile,moreoffset,1)) {
      write(("     "+moreoffset)[-4..-1]+" "+l);
      moreoffset++;
    } else return 0;
  }
  if (read_file(morefile,moreoffset+1,1)) return 1;
  else return 0;
}
/*--------------------------------------------------------------------------*/
void d_more(string str) {
  int i, off;
  string f,l,r;
  
  if (str) {
    switch(str[0]) {
    case 'q':
    case 'x': moreflag=0;
              moreoffset=1;
              return 0;
    case 'U': moreoffset=moreoffset-morelines;
    case 'u': moreoffset=moreoffset-2*morelines;
              break;
    case 'D': moreoffset+=morelines;
    case 0:
    case 'd': if (moreflag) {
                moreflag=0;
                moreoffset=1;
                return;
              }
              break;
    case '/': i=moreoffset-morelines+1;
              if (str=="/" && morepattern) r=morepattern;
              else r=str[1..-1];
              morepattern=r;
              if (!regexp(({"dummy"}),r)) write("Bad regular expression.\n");
              else while ((l=read_file(morefile,i++,1)) && !sizeof(regexp(({l}),r)));
              if (l) {
                write("**** Skipping ...\n");
                moreoffset=i-1;
              } 
              else {
                write("**** Pattern not found\n");
                moreoffset-=morelines;
              }
              break;
    case '0'..'9':
              sscanf(str,"%d",i);
              moreoffset=i;
              break;
    }
  }
  else {
    /*moreoffset=1;*/
    moreflag=0;
  }
  if(moreoffset<1) moreoffset=1;
  if(d_cat()) {
    write("**** More: q,u,U,d,D,/<regexp>,<line> ["+(moreoffset-1)+"] **** ");
  } else {
    write("**** More: q,u,U,d,D,/<regexp>,<line> ["+(moreoffset-1)+"=EOF] **** ");
    moreflag=1;
  }
  input_to("d_more");
  return;
}
/*--------------------------------------------------------------------------*/
string check_filename(string str) {
  if (!str) return 0;
  else if (str[0..0]!="/") str=(string)this_player()->query_path()+"/"+str;
  if (str[0..0]!="/") str="/"+str;
  return str;
}
/*--------------------------------------------------------------------------*/
int m_more(string str) {
  string *args, file;
  int line;

  SECURITY0;
  notify_fail("Usage: "+query_verb()+" <filename> [<starting line>]\n");
  if (!str) return 0;
  
  switch (sizeof(args=explode(str, " "))) {
  case 1:
    moreoffset=1;
    break;
  case 2:
    sscanf(args[1],"%d",line);
    moreoffset= (line>0 ? line : 1);
    break;
  default:
    return 0;
  }
  morepattern=0;
  morefile=check_filename(args[0]);
  if (!morefile) return 0;

  /*** check validity ***/
  if (!((int)this_player()->valid_read(morefile))) {
    write("No read access...\n");
    return 1;
  }
  
  if (file_size(morefile)>=0) d_more(0);
  else write("Unknown file: "+morefile+"\n");
  return 1;
}
/*--------------------------------------------------------------------------*/
int d_onefile(string src, string dst) {
  int fpos,todo,chunk;
  string data;

  /*** check validity ***/
  if (rec && !((int)this_player()->valid_write(src))) {
    write("\nNo remove access...\n");
    return 0;
  }
  if (!((int)this_player()->valid_read(src))) {
    write("\nNo read access...\n");
    return 0;
  }
  if (!((int)this_player()->valid_write(dst))) {
    write("\nNo write access...\n");
    return 0;
  }

  todo=file_size(src); grepped+=todo;
  if (file_size(dst)>0) rm(dst);
  fpos=0;
  while (todo>0) {
    chunk=todo;
    if (chunk>10000) chunk=10000;
    data=read_bytes(src,fpos,chunk);
    /*if (strlen(data)) data=string_replace(data,"\r","");*/
    fpos+=chunk;
    todo-=chunk;
    if (data && !write_file(dst,data)) return 0;
  }
  if (rec) rm(src);
  return 1;
}
/*--------------------------------------------------------------------------*/
int d_copy(int num) {
  int i;
  string src,dest;
  
  if (!tr) return 0;
  
  tr=0;
  
  grepped=0;
  while (1) {
    src=path+finfo[num];
    if (file_size(src)>0) {
      if (file_size(src)==-1) ;
      else if (wild) {
        dest=copypath+finfo[num];
        write("Copying: "+src);
      }
      else {
        dest=copypath+copyfile;
        write("Copying: "+src+" to "+dest);
      }
      if (d_onefile(src,dest))
        write("    Complete.\n");
      else num=sizeof(finfo);
    }
    num++;
    if (num<sizeof(finfo)) {
      if (grepped>100000) {
        tr=1;
        call_out("d_copy",0,num);
        return 1;
      }
    }
    else if (sizeof(finfo)>1) {
      write("Copy completed.\n");
      return 1;
    }
    else return 1;
  }
}
/*--------------------------------------------------------------------------*/
int m_copy(string str) {
  mixed *dir1,*dir2;
  string f1,f2;

  SECURITY2;

  if (this_player()!=this_interactive()) return 1;
    /* should not happen, but one may be forced... */
  
  if (!str) {
    notify_fail("Usage: "+query_verb()+" <src> <dest>\n"+
                "  You might use wildcards and jokers.\n");
    return 0;
  }

  if (tr) {
    write("Busy.\n");
    return 1;
  }
  
  rec=(query_verb()=="mv");
  
  if (sscanf(str,"%s %s",f1,f2)!=2) return 0;
  dir1=_c_filename(f1);
  dir2=_c_filename(f2);
    
  wild=0;
  switch (dir1[2]) {
    case  0: f1=dir1[0]+dir1[1]; wild=1; break;
    case  2: f1=dir1[0]+dir1[1]; break;
    case  1: f1=dir1[0]+"*"; wild=1; break;
    case -2: write("Illegal source path.\n");
             return 1;
    case -1: write("Source path does not exist.\n");
             return 1;
    default: return 0;
  }
  
  switch (dir2[2]) {
    case  1: break;
    case -2: write("Illegal destination path.\n");
             return 1;
    case -1: if (wild) {
               write("Destination path does not exist.\n");
               return 1;
             }
             break;
    case  2: if (wild) {
               write("Destination is not a path.\n");
               return 1;
             }
             break;
    case  0: write("No wildcards in the destination path allowed.\n");
             return 1;
    default: return 0;
  }
  
  path=dir1[0];
  copypath=dir2[0]; copyfile=0;
  
  if (!wild) {
    copyfile=(dir2[2]==-1 ? "" : (dir2[1] ? dir2[1] : dir1[1]));
    if (!copyfile) {
      write("Mysterious copy error.\n");
      return 1;
    }
  }
  if (path==copypath && (wild || copyfile==dir1[1])) {
    write("Override abortion.\n");
    return 1;
  }
  
  finfo=get_dir(f1);
  if (finfo) finfo-=({".",".."});
  if (!finfo) {
    write("No such directory.\n");
    return 1;
  }
  tr=1;
  d_copy(0);
  return 1;
}
/*--------------------------------------------------------------------------*/
int m_rm(string str) {
  mixed *dir;
  int i;
  
  SECURITY2;  
  
  if (this_player()!=this_interactive()) return 1;
    /* should not happen, but one may be forced... */

  if (!str) {
    notify_fail("Usage: "+query_verb()+" <path>\n"+
          "  You might use wildcards and jokers, <path> may be a single file, too.\n");
    return 0;
  }

  if (tr) {
    write("Busy.\n");
    return 1;
  }
  dir=_c_filename(str);

  if (dir[2]<0 /*|| dir[2]==2*/) {
    write("Illegal pathname (or the file does not exist?).\n");
    return 1;
  }
  path=dir[0]; ext=(dir[1] ? dir[1] : "*");
  finfo=get_dir(path+ext);
  if (finfo) finfo-=({".",".."});
  if (!finfo) {
    write("No such file/directory.\n");
    return 1;
  }
  if (path=="/log/" && sizeof(finfo)>1) {
    write("Please delete all files separate.\n");
    return 1;
  }
  for (i=0; i<sizeof(finfo); i++) {
    if (file_size(path+finfo[i])>=0) {
      write("Deleting: "+path+finfo[i]+"\n");

      /*** check validity ***/
      if (!((int)this_player()->valid_write(path+finfo[i]))) {
        write("No write access...\n");
        return 1;
      }
      
      if (rm(path+finfo[i])) /*write("Complete.\n")*/;
      else break;
    }
  }
  /*if (sizeof(finfo)>1) write("Completed.\n");*/
  return 1;
}
/*--------------------------------------------------------------------------*/
int m_up(string str) {
  mixed *dir;
  int i;
  object obj;
  string c;
  
  SECURITY2;  

  if (!str) {
    write("Usage: "+query_verb()+" <path>\n"+
          "  You might use wildcards and jokers, <path> may be a single file, too.\n");
    return 1;
  }
  
  dir=_c_filename(str);

  if (dir[2]<0 || dir[2]==2) {
    return 0;
  }
  
  if (tr) {
    write("Busy.\n");
    return 1;
  }
  path=dir[0]; ext=(dir[1] ? dir[1] : "*");
  finfo=get_dir(path+ext);
  if (finfo) finfo-=({".",".."});
  if (!finfo) {
    write("No such file/directory.\n");
    return 1;
  }

  for (i=0; i<sizeof(finfo); i++) {
    c=path+finfo[i];
    if (!i && !((int)this_player()->valid_write(c))) {
      write("Update your own directories only!\n");
      return 1;
    }
    if (obj=find_object(c)) {
      destruct(obj);
    }
  }
  /*if (sizeof(finfo)>1) write("Completed.\n");*/
  write("Ok.\n");
  return 1;
}
/*--------------------------------------------------------------------------*/
int d_grepone() {
  int i,j,line,c;
  string *ts,t,str,file;
  
  if (!tr) return 0;
  
  tr=0;
  while (1) {
    file=path+finfo[d++];
    if ((int)this_player()->valid_read(file)) {
      if ((c=file_size(file))==-2) {
        if (rec) pinfo+=({file+"/"});
      }
      else if (c<=0) ;
      else {
        line=1; grepped+=c; grepfiles++;
        for (i=1; t=read_file(file,i,1000); i+=1000) {
          if (!t || !stringp(t) || t=="") ;
          else {
            ts=explode(t,"\n");
            if (stringp(ts)) ts=({ts});
              if (ts) {
                for (j=0; j<sizeof(ts); j++) {
                if (sizeof(regexp(({ts[j]}),pat))) {
                  write_file(tfile,/*str=*/file+"   line "+(j+line)+"\n"+ts[j]+"\n");
                  /*write(str);*/
                }
              }
              line+=sizeof(ts);
            }
          }
        }
      }
    }
    if (d==sizeof(finfo)) {
      if (!sizeof(pinfo)) {
        write("Grep ready.\n");
        return 1;
      }
      else {
        call_out("d_grep",0);
        tr=1;
        return 1;
      }
    }
    else {
      if (grepped>10000) {
        grepped=0;
        call_out("d_grepone",0);
        tr=1;
        return 1;
      }
    }
  }
}
/*--------------------------------------------------------------------------*/
int d_grep() {
  string f;
  int i;
  
  grepped=0; grepfiles=0;
  if (!tr) return 0;
  
  path=pinfo[0]; 
  pinfo-=({path});
  write("Grep directory: "+path+ext+"\n");
  
  finfo=get_dir(path+ext);
  if (finfo) finfo-=({".",".."});
  if (!finfo) {
    write("No such file/directory.\n");
    tr=0;
    return 1;
  }

  d=0;
  if (sizeof(finfo)) d_grepone(); 
  else if (sizeof(pinfo)) { d_grep();}
  else { tr=0; write("Grep ready.\n"); finfo=0; pinfo=0; }
}
/*--------------------------------------------------------------------------*/
int m_grep(string str) {
  mixed *dir;
  SECURITY1;
  if (tr) {
    write("Busy.\n");
    return 1;
  }
  if (!str || sscanf(str,"%s %s",str,pat)!=2) {
    notify_fail("Usage: "+query_verb()+" <path> <pattern>\n"+
          "  You might use wildcards and jokers, <path> may be a single file, too.\n"+
          "  The result is stored in /players/<your name>/.grep\n");
    return 0;
  }
  
  rec=query_verb()=="rgrep";
  
  tfile="/players/"+name+"/.grep";
  if (!((int)this_player()->valid_write(tfile))) {
    write("The boa refuses mysterically to do this.\n");
    return 1;
  }
  rm(tfile);
  dir=_c_filename(str);

  if (dir[2]<0 || dir[2]==2) {
    return 0;
  }
  path=dir[0]; ext=(dir[1] ? dir[1] : "*");
  pinfo=({path});
  
  write_file(tfile,"*** File: "+path+ext+" ***\n"); tr=1;
  write("Results are stored to: "+tfile+"\n");
  d_grep();
  return 1;
}
/*--------------------------------------------------------------------------*/
int m_stop(string str) {
  SECURITY1;
  if (!str) {
    notify_fail("Usage: "+query_verb()+" boa\n");
    return 0;
  }
  if (present(str)!=this_object()) return 0;
  if (tr) write("Ok.\n");
  tr=0;
  finfo=0; pinfo=0;
  return 1;
}
/*--------------------------------------------------------------------------*/
int m_goto(string str) {
  object obj;
  SECURITY1;
  if (!str) return 0;
  
  if (sizeof(explode(str,"#"))<=1) return 0;
  if (!(obj=find_object(str))) {
    write("Unknown object.\n");
    return 1;
  }
  this_player()->move_player("suddenly#"+str);
  return 1;
}
/*--------------------------------------------------------------------------*/
