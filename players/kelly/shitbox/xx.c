inherit "obj/thing";

reset() {
  ::reset();
  set_name("tester");
  set_short("A tester");
}
init() {
  ::init();
  add_action("test","test");
}

test(str) {
  if(present(str,this_player()))
    write("Jo.\n");
  else
    write("Na.\n");
 return 1;
} 
