/*coded by tatsuo for the samurai guild*/
inherit "/obj/monster";

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0] =("Shingo Tanaka says: Please great warrior sit and relax while i show you\n"+
           "the wonders i have to sell. I have many choices for you to select from\n"+
           "Please let me know what you want and i will get it for you.\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Shingo Tanaka");
  set_race("human");
  set_alias("tanaka");
  set_level(100);
  set_gender(1);
   load_chat(2, get_chats());
  set_short("shingo tanaka");
set_long("Shingo Tanaka is a small weasle like man who runs the general store in the\n"+
         "guild. He is very respectful though not very big or strong. He is wearing\n"+
         "a simple robe made from white cotton with a blue sash. You recognize the\n"+ 
         "sash as being the symbol of retired samurais. Maybe you should rethink your\n"+
         "earlier decision.\n");
 return 1;
 }
