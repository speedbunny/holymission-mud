/*coded by tatsuo for the samurai guild*/
inherit "/obj/monster";

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0] =("Mr Nyatamoya says: Hello, how are you? Please feel free to buy any\n"+
           "                of our fine selections of teas. They are the finest\n"+
           "                quality known to man. I can guarantee that it will clear\n"+
           "                your head while relaxing you.\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Mr. Nyatamoya");
  set_race("human");
  set_alias("nyatamoya");
  set_level(25);
  set_hp(6000);
  set_gender(1);
   load_chat(2, get_chats());
  set_short("nyatamoya");
set_long("Mr. Nyatamoya is a tall slender man who keeps the tearoom up. He is the\n"+
	 "cousin of Hekayashi the owner of the Sake shop. Nyatamoya is a graceful gentle\n"+
	 "man who is well versed in all forms of herb lore.\n");
 return 1;
 }
