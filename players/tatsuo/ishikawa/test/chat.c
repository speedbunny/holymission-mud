/*coded by tatsuo for the samurai guild*/
#define TP this_player()->query_name()
inherit "/obj/monster";

  string chats;
 get_chats() {
     if(!chats) {
    chats = allocate(5);
chats[0] =("Mamoru Shigeitsu says: Oh hello the sir. I'm sorry i did not see you\n"+
           "                       there. Welcome to the great bank of the honorable\n"+
           "                       samurai. We are here to serve you whenever and\n"+
           "                       however you may need us.  If you need any help\n"+
           "                       opening an account just read the sign above the\n"+
           "                       abacus for more information.\n");
chats[1] =("CLICK!!!\n");
chats[2] =("CLICk,CLACK!!");
chats[3] =("You see a man working furiously at and abacus");
chats[4] =("You see a man working furiously at and abacus");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_race("human");
 set_alias("shigeitsu");
   set_level(20);
  set_hp(3000);
  set_gender(1);
   load_chat(10, get_chats());
   set_short("shigeitsu");
set_long("Mamoru Shigeitsu is the banker for the samurai treasury. He is an older\n"+
        "man who looks comfortable behind the counter. He is deep in concentration\n"+
        "pouring over ledgers and you are amazed at the speed with which he adds numbers.\n");
 return 1;
}

init()
  {
  add_action("_give", "give");
  return 1;
  }
_give(arg){
string what;

  if(sscanf(arg, "%s to moto", what)==1){
  if(!present(what, this_player())){
      write("Fool! You do not have that!\n");
      say(TP+" looks a little foolish.\n");
      return 1;
    }
   else if(what=="crown"){
     if(present("serpent_id", this_player())){
       write("Thank you for completing the quest.\n");
       say(TP+" finished the quest.\n");
       this_player()->set_quest("serpent");
       return 1;
     }
     write("You dishonorable scum! You didn't kill the serpent.\n");
     say("Moto kicks "+TP+" and turns away in disgust.\n");
     return 1;
   }
}
}
