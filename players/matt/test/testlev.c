int id(string str) { return str == "testlev"; }
string short() { return "Testlev"; }
void long() { write("Testlev.\n"); }
int get() { return 1; }
void init() { add_action("testlev", "testlev"); }
int testlev(string arg) {
  if(!arg) return 0;
  write("Level is " + master_object()->get_wiz_level(arg) + ".\n");
  return 1;
}
