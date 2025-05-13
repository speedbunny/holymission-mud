inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("raccoon");
set_race("animal");
set_short("A raccoon");
set_long(
"A medium-sized brown raccoon washes its hands as it prepares to eat "+
"an apple that it has found somewhere.  Its eyes,which are ringed by its "+
"trademark mask, stare at you warily as it wraps its tail protectively around "+
"its food.\n");
set_level(11);
set_wc(15);
set_ac(9);
set_size(3); 
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
