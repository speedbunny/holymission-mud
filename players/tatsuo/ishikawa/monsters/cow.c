/*coded by gandalf*/
inherit "/obj/monster";

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
 chats[0] =("Cow goes MOOOOO!!!\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Cow");
  set_race("mammal");
  set_alias("cow");
  set_level(20);
   load_chat(10, get_chats());
  set_name("cow");
  set_long("It is a dirty old cow. It is starting to EAT your WEAPON.\n");
 return 1;
 }
