inherit "/obj/thing";
#include "/players/mangla/defs.h"
#define JAN     820450800     // january 1 00:00:00 1996
 
string dir_path;

int _file_date(string arg) {
  string filename, tmp;
  int    i, sz;
  mixed  *ret_vals;
 
  if(!arg) {
    notify_fail("An argument would be helpful.\n");
    return 0;
  }

  if(arg == "here")
    arg = ".";

  if(arg[0] != '/') {
    arg = "/" + TP->query_path() + "/" + arg;
  }

  if(file_size(arg) != -2) {
    write("That is not a valid directory.\n");
  }
  else {
    ret_vals = get_dir(arg, 7);
    sz = sizeof(ret_vals);
    tmp = "\n";
    for(i=0; i<sz-1; i+=3) {
      if(ret_vals[i+2] < JAN) {
        tmp += (sprintf("%-13s", ret_vals[i]));
        tmp += (" = " + ctime(ret_vals[i+2]) + "\n");
      }
    }
    TP->more_string(tmp);
  }
  return 1;
}
 
int _file_date2(string arg) {
  string filename, tmp;
  int    i, sz;
  mixed  *ret_vals;
 
  if(!arg) {
    notify_fail("An argument would be helpful.\n");
    return 0;
  }
 
  if(arg == "here")
    arg = ".";
 
  if(arg[0] != '/') {
    arg = "/" + TP->query_path() + "/" + arg;
  }
 
  if(file_size(arg) != -2) {
    write("That is not a valid directory.\n");
  }
  else {
    ret_vals = get_dir(arg, 7);
    sz = sizeof(ret_vals);
    tmp = "\n";
    for(i=0; i<sz-1; i+=3) {
      tmp += (sprintf("%-13s", ret_vals[i]));
      tmp += (" = " + ctime(ret_vals[i+2]) + "\n");
    }
    TP->more_string(tmp);
  }
  return 1;
}

void checker(string str) {
  string filename, *tmp;
  int    i, sz;
  mixed *ret_vals;

  if(str != "YES") {
    write("Thought twice about it, eh?\n");
    return;
  }
  tmp = explode(dir_path,"/");
  dir_path = "/";
  for(i=0, sz=sizeof(tmp); i<sz; i++) {
    if(tmp[i]=="" || tmp[i]==".")
      continue;
    dir_path += tmp[i] + "/";
  }
  ret_vals = get_dir(dir_path+".", 7);
  sz = sizeof(ret_vals);

  for(i=0; i<sz-1; i+=3) {
    if(ret_vals[i+2] < JAN) {
      if(rm(dir_path+ret_vals[i])) {
        write("Removed file : "+ret_vals[i]+"\n");
      }
    }
  }
  return;
}

int _remove_file(string arg) {
  if(!arg) {
    notify_fail("An argument would be helpful.\n");
    return 0;
  }
  if(file_size(arg) != -2) {
    notify_fail(arg + " is not a directory.\n");
    return 0;
  }
  dir_path = arg;
  input_to("checker");
  write("ARE YOU SURE? (type: YES if you are) ");
  return 1;
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;

  set_name("calendar");
  set_alt_name("dater");
  set_short("Calendar");
  set_long("mydate dir - where dir is the full path of the directory\n"+
           "or here, and returns all files older than Jan 1 1996\n"+
           "remfile <path> - full path is required\n"+
           "EX: mydate here\n"+
           "    mydate /doc/. \n");
  set_weight(0);
}

init() {
  ::init();
  if(!TP->query_archwiz()) {
    destruct(this_object());
    return;
  }
  else {
    add_action("_file_date", "mydate");
    add_action("_file_date2", "alldate");
    add_action("_remove_file","remfiles");
  }
}

