
id(str) { return str == "xb"; }
short() { return "Xb"; }
init() { add_action("xb", "xb"); }

void func(object user) { printf("%O\n",user); }
xb() {

  map_array(users(),&func);
  write("DONE\n");
  return 1;
}
  
