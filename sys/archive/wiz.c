inherit "/sys/newwiz";

#define DEF_START       "/room/church"
#define WIZ             "/sys/bin/wiz/"

int sponsor;

static int set_start_pos(string arg) {
   if(!arg) {
     if(!start_where) write("You start at '"+DEF_START+"'.\n");
     else write("Your actual start position is "+start_where+".\n");
     return 1;
   }
   if(arg=="none") start_where=0;
   else if(arg=="here" && environment())
     start_where="/"+file_name(environment());
   else start_where=arg;
   if(!start_where) write("You start at '"+DEF_START+"'.\n");
   else write("You now start at '"+start_where+"'.\n");
   return 1;
}

int _filter(string str) {

  string theverb;

  theverb=(string)query_verb();

  if(theverb[0..0]=="'" || member(theverb,'.')!=-1)
    return 0;

  if(file_size(WIZ+theverb+".c")>0)
    if((WIZ+theverb)->main(str))
      return 1;

  return ::_filter(str);
}

static void wiz_commands() {
    add_action("set_start_pos","startposition");
    add_action("_filter","",1);
}

void logon(string n, int quiet) {
  ::logon(n,quiet);
  wiz_commands();
}
