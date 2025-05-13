inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("raccoon");
set_race("animal");
set_short("A raccoon");
set_long("A medium brown raccoon with long tail.\n");
set_level(11);
set_wc(15);
set_ac(9);
set_size(3); 
move_object(clone_object("players/goldsun/7-islands/emerald/obj/tail"),
   this_object());
}

init(){
 ::init();
add_action("dig","dig");
}

int dig(string str){
 notify_fail("Dig where?\n");
 if (str=="down"){
  write("A raccoon hinders you to do it.\n");
  return 1;
 }
}
