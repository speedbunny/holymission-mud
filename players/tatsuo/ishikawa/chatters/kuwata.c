/*coded by tatsuo for the samurai guild*/
inherit "/obj/monster";

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0] =("Yokiko Kuwata says: I was the geisha for milord the shogun. And i have seen\n"+
          "                    him ascend to the fourth floor of our humble dwelling\n"+
          "                    and he bespeaks the wonders of this floor. I have heard\n"+
          "                    him say that he communicates with the most ancient and\n"+
          "                   wise samurai who have ever walked among the mortals\n"+
          "                   and it is said there are spirits that still love\n"+
          "                   to help us.\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Yokiko Kuwata");
  set_race("human");
  set_alias("kuwata");
  set_level(100);
   load_chat(3, get_chats());
  set_short("yokiko kuwata");
  set_long("Yokiko Kuwata is a very beautiful and stunning woman. You can see\n"+
           "why the shogun fell madly in love with her. She is wearing a light\n"+
           "green silk wrap. She moves with grace and her voice is like a beautiful\n"+
           "song. She has a beatiful smile but to touch her would mean death by the\n"+
           "shogun for daring to touch his geisha.\n");

 return 1;
 }
