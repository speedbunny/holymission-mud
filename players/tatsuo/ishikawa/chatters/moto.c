/*coded by tatsuo for the samurai guild*/
#define TP this_player()->query_name()
#define TO this_object()
inherit "/obj/monster";

 object cro, crown;
  string chats;
 get_chats() {
     if(!chats) {
    chats = allocate(5);
chats[0] =("Moto says: My poor people how can we bear such sorrow!!!\n");
chats[1] =("Moto says: The evil Serpent King Kyoshi has stolen our crown of power.\n");
chats[2] =("Moto says: We are in need of a brave and honorable hero to help us.\n");
chats[3] =("Moto says: Kyoshi is rumored to live inside the mountain of ishikawa.\n");
chats[4] =("Moto says: Please kill Kyoshi for us and help my people.\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_race("human");
  set_name("Shyoto Moto");
   set_alias("moto");
  set_level(25);
   set_hp(5000);
  set_gender(1);
   load_chat(10, get_chats());
  set_short("moto");
set_long("Shyoto Moto is the village elder. He has a friendly smile and \n"+
         "is dressed in a simple robe. You can sense a great power surrounding\n"+
         "him and you realize he is hardly a simply fisherman. He cares deeply\n"+
         "for his people and their welfare.\n");
 return 1;
}

init()
  {
  add_action("_give","give");
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
    cro=present("crown", this_player());
     destruct(cro);
       return 1;
     }
     write("You dishonorable scum! You didn't kill the serpent.\n");
     say("Moto kicks "+TP+" and turns away in disgust.\n");
     return 1;
   }
}
}
