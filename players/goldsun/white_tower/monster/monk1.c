inherit "/obj/monster";
#define TO this_object()
#define env(x) environment(x)

void reset(int arg) {


    ::reset(arg);

   if (arg) return;
    set_name("guard");
    set_alias("monk");
    set_race("human");
    set_short("Monk the guard");
    set_long("Monk the guard. He is prisoned here.\nHe wait for man"+
     	     " who rescue him.\n");
    set_level(5);
    set_hp(600);
    set_al(200);
    enable_commands();
    set_gender(1);
    set_aggressive(0);
    set_wc(16);
    set_ac(5);
}



init(){
 ::init();
add_action("rescue","rescue");
}

int rescue(string str){
 notify_fail("Rescue whom?\n");
 if (str=="guard" || str=="monk"){
  write("Monk tells you: Thank you. I am guard of White Tower. I guard White\n"+
       "Tower with 2 guards. Once upon a time a lot of ugly Cyclops attacked\n"+
       "White Tower and stole altar from it. They captured my friends. I\n"+
       "escaped to the forest but Nottingham soldiers imprisoned me.\n");
  write("Monk tells you: I go to find my master. If you decide to save our\n"+
        "altar he will help you.\n");
  write("Monk tells you: Here is my reward.\nMonk drops a ring.\n");
  move_object(clone_object("players/goldsun/white_tower/obj/ring1"),env(TO));
  say(this_player()->query_name()+" rescues monk.\n");
  say("Monk drops a ring.\n");
  write("Monk leaves.\n");
  say("Monk leaves.\n");
  destruct(this_object());
  return 1;
 }
}


run_away(){
 write("He is prison here.\nHe cannot escape.\n");
 return 1;
}
