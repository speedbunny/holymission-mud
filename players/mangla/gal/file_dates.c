inherit "obj/treasure";

#include "/players/mangla/defs.h"

string query_auto_load() {
  return "/players/mangla/gal/file_dates:";
}

int _file_date(string arg) {

  string filename;
  int    option, time_val;
  string  *ret_vals;

  if(sscanf(arg, "%s %d", filename, option) != 2) {
    notify_fail("That is not valid syntax for this command.\n");
    return 0;
  }

  ret_vals = get_dir(filename, option);
write(ret_vals[2]);
  sscanf(ret_vals[2], "%ld", time_val);
  write(ctime(time_val));
  write("\n");
  return 1;
}

void reset(int arg) {
  set_name("calendar");
  set_long("filedate filename option\n");
  set_short("Calendar");
  set_weight(0);
}
init() {
  ::init();
  add_action("_file_date", "filedate");
}
