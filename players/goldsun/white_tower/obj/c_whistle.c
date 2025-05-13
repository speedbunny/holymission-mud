inherit "/obj/treasure";
#define TO this_object()
#define MERLIN "players/goldsun/lank/monster/merlin"
#define SAY(x) tell_room(environment(this_player()),x)

 reset(arg){
  ::reset(arg);
 if (arg) return;
   set_name("crystal whistle");
   set_alias("whistle");
   set_value(100);
   set_short("A crystal whistle");
   set_long("A crystla whistle. Who lost it?\n");
   set_weight(1);
 }

init(){
 ::init();
 add_action("blow","blow");
}


int drop(){
 write("Whistle breaks to small peaces.\n");
 destruct(this_object());
 return 1;
}

int blow(string str){
 notify_fail("Blow what ?\n");
 if (str=="whistle" || str=="crystal whistle"){
   SAY("Whheeeeeeeee !\n");
   if (MERLIN->query_is_busy()){
      write("Merlin tells you: I am busy at this moment, try it later.\n");
      return 1;
   }
   MERLIN->call_me(environment(this_player()));
   return 1;
  }
}

