inherit "/obj/monster";

void reset(int arg) {


    ::reset(arg);

   if (arg) return;
    set_name("prisoner");
    set_race("human");
    set_short("A prisoner");
    set_long("An unknown prisoner.\n");
    set_level(5);
    set_al(90);
    set_gender(1);
    set_aggressive(0);
    set_wc(10);
    set_ac(5);
}



init(){
 ::init();
add_action("rescue","rescue");
}

int rescue(string str){
 notify_fail("Rescue whom?\n");
 if (str=="prisoner" ){
  write("Prisoner tells you: Thank you. Here is my reward.\n");
  write("Prisoner gives you 200 coins.\n");
  this_player()->add_money(200);
  say(this_player()->query_name()+" rescues a prisoner.\n");
  write("Prisoner says: Bye.\n");
  say("Prisoner says: Bye.\n");
  destruct(this_object());
  return 1;
 }
}

run_away(){
 write("He is imprisoned here.\nHe cannot escape.\n");
 return 1;
}
