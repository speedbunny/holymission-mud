#include "../std/list_nicely.h"

#define TESTME if(!interactive(this_player()) ||\
	(string)this_player()->query_real_name()!="moonchild")\
	destruct(this_object())

#define TRACECMDS ({ "Dump", "Destruct", "Call", "Tell", "Trans", "Set",\
			"Goto", "In", "Clean" })
#define BASIC_DYNION ({ "don", "doff", "dwho", "net", "objects", "show",\
			"where", "scan", "i_dump", "i_mark", "i_clone",\
			"i_swap", "i_destruct", "i_call", "i_more",\
			"i_move", "i_show", "i_clear", "i_who", "i_stat" })
#define OTHER_DYNION ([ "clear":"clear_room","noshout":"shout_curse" ])
#define SAME_DYNION ({ "ih", "ir", "il", "idl", "ii", "ime" })
#define DYNION_ALIASES ([ "im":"i_mark","isw":"i_swap","id":"i_destruct",\
			"ic":"i_call","imo":"i_move","ish":"i_show",\
			"icl":"i_clear","is":"i_stat" ])

#define TRACE "obj/trace"
#define DYNION "tools/tool"
#define LCOUT "players/herp/lcout"
#define HBINFO "players/james/hbinfo"
#define PARSE "/players/moonchild/wiz/parse_tmp"

void ADD(string x, mixed y);

string short()     { return "Male Chastity Belt (worn) (locked)"; }
void long()        { printf("%s.\n", short()); }
int get()          { return 1; }
int drop()         { return 1; }
int id(string str) { return str=="belt" || str=="chastity belt"; }

void init() {
  ADD("tracer_command", TRACECMDS);
  ADD("basic_dynion", BASIC_DYNION);
  ADD("other_dynion", OTHER_DYNION);
  ADD("same_dynion", SAME_DYNION);
  ADD("dynion_aliases", DYNION_ALIASES);
  add_action("lcout", "lcout");
  add_action("hbinfo", "hbinfo");
  add_action("parse_lpc", "parse");
  add_action("parse_lpc", "eval");
  add_action("grep_dir", "grep");
}

void ADD(string y, mixed x) {
  int i;
  if(mappingp(x)) {
    mixed *cmds;
    cmds=m_indices(x);
    for(i=0;i<sizeof(cmds);i++) add_action(y, cmds[i]);
  }
  else for(i=0;i<sizeof(x);i++) add_action(y, x[i]);
}

int tracer_command(string s) {
  TESTME;
  return (int)call_other(TRACE, query_verb(), s);
}

int basic_dynion(string s) {
  TESTME;
  return (int)call_other(DYNION, sprintf("do_%s", query_verb()), s);
}

int other_dynion(string s) {
  TESTME;
  return (int)call_other(DYNION, OTHER_DYNION[query_verb()], s);
}

int same_dynion(string s) {
  TESTME;
  return (int)call_other(DYNION, query_verb(), s);
}

int dynion_aliases(string s) {
  TESTME;
  return (int)call_other(DYNION, sprintf("do_%s",
	 DYNION_ALIASES[query_verb()]), s);
}

int lcout() {
  TESTME;
  return (int)LCOUT->lcout();
}

int hbinfo() {
  TESTME;
  return (int)HBINFO->hbinfo();
}

int parse_lpc(string s) {
  mixed res;
  string err;
  object ob;
  TESTME;
  if(file_size(PARSE)) rm(PARSE);
  if(ob=find_object(PARSE)) destruct(ob);
  write_file(PARSE, query_verb()=="eval" ? sprintf("parse_it() { return %s; }",
	s) : sprintf("parse_it() { %s; }", s));
  if(err=catch(res=PARSE->parse_it()))
    write(err);
  else if(query_verb()=="eval")
    write("Got" + intp(res) ? " int: " : ": " + res + "\n");
  rm(PARSE);
  return 1;
}

int see_who_has(string s) {
  object *poss,*u;
  int i,j;
  TESTME;
  u=users();
  for(i=0;i<sizeof(u);i++) {
    poss=filter_array(all_inventory(u[i]), "get_creator", this_object(), s);
    for(j=0;j<sizeof(poss);j++) {
      string qrn;
      qrn=(string)u[i]->query_real_name();
      printf("%s: %s  %s\n", qrn, poss[j]->short() ? (string)poss[j]->short()
	: "<INVIS>", file_name(poss[j]));
    }
  }
  return 1;
}

int grep_dir(string str) {
  string exp,dir,*tmp,*files;
  int i,j;
  TESTME;
  if(!str) return 0;
  if(sscanf(str, "%s %s", exp, dir)!=2) {
    write("Invalid syntax.\n");
    return 1;
  }
  if(dir==".")
    dir=sprintf("/%s/", (string)this_player()->query_path());
  else if(dir[0..0]!="/")
    dir=sprintf("/%s/%s/",(string)this_player()->query_path(), dir);
  else if(dir[-1..-1]!="/")
    dir=sprintf("%s/", dir);
  files=get_dir(sprintf("%s*", dir));
  if(!(j=sizeof(files))) {
    write("No files.\n");
    return 1;
  }
  for(i=0;i<j;i++) {
    string file;
    if(file!="." && file!="..") {
      file=read_file(sprintf("%s%s", dir, files[i]));
      if(file && strstr(file, exp)!=-1)
	printf("Found %s in: %s%s\n", exp, dir, files[i]);
    }
  }
  return 1;
}
