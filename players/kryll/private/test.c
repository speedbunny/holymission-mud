inherit "/room/room";
 
#define RES1  100
#define RES2  this_player()->query_level() + 80
 
reset(arg) {
 
  if(arg) return;
 
  short_desc = "Test room";
  long_desc = "type <show me>\n";
 
  set_light(1);
 
  ::reset(arg);
 
}
 
init() {
  ::init();
  add_action("show", "show");
}
 
show(str) {
  if(str != "me") return 0;
  if(RES1 > (this_player()->query_immortal() ? RES1 : RES2)) 
    write("You low level geek!\n");
  else
    write("Ok, sir.\n");
  return 1;
}
