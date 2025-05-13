/*
    secure/valid.c - validating functions
    To be inherited nomask by the player object.
*/

#include <ctype.h>
#include <levels.h>
#define TP this_player()
#define TO this_object()
#define TI this_interactive()
#define PO previous_object()
#define MASTER master_object()
#define RNAME query_real_name()

#undef NEWLEVELSYSTEM

int     query_level();
int     query_immortal();
int     query_newwiz();
int     query_wizard();
int     query_lord();
int     query_archwiz();
string  query_real_name();
string  current_path;	/* Current directory */
string  query_path () { return current_path; }
// string *query_domains() { return domains ? domains[0..sizeof(domains)] : ({}); }

/* HERP 930509 xperms: a array containing a path-list (i.e. ({ "room","obj"}) */
string  *xperms;

/*
 * Check that a player name is valid. Only allow
 * lowercase letters.
 */
int valid_name(string str) {

  int i, length;

  if (!str || str=="" || str == "logon") {
    write("Invalid name");
    return 0;
  }
  length = strlen(str);
  if (length > 11) {
    write("Too long name.\n");
    return 0;
  }
  for (i = 0; i < length; i++) {
    if (str[i] < 'a' || str[i] > 'z') {
      write("Invalid characters in name:" + str + "\n");
      write("Character number was " + (i+1) + ".\n");
      return 0;
    }
  }
  return 1;
}

string *normalize_path(mixed path, int file) {

  int i, j;

  if(stringp(path))
    path = explode (path, "/");
  if(!pointerp (path))
    return ({});
  for(i = j = 0; i < sizeof (path); i++) {
    if(path[i] == "") continue;
    if(path[i] == "..") {
      if(j) j--;
      continue;
    }
    if(path[i] == "." && (!file || i != sizeof (path) - 1))
      continue;
    if(j != i)
      path[j++] = path[i];
    else
      j++;
  }
  return path[0..j-1];
}

string valid_write(string str) {

  string uid, *path;
  string lpath;			/*HERP: leading path */
  string pnam;
  int i;

  /*
  Determine uid for write permission. Please use the same definition
  as the gamedriver uses for save_object. There is a difference
  concerning domains currently, which will we fixed in the gamedriver
  soon.
  */
  if(PO && PO != TO) {
    uid = explode(file_name(PO), "/")[0];
    if(uid == "obj" || uid == "room"
                    || uid == "std"
                    || uid == "secure"
                    || uid == "sys"
                    || uid == "tools" )
      uid = 0;		/* 245 backbone */
    else if(uid == "log" || uid == "open" || uid == "ftp")
      return 0;		/* distrust open directories */
    else if( uid == "boards" )
      uid = "boards";      // senseless, but more understandable !?
    else if(!(uid = creator(PO)))
      return 0;		/* no good - not manually cloned */
  } else uid = RNAME;

  if(uid && !isalpha(uid[0]))
    return 0;

  if(str[0] != '/') {
    if(PO && PO != TO && uid) {
      return("players/" + uid);
#if 0
      return(islower(uid[0]) ?
             "players/" + uid :              /* wizard */
		         "domains/" + lower_case(uid)) + /* domain */
             "/" + implode(normalize_path(str, 1), "/");
#endif
    }
    else {
      path = normalize_path(current_path, 1) + normalize_path(str, 1);
    }
  }
  else
    path = normalize_path(str, 1);

  if(!path || !sizeof(path))
    return 0;

  /*HERP 93-05-09 check extended permissions (xperms) */
  if(xperms && sizeof(path) > 1) {
    lpath = implode(path[0..sizeof(path)-2],"/");
    if(member_array(lpath, xperms) >= 0)  /* found in permlist */
      return implode(path, "/");
  }

  switch(path[0]) {
  case "log":
    if(sizeof(path) != 2
          || lower_case(extract(path[1], 1)) != extract(path[1], 1))
      break;
  case "open":	/* sorry for that, it's for efficiency */
  case "ftp":
    return implode(path,"/");
  case "boards":
    if(uid == "boards")
      return(implode(path,"/"));
    break;
  case "players":
    pnam = path[1];
    i = strlen(pnam) - 1;
    if(pnam[i-1..i] == ".o")
      pnam = pnam[0..i-2];

    /* Herp: Lords may access /player-directories */

    if(MASTER->get_wiz_level(RNAME) == L_ELDER
          && MASTER->get_wiz_level(pnam) < L_ELDER)
      return implode(path, "/");
    if(sizeof(path) < 3 || (  path[1] != (uid ? uid : RNAME)
                        && !(MASTER->valid_access(RNAME, pnam)) ))
      break;
    return implode(path,"/");
/*
  case "domains":
    if (sizeof (path) < 3) break;
    if (uid && uid != RNAME) {
      if (!isupper (uid[0]) || lower_case (uid) != path[1])
        break;
    }
    return implode(path,"/");
*/
  }

  /*
   * After checking all the standard cases we'll now check
   * whether we are privileged or not. We have to ensure that
   * nobody is forcing a change of this_player() by means of init()
   * or command().
   */ 
  if(!TP->query_archwiz()       /* arch level */
     || (uid && uid != RNAME)   /* only owned tools work (!) */
     || TP != TO)               /* no init() cheats */
    return 0;
  return implode(path,"/");
}

int chk_for_lock(string *path);

string valid_read(string str) {

  string *s;
  string nof;

  if(str[0] != '/')
    str = "/" + current_path + "/" + str;
  s = normalize_path(str,1);
  if(sizeof(s) && s[sizeof(s)-1] == ".SECURE") 
    return implode (s,"/");
  if(TI && TI->query_archwiz())
    return implode (s,"/");
  if(TI) {
    nof = TI->query_testchar();
    if(nof != "" && MASTER->get_wiz_level(nof) >= L_ARCH)
      return implode (s,"/");
  }
  if(sizeof(s) && (s[0] == "secure"
                || s[0] == "sys"
//                || s[0] == "spells"
//                || s[0] == "masters"
//                || s[0] == "abilities"
                || s[0] == "p")) {
    return 0;
  }
  if(sizeof(s) && s[0] == "boards"
               && !(PO && explode(file_name(PO), "/")[0] == "boards")) {
    return( 0 );
  }

  if(chk_for_lock(s)) return 0;
    return implode (s,"/");
}

/* 030793 Llort use a '.SECURE' file to protect this and all following dirs */
// 070993 Moonchild change so that .SECUREd directories can only be read by
//	  wizards of level >= level of owner. (and of course only if senior+
//	  also).
static int chk_for_lock(string *path) {

  string tmp;
  int i, g;

  if(TP) {
    if(sizeof(path) > 1 && path[0] == "players") {
      if((string)TP->RNAME == path[1])
        return 0;
      if(((int)TP->query_sage())
#ifdef NEWLEVELSYSTEM
          && ((int)TP->query_wiz_level() > (int)MASTER->get_wiz_level(path[1])))
#else
          && ((int)TP->query_level() > (int)MASTER->get_wiz_level(path[1])))
#endif
        return 0;
      if(MASTER->valid_access(TP->RNAME, path[1]))
        return 0;
    }
  }
  for(i = 0, tmp = "", g = sizeof(path); i < g; i++) {
    tmp += "/" + path[i];
    if(file_size(tmp + "/.SECURE") >= 0)
      return 1;
  }
  return 0;
}
