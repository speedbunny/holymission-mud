inherit "room/room";

reset(arg){
  if(arg) return;
  set_light(1);
  short_desc = "Test room";
  long_desc = "Duh.. its a test room.\n";
}

init(){
::init();
add_action("blah","blah");
add_action("snot","snot");
}

blah(){
  "/sys/chatd"->dump();
  return 1;
}
snot(string what){

log_file("snot_log",
this_player()->query_real_name() + " snotted: " + what + ".\n");
return 1;
}

