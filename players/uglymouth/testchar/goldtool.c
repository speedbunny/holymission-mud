int light_level;
object mark;

int id(string str) {
  return str == "goldtool";
}

string short() { return "A gold pin"; }

void long() {
  write ("A beautifully crafted gold pin.\n"
    + "It belongs to Goldwolf.\n");
}

int get() { return 1; }

int drop() {
  write("A gold pin vanishes into thin air.\n");
  destruct(this_object());
  return 0;
}

void init() {
  if(this_player()->query_real_name() != "goldwolf") return;
  add_action("do_set_light_level", "pinlight");
  add_action("do_mark_and_more", "read");
}

int do_set_light_level(string str) {
  int llevel;
  if(!str) {
    write("Light level is now " + light_level + ".\n");
    return 1;
  }
  sscanf(str, "%d", llevel);
  set_light(llevel);
  light_level += llevel;
  write("Light level is now " + light_level + ".\n");
  return 1;
}

int do_mark_and_more(string str) {
  string roomfile;
  if(str != "code") return 0;
  mark = environment(this_player());
  roomfile = explode(file_name(mark), "#")[0];
  this_player()->more("/" + roomfile + ".c");
  write("Ok.\n");
  return 1;
}

