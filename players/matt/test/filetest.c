inherit "/obj/thing";

#include "/players/matt/defs.h"

void reset(int arg);
void init();
string resolve_path(string arg);

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("file thing");
  set_short("File Thing");
  set_long("A file thing. Use normal file commands prepended by 'f'.\n");
  set_alias("thing");
}

void init() {
  ::init();
  add_action("resfn", "resfn");
}

int resfn(string arg) {
  if(!arg) return 0;
  else {
    write("File:     \"" + arg + "\"\n");
    write("Resolved: " + resolve_path(arg) + "\n");
    return 1;
  }
}

string resolve_path(string fn) {
  int fnlen;
  int clistlen;
  int fnlistlen;
  int i;
  string cur;
  string *clist;
  string *fnlist;
  string path;

  if(sizeof(explode(fn, " ")) > 1) return "";
  else if(sizeof(explode(fn, "//")) > 1) return "";
  else if(sizeof(explode(fn, "...")) > 1) return "";
  else switch(fn[0]) {
  case '~':
    fnlen = strlen(fn);
    if(fnlen > 1) {
      if(fn[1] == '/') path =  "players/" + TP->RNAME + fn[1..(fnlen - 1)];
      else path = "players/" + fn[1..(fnlen - 1)];
    }
    else path = "players/" + TP->RNAME;
    break;
  case '.':
    fnlen = strlen(fn);
    if(fnlen > 1) {
      if(fn[1] == '/') path = TP->query_path() + fn[1..(fnlen - 1)];
      else path = TP->query_path() + "/" + fn;
    }
    else path = TP->query_path();
    break;
  case '/':
    fnlen = strlen(fn);
    path = fn[1..(fnlen - 1)];
    break;
  default:
    path = TP->query_path() + "/" + fn;
  }

  clist = explode(TP->query_path(), "/");
  fnlist = explode(path, "/");
  fnlistlen = sizeof(fnlist);
  clistlen = sizeof(clist);

  for(i = 0; i < fnlistlen; i++) {
    if(fnlist[i] == "..") {
      if(clistlen) {
	clist = del_array(clist, (clistlen - 1));
	clistlen--;
      }
    }
    else {
      clistlen++;
    }
  }


  return path;
}
  
