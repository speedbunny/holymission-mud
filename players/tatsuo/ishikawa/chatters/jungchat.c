/* coded by tatsuo for Ishikawa */
inherit "/obj/monster";

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(5);
chats[0] =("Something behind you screams.\n");
chats[1]=("Something scurries through the undergrowth.\n");
chats[2] =("Something growls at you!\n");
chats[3] =("You hear bird chirps echo all through the jungle.\n");
chats[4] =("You feel as if something is watching you!\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
 set_race("chatter");
  set_level(1);
  set_alt_name("something");
  set_hp(1);
  set_gender(1);
   load_chat(12, get_chats());
 return 1;
 }
