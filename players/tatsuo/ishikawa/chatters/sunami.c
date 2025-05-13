/*coded by tatsuo for the samurai guild*/
inherit "/obj/monster";
object kat;

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0] =("Higuchi Sunami says: We have many weapons Master. Only the best for the\n"+
            "                     honorable and mighty samurai. Please take your time.\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Higuchi Sunami");
  set_race("human");
  set_alias("sunami");
  set_level(100);
   load_chat(5, get_chats());
  set_short("higuchi sunami");
set_long("You see a strong powerful samurai who is the major weapons dealer in\n"+
         "the guild. You can see he is as good with the weapons as he is selling\n"+
         "them. He carries a mighty Katana.\n");
	kat =clone_object("players/tatsuo/ishikawa/obj/katana");
	move_object(kat,this_object());
	init_command("wield katana");
 return 1;
 }
