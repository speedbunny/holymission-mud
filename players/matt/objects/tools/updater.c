inherit "/obj/thing";

#include "/players/matt/defs.h"

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_name("updater");
  set_short("Directory update tool");
  set_long("This tool will update the contents of a directory.\n" +
	   "\"upall\" will update the contents of the current directory,\n" +
	   "and can take as an optional argument a directory name.\n" +
	   "Enjoy!        - Matt\n");
}

void init() {
  ::init();
  if(!TP->query_immortal()) destruct(TO);
  add_action("upall", "upall");
}

int upall(string arg) {
  int i;
  int contsize;
  string dir;
  string *cont;
  string file;
  object obj;

  if(!arg) dir = "/" + TP->query_path() + "/";
  else dir = arg + "/";

  cont = get_dir(dir + ".");
  if(!cont || !(contsize = sizeof(cont))) {
    write("Invalid or empty directory \"" + dir + "\".\n");
    return 1;
  }
  for(i = 0; i < contsize; i++) {
    file = dir + cont[i];
    write(file + ": ");
    if(obj = find_object(file)) {
      destruct(obj);
      write("Updated.\n");
    }
    else write("Not found.\n");
  }
  write("Done.\n");
  return 1;
}
