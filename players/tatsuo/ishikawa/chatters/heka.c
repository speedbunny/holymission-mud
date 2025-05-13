/*coded by tatsuo for the samurai guild*/
inherit "/obj/monster";

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(3);
chats[0] =("Aragoya Hekayashi says: Welcome travellers to our most humble sake shop.\n");
chats[1]=("Aragoya Hekayashi says:Sit down and relax, heal, and gather your strength.\n");
chats[2] =("Aragoya Hekayashi says: You can buy many wines to aid in your healing.\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Aragoya Hekayashi");
  set_race("human");
  set_alias("hekayashi");
  set_level(25);
  set_hp(6000);
  set_gender(1);
   load_chat(12, get_chats());
  set_short("aragoya hekayashi");
set_long("Aragoya Hekayashi is a short, overweight, shopkeeper. He has a rag in the\n"+
         "hand which he uses to keep the bar counter clean. He has owned this shop\n"+ 
         "for many years, selling healing drinks to battle weary samurai. He has\n"+
         "a bright cheery smile and infectious laugh that spreads a warm glow over\n"+
         "all those who meet him.\n");
 return 1;
 }
