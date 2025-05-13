/*coded by tatsuo for the samurai guild*/
inherit "/obj/monster";
object wak;

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0] =("Kiko Sunami says: Welcome O great samurai! Allow me to show you the\n"+
           "                  wide selections of armour that we sell. There is none\n"+
           "                  better than ours. \n"+
           "                  Please take your time in shopping our humble store.\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Kiko Sunami");
  set_race("human");
  set_alias("sunami");
  set_level(100);
   load_chat(2, get_chats());
  set_short("kiko sunami");
set_long("Kiko Sunami is the sister of Higuchi Sunami the weaponer. She is dressed\n"+
         "in a white silk kimodo sitting behind a desk waiting to serve those samurais\n"+
         "in need of her services. You can see that she is very beautiful, but do not\n"+
         "be deceived she is as skilled a fighter as her brother.\n");
	wak =clone_object("players/tatsuo/ishikawa/obj/wakizashi");
	move_object(wak,this_object());
	init_command("wield wakizashi");
 return 1;
 }
