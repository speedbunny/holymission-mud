inherit "/obj/monster";
object kat;

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0] =("Akito Usaki says: Hail great warrior and archer! Welcome to the greatest\n"+
           "                  bowyer in the world. I have the greatest and best\n"+
           "                  equipment in all the land. Please take your time and\n"+
           "                  select the bow most suited to your taste. However\n"+
           "                  remember only those most devoted to Raiden the holy\n"+
           "                  and powerful god of bowyer will be successful with my\n"+
           "                  weapons of power.\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Akito Usaki");
  set_race("human");
  set_alias("usaki");
  set_level(100);
  set_gender(1);
   load_chat(2, get_chats());
  set_name("akito usaki");
set_long("Akito Usaki is proud and arrogant as he well should be. He wears the robes\n"+
         "of the high priest of Raiden god of bowyer. He is in excellent physical shape\n"+
         "and his deeds as a samurai are spoken of in legends. He sells the weapons\n"+
         "whose power rival even the most deadly of weapons but require skill granted\n"+
         "only by Raiden himself.\n");
	kat =clone_object("players/tatsuo/ishikawa/obj/katana");
	move_object(kat,this_object());
	init_command("wield katana");
 return 1;
 }
