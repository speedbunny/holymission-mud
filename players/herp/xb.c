id(str) { return str == "xb"; }
short() { return "Xb"; }
init() { add_action("xb", "xb"); }
xb() {
mixed *gl;
int i;

  gl=allocate(100);
  for (i=0;i<50;i++) gl[i]=query_actions(this_player(),i);
  printf("%O\n",gl);
  write("DONE\n");
  return 1;
}
  
