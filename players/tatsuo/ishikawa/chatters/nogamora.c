/*coded by tatsuo for the samurai guild*/
inherit "/obj/monster";

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0] =("Venerable Nogamora says: This guild was designed and coded by Exos\n"+
           "                         the Undead Slayer who has put many hours into it\n"+
           "                         Also special thanks to Tatsuo for his help in coding\n"+
           "                         and room design. And to Haplo for his time and help\n"+
           "                         with coding. Each of these wizards have put in their\n"+
           "                         time and effort to make the samurai's the most kick\n"+
           "                         ass guild ever coded!!!! *thanks alot guys*\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Venerable Nogamora");
  set_race("human");
  set_alias("nogamora");
  set_level(100);
   load_chat(2, get_chats());
  set_short("venerable nogamora");
set_long("You see a wizened old man sitting in the lotus positon on fine velvet\n"+
         "pillows. He has his eyes closed and is quietly murmuring an ancient chant\n"+
         "so ancient you do not understand the words. Knowledge and wisdom hang\n"+
         "about this man like fine silk robes. You can feel your intellegence increasing\n"+
         "just by being near him. Listen to what he says. There are none wiser.\n");

 return 1;
 }
