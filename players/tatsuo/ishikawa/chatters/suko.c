inherit "/obj/monster";
   object doll;

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0] =("Okito Suko says: My grandfather told me about the mystical samurai fountain\n"+
          "                  He said that if used properly it would show you a man's\n"+
          "                  place in the world and let you reach into his soul and\n"+
          "                  see the world through his eyes.\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Okito Suko");
  set_race("human");
  set_alias("suko");
  set_level(100);
  set_gender(2);
   load_chat(2, get_chats());
  set_name("okito suko");
set_long("Okito Suko is a young girl whose eyes shine with the beauty and life of the\n"+
         "young. She is dressed in a cute apple-green silk dress. She is simply\n"+
         "adorable and to harm her would certainly anger the gods and dishonor\n"+
         "any beast that would be so low.\n");
         doll =clone_object("players/tatsuo/ishikawa/obj/doll");
    	 move_object(doll,this_object());
 return 1;
 }
