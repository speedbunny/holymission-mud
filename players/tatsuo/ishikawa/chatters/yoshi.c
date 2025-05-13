/*coded by tatsuo for the samurai guild*/
inherit "/obj/monster";
object ring;

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0] ="Hikuru Yoshi says: The shogun's treasury is vast and holds much.  I will\n"+
          "                    always trust them with your money! if you are in need of\n"+
          "                    such services you may wish to look up on the second floor\n"+
          "                    However be warned those who try to rob it will be executed!\n";
  }
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Hikuru Yoshi");
  set_race("human");
  set_alias("yoshi");
  set_level(100);
   load_chat(1, get_chats());
  set_short("hikuru yoshi");
  set_long("Hikuru Yoshi is dressed in a rich purple kimodo. He is drapped\n"+
           "with many gold necklaces. He is the owner of some of the largest\n"+
           "businesses on the island of Ishikawa. Beware of robbing this man\n"+
           "however; for it is rumored that he has invisible bodyguards who\n"+
           "will carve any robber into sushi!!!!\n");
        ring=clone_object("players/tatsuo/ishikawa/obj/lring");
        move_object(ring,this_object());
        init_command("wear ring");

 return 1;
 }
