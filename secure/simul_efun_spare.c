/*
 * This is a mudlib file. Copy it to /obj/simul_efun.c, or
 * wherever the get_simul_efun() in master.c says.
 * The functions defined in this file should only be replacements of efuns
 * no longer supported. Don't use these functions any longer, use the
 * replacement instead.
 */

#pragma strict_types
#pragma save_types

#include "/sys/include/sys_defs.h"
#include "/sys/include/sys_levels.h"

#define MAX_LOG_SIZE		50000
#define MAX_WIZ_LOG_SIZE	20000

closure call, tell, text, loop, roll;

void log_file(string file, string str);

void reset(int tick) {
  if(tick) return;

  tell = #'tell_object;
  call = #'call_other;
  text = lambda( ({ 't, 'ti, 'o, 'who }),
              ({ #'? , ({ call,'who,"is_invis_for",'o}), 'ti, 't }) );
  loop = lambda( ({ 'i, 'act, 'msg, 'src, 'inv, 'kind }),
      ({ #'while, ({ #'>=, 'i, 0 }), 0,
         ({ #',,
            ({ #'call_other, ({ #'[, 'inv, 'i }), "lcatch_tell",
               'act, 'msg, 'src, 'kind }),
            ({ #'=, 'i, ({ #'-, 'i, 1 }) })
         })
      }) );
  roll = lambda( ({ 'n, 'd, 'm }),
      ({ #'while, ({ #'>, 'n, 0 }), 'm,
         ({ #',,
            ({ #'=, 'm, ({ #'+, 1, ({ #'+, 'm, ({ #'random, 'd }) }) }) }),
            ({ #'=, 'n, ({ #'-, 'n, 1 }) })
         })
      }) );
}

void say(string txt, object ex, object who, string inv_txt) {
  int    i, j, k;
  object where,*inv; 

  if(!who || !inv_txt) {
    if(ex)
      return efun::say(txt,ex);
    else
      return efun::say(txt); 
  }

  if(!ENV(who))
    return;
  where = ENV(who);
  inv   = all_inventory(where);
  inv  -= ({ who });
  if(ex)
    inv -= ({ ex }); 
  j = sizeof(inv);
  i = 0;
  while(i < j) {
    funcall(tell, inv[i], funcall(text, txt, inv_txt, inv[i++], who));
  }
  tell_object(where, txt);
  return;
}

// A function to remove an entry from arrays or strings
mixed *del_array(mixed *array,int index) {
  int len;

  if(stringp(array))
    len = strlen((string)array);
  else if(pointerp(array))
    len = sizeof(array);
  else
    return array;
  if(index < 0 || index >= len)
    return array;
  return array[0..index-1] + array[index+1..len-1];
}

string clean_path(string path) {
  string *res, *hlp;
  int    i, noget;

  if(!path) return "";
  if(TP && path[0]=='~') 
    path = "/players/" + TP->RNAME + path[1..strlen(path)-1];
  if(path[0] != '/') path = "/" + path;
  if(path == "/") return path;
  if(sizeof(explode(path,"...")) > 1) return "";
  if(sizeof(explode(path,"//")) > 1) return "";
  if(sizeof(explode(path," ")) > 1) return "";
  if(!(hlp = explode(path,"/"))) return "";
  res = allocate(0);
  for(i = sizeof(hlp) - 1, noget = 0; i >= 0; i--) {
    if(hlp[i] != ".") {
      if(hlp[i] == "..") noget++;
      else if(noget) noget--;
      else res = ({ hlp[i] }) + res;
    }
  }
  if(noget) return ""; 
  path = implode(res,"/");
  if(path == "") return "/";
  else return path;
}

int roll_dice(int n, int d, int m) {
  return funcall(roll, n, d, m);
}

/*
 * The ls() function is no longer needed, as get_dir() can do the same
 * work.
 *
 * RE: Some directories are INCREDIBLY large. Therefore, we reintroduce
 *     the hardcoded ls() efun.
 *     The former lpc-ls is now available as "dir" for a beautful printout
 *     of any directory.
 *
 */
void dir(string path) {
  string *dir, *hlp, orig;
  int    trunc_flag,i, num, dirs;

  if(path[0] == '/' || path[0] == '~') { 
    if((path = clean_path(path)) == "") {
      write("Illegal path!\n");
      return; 
    }
    orig = path;
    write("[" + path + "]\n");
    if(file_size(path) == -2 && path != "/")
      dir = get_dir(path + "/*");
    else {
      dir = get_dir(path);
      hlp = explode(path, "/");
      if(sizeof(hlp) < 2)
        path = "";
      else
        path = implode(hlp[0..sizeof(hlp)-2], "/");
     }
  }
  else
    dir = get_dir(path);

  if(!sizeof(dir) && file_size(orig)!=-2) {
    write("No such file or directory.\n");
    return;
  }
  if((num = sizeof(dir)) > 330) {
    dir = dir[0..329];
    trunc_flag = 1;
  }
  if(path) path += "/";
  dirs = 0;
  for(i = 0; i < sizeof(dir); i++) {
    if(sizeof(explode(path + dir[i], " ")) <= 1) {
#if 0
/* LLORT */ write("simul_efun: path="+path+" dir="+dir[i]+"\n");
#endif
      switch(file_size(path + dir[i])) {
        case -2:
          dir[i] += "/";
          dirs++;
          break;
        case -1: break;
        case 0:
          dir[i] += "-";
          break;
        default:
          if(find_object(path + dir[i]))
            dir[i] += "*";
      }
    }
    else
      dir[i] += "?!?"; 
  }
  if(!dir)
    write("No such directory.\n");
  else {
    printf(" %-*#s\n", 79, implode(dir, "\n"));
    if(trunc_flag)
      write("***TRUNCATED***\n");
    printf("The directory contains %i directories and %i files.\n",
           dirs, num-dirs);
  }
} 

/*
 * The old 'slice_array' is no longer needed. Use range argument inside
 * a pair of brackets instead.
 */
mixed *slice_array(mixed *arr, int from, int to) {
  return arr[from..to];
}

#define xwrite(str) tell_room(this_object(),str+"\n")

static object get_him(object ob) {
  string tmp;
  int    l;

  if(!ob)
    return 0;
  if(PO && (tmp=explode(file_name(PO),"#")[0]) &&
     (tmp == "secure/login" ||
// Sauron: This isn't what I had in mind Rich!
//      tmp == "sys/bin/player/finger" ||
      tmp == "obj/tick"))
    return ob;
  if(TP && (tmp = (string)TP->RNAME) 
        && tmp == (string)ob->RNAME)
    return ob;
#if 1
// Sauron: Changed from 'TP->LEVEL >= ob->INVIS' to 'TP->LEVEL > ob->INVIS'
//         If invis to level 120, level 120 ppl should not see me.
  if(TP && query_ip_number(TP)
        && TP->LEVEL > ob->INVIS)
    return ob;
  if(!(TP && query_ip_number(TP)) && (!ob->query_immortal()))
    return ob;
  return 0;
#else
  if((TP ? (int)TP->LEVEL : 1) >= ob->INVIS)
    return ob;
  return 0;
#endif
}

nomask object *users() {
  int    i, j, sz;
  object *u, *v,herp;

#if 0
  herp = find_player("herp");
  if(herp)
    tell_object(herp, "sim/users called\n");
#endif

  u = efun::users();
  v = allocate(0);
  for(i = 0, sz = sizeof(u); i < sz; i++)
    if(get_him(u[i]) && u[i]->query_player())
      v += u[i..i];
  return v;
}

nomask object find_player(string str) {
  object ob;
  
  ob = efun::find_player(str);
  return get_him(ob);
}

nomask object find_living(string str) {
  object ob;

  ob = efun::find_living(str);
  return get_him(ob);
}

nomask object query_snoop(object obj) {
  object ob;

  ob = efun::query_snoop(obj);
  if(TP && !TP->query_elder())
    return 0;
  if(master_object()->get_wiz_level(TP)
        < master_object()->get_wiz_level(ob))
    return 0;
  return get_him(ob);
}


#if 0
nomask void wizlist(string arg) { // Moonchild
  if(TP && TP->query_lord() && interactive(TP))
    return efun::wizlist(arg);
  return 0;
}
#endif

void log_file(string file,string str) {
  string file_name;
  int    *st;

  file_name = "/log/" + file;
#ifdef COMPAT_FLAG
  if(sizeof(regexp(({file}), "/")) || file[0] == '.'
                                   || strlen(file) > 30 ) {
    write("Illegal file name to log_file(" + file + ")\n");
    return;
  }
#endif
  if((st = get_dir(file_name, 2) ) && sizeof(st)) {
    if(st[0] > (file_name[1..<1] == lower_case(file_name[1..<1]) ?
                MAX_WIZ_LOG_SIZE:
                MAX_LOG_SIZE))
      catch(rename(file_name, file_name + ".old")); // No panic if failure
  }
  set_this_object(previous_object());
  write_file(file_name, str);
}

nomask string version() {
  return __VERSION__;
}

int tell_object(object ob, string txt, object ob2) {
  efun::tell_object(ob, txt);
}

// Sauron: Is there a reaason to block the functionality like this?
void tell_room(mixed ob, string txt, object ob2) {
  efun::tell_room(ob, txt);
}

int filter_earmuffs(object ob, int lvl) {
  return (int)ob->query_earmuff_level() < lvl && ob!=TP;
}

varargs void shout(string sStr, object oOb) {
  int     i, iSz;
  object  *oUs, oPrev;

  oPrev = previous_object();
  if(creator(oPrev) || file_name(oPrev)[0..6] == "spells/")
    CD->do_chat(-1, sStr);
  else {
// Old shout() code here...
    oUs = filter_array(users(), "filter_earmuffs", this_object(),
      TP ? (int)TP->LEVEL:L_APPR);
    for(i = 0; i < sizeof(oUs); i++)
      tell_object(oUs[i], sStr, oOb);
  }
}

// ----- language handling (pat) start ---------------------------------

void lsay(string act, string msg, object src, object excl) {
  int    i;
  object *inv;

  if(!act || !msg || !src) return;
  if(!ENV(src)) return;

  inv  = all_inventory(ENV(src));
  inv += ({ENV(src)});
  if(excl) inv -= ({excl});
  inv -= ({src});
  i    = sizeof(inv) - 1;

  funcall(loop, i, act, msg, src, inv, 1);
}

int ltell(object dest, string act, string msg, object src) {
  if(dest && act && msg && src)
    return (apply(#'call_other, dest, "lcatch_tell", act, msg, src, 2));
  return 0;
}

void lshout(string act, string msg, object src) {
  int    i;
  object *inv;

  if(!(act && msg && src)) return;

  inv  = efun::users();
  inv -= ({src});
  i    = sizeof(inv) - 1;

  funcall(loop, i, act, msg, src, inv, 3);
}

// ----- language handling (pat) ent -----------------------------------

// implementation: Llort - 05.02.1995
// this function matches the give item to the strings in the list
// if there is amn exact match you get that one, else the first match
// we find
// Arguments:
//    list .. the strings to match with
//    item .. the string to be found
// Returns:
//    the index of the found match
//    -1 .. not found
//  -----------

int match_array(string *list, string item) {
  int i, cnt, idx;

  cnt = sizeof(list);
  idx = -1;
// search for a fitting in the list
  for(i = 0; i < cnt; i++) {
    if(list[i] == item)
      return i;
    if(idx == -1 && !strstr(list[i], item))
      idx = i;
  }
  return idx;
}

nomask varargs string break_text(string str, int width,
                                 int indent, int brk) {
  string res, indent_str;
  int    len, pos, old_pos;

  if(!str || str == "" || width < 2)
    return str;

  if(!brk) brk = ' ';
  if(!indent || indent < 0) {
    res     = str;
    indent  = 0;
    pos     = width;
    old_pos = 0;
  }
  else {
    for(pos=0, indent_str=""; pos<indent; indent_str+=" ", pos++) ;
    res     = indent_str + str;
    pos     = width + indent;
    old_pos = indent;
  }
  len = strlen(res);

  while(pos < len) {
    while(res[pos]!=brk && pos>old_pos)
      pos--;   // search for brks
    if(pos == old_pos)
      return str;        // there is none !
    res[pos] = '\n';     // replace brk by NL
    if(indent) {         // is there an indent ?
      if(pos < len) {    // something there ?
        res  = res[0..pos] + indent_str + res[pos+1..];  // concenate it
        len += indent;   // add indent to len
        pos += indent;
      }
    }
    old_pos = pos+1;     // remember first new char
    pos += (width+1);    // calc new pos
  }
  return res;
}

// Herp: it's illegal to move_objects to outside areas for new-wizzes

int check_legal_move(mixed item, mixed dest) {
  string icr, dcr;
  object iob, dob, ico;

  if(TP && TP->query_archwiz()) return 1;

  if(stringp(item)) {
    iob = find_object(item);
    if(!iob) {
      item->load_me();
      iob = find_object(item);
    }
  }
  else iob = item;
  if(stringp(dest)) {
    dob = find_object(dest);
    if(!dob) {
      dest->load_me();
      dob = find_object(dest);
    }
  }
  else dob=dest;
  if(iob && dob) {
    icr = creator(iob);
    dcr = creator(dob);
#if 0
    if(icr) write("icr: "+icr+"\n"); else write("no icr\n");
    if(dcr) write("dcr: "+dcr+"\n"); else write("no dcr\n");
#endif

    if(icr && master_object()->get_wiz_level(icr) < L_WIZ 
	   && !dob->query_immortal()     /* wiz-wiz immer erlaubt */
	   && !dob->query_testchar()
	   && dcr != icr) {
      if(TP) {
        write("iob = "); write(iob); write("\tdob = "); write(dob); write("\n");
#if 1
        write("Illegal move_object in outer area.\n");
        write("Current object was ");
        write(iob);
        write("\n");
        write("ICR="); write(icr); write("\n");
        write("DCR="); write(dcr); write("\n");
#endif
        log_file("CHECK_LEGAL_MOVE", "item=" + file_name(iob) + "\n");
        log_file("CHECK_LEGAL_MOVE", "icr =" + icr + "\n");
        log_file("CHECK_LEGAL_MOVE", "dest=" + file_name(dob) + "\n");
        log_file("CHECK_LEGAL_MOVE", "dcr =" + dcr + "\n");
        raise_error("Illegal move_object in outer area.\n");
      }
      destruct(iob);
      return 0;
    }
  }
  else
    return 0;
  return 1;
}

nomask mixed move_object(mixed item, mixed dest) {
  if(check_legal_move(item, dest))
    return efun::move_object(item, dest);
}

nomask int transfer(mixed item, mixed dest) {
  if(check_legal_move(item, dest))
    return efun::transfer(item, dest);
  else
    return 5;
}

nomask object *heart_beat_info() {
  int    i, sz;
  object *obj, *res;

  obj = efun::heart_beat_info();
  res = ({});
  sz  = sizeof(obj);
  for(i = 0; i < sz; i++)
    if(obj[i]->INVIS <= TP->LEVEL)
      res += ({obj[i]});

  return res;
}

/*
 * used by listArray() but also a useful sefun in it's own right.
 */

mixed *capArray(mixed *saArr) {
  int i, iSz;

  if(!pointerp(saArr))
    return ({});
  else if(!(iSz = sizeof(saArr)))
    return saArr;
  else {
    for(i = 0; i < iSz; i++) {
      if(stringp(saArr[i]))
        saArr[i] = capitalize(saArr[i]);
    }
  }
  return saArr;
}

/*
 * This function allows you to list the contents of an array of strings in
 * a nice format for printing to someone' screen.
 * Final separator is "and" by default - if iSep != 0, "or" is used.
 * NB. iFlag = 0 -> unordered, uncap list
 *     iFlag = 1 -> ordered, uncap list
 *     iFlag = 2 -> unordered, cap list
 *     iFlag = 3 -> ordered, cap list
 */

varargs string listArray(string *saList, int iSep, int iFlag) {
  string  sRet;
  int     i, iSz;

  iSz = sizeof(saList);
  if(iFlag % 2)
    saList = sort_array(saList, #'>);
  if(iFlag / 2)
    saList = capArray(saList);
  switch(iSz) {
  case 0:
    return "";
    break;
  case 1:
    return saList[0] + ".";
    break;
  case 2:
    return saList[0] + (iSep ? " or " : " and ") + saList[1] + ".";
    break;
  default:
    sRet = "";
    for(i = 0; i < iSz - 2; i++)
      sRet += saList[i] + ", ";
    return sRet + saList[iSz-2] + (iSep ? " or " : " and ") + saList[iSz-1]
                + ".";
    break;
  }
}

mixed *keys(mapping mMap) {
  return m_indices(mMap);
}

mixed *values(mapping mMap) {
  return m_values(mMap);
}

int sizeof(mixed xTmp) {
  if(mappingp(xTmp))
    return m_sizeof(xTmp);
  else
    return efun::sizeof(xTmp);
}

/*
 * This function simply allows you to pass an array of objects to
 * call_other(), and returns the corresponding array of return values.
 */

varargs mixed callOther(mixed mObj, string sFunc, mixed mArg1,
                        mixed mArg2, mixed mArg3, mixed mArg4,
                        mixed mArg5, mixed mArg6) {
  int    iSize,i;
  mixed  maRet;  
  
  if(!mObj || !sFunc || sFunc == "")
    return 0;
  else if(objectp(mObj) || stringp(mObj)) {
    if(mArg6)
      return call_other(mObj, sFunc, mArg1, mArg2, mArg3,
                                     mArg4, mArg5, mArg6);
    else if(mArg5)
      return call_other(mObj, sFunc, mArg1, mArg2, mArg3,
                                     mArg4, mArg5);
    else if(mArg4)
      return call_other(mObj, sFunc, mArg1, mArg2, mArg3,
                                     mArg4);
    else if(mArg3)
      return call_other(mObj, sFunc, mArg1, mArg2, mArg3);
    else if(mArg2)
      return call_other(mObj, sFunc, mArg1, mArg2);
    else
      return call_other(mObj, sFunc, mArg1);
  }
  else if(!pointerp(mObj))
    return 0;    
  else {
    maRet=allocate((iSize=sizeof(mObj)));
    for(i=0;i<iSize;i++) {
      if(!objectp(mObj[i]) && !stringp(mObj[i]))
        continue;
      else if(mArg6)
        maRet[i]=(mixed)call_other(mObj[i], sFunc, mArg1, mArg2, mArg3,
                                                   mArg4, mArg5, mArg6);
      else if(mArg5)
        maRet[i]=(mixed)call_other(mObj[i], sFunc, mArg1, mArg2, mArg3,
                                                   mArg4, mArg5);
      else if(mArg4)
        maRet[i]=(mixed)call_other(mObj[i], sFunc, mArg1, mArg2, mArg3,
                                                   mArg4);
      else if(mArg3)
        maRet[i]=(mixed)call_other(mObj[i], sFunc, mArg1, mArg2, mArg3);
      else if(mArg2)
        maRet[i]=(mixed)call_other(mObj[i], sFunc, mArg1, mArg2);
      else
        maRet[i]=(mixed)call_other(mObj[i], sFunc, mArg1);
    }
    return maRet;
  }
}

/*
 * This function matches a given string against a lsit of players/livings
 * (see use of flag iFlag and extra argument oaArr) and returns the full
 * name if a unique match is found. If not, a msg is printed to
 * this_player() and 0 is returned.
 * Possible values for iFlag:
 *   0: use the users() list for the search.
 *   1: use the lsit of interactives in the environment of this_player().
 *   2: use the lsit of livings in the environment of this_player().
 *   3: use the list passed via the oaArr argument.
 */

varargs string matchName(string sName,int iFlag,object *oaArr) {
  string sTmp,*saTmp;
  int i,iLen,iSz;

  if(!sName || sName == "")
    return 0;
  else
    iLen = strlen(sName)-1;

  sName = lower_case(sName);
  saTmp = ({});

  if(!iFlag)
    oaArr = users();
  else if(iFlag == 1)
    oaArr = filter_array(ALL(ENV(TP)), #'interactive);
  else if(iFlag == 2)
    oaArr = filter_array(ALL(ENV(TP)), #'living);
  else if(iFlag != 3)
    return 0;

  iSz = sizeof(oaArr);
  for(i = 0; i < iSz; i++) {
    sTmp=(string)oaArr[i]->query_real_name();
    if(sTmp[0..iLen] == sName)
      saTmp += ({sTmp});
  }

  if(sizeof(saTmp) == 1)
    return saTmp[0];
  else if(sizeof(saTmp))
    printf("The name \"%s\" is ambiguous (\"%s\"). Please be more \
precise.\n",
           sName, listArray(saTmp,1));
  else
    printf("No-one found to match '%s'.\n", sName);
}

#if 0
void _say(string txt, object ob, object ob2) {
  if(ob)
    return efun::say(txt, ob);
  else
    return efun::say(txt);
}
#endif

#if 0  // HERP: Test only
string format(string str, int width) {
  if (!width)
    width = 78;
  return sprintf("%-=*s", width, str);
}

nomask int exec(object new, object old) {
  write("exec(" + file_name(new) + "," + file_name(old) + ")\n");
  return efun::exec(new, old);
}
#endif
