/*coded by tatsuo for the samurai guild*/
inherit "/obj/monster";
object aba;

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
 set_name("Mamoru Shigeitsu");
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
    aba=clone_object("players/tatsuo/guild/obj/abacus");
     move_object(aba,this_object());
     init_command("wield abacus");
 return 1;
 }
