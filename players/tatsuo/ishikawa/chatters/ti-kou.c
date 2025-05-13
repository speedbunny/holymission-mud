/*coded by tatsuo for the samurai guild*/
inherit "/obj/monster";
 object mail,staff;
  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0] =("Master Ti-kou says: I am a priest of the almighty and powerful Hachiman\n"+
           "                    god of war! This guild is blessed to have his temple in it.\n"+
           "                    His temple is beautiful and powerful\n"+
           "                    bringing tears to a persons eyes. I am honored among all\n"+
           "                    men to be his most holy priest. However be warned\n"+
           "                    Hachiman has forbidden any violence in his temple\n"+
           "                    A violator will be struck down by Hachiman sending \n"+
           "                    the wretches soul to rot and fester in hell!!!\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Master Ti-kou");
  set_race("human");
  set_alias("ti-kou");
  set_level(100);
   load_chat(2, get_chats());
  set_short("master ti-kou");
  set_long("Master Ti-Kou is the high priest of Hachiman god of war. He is dressed\n"+
           "in resplendent gold and white robes of silk and velvet. You can feel\n"+
           "his power and radiance like the glowing sun.  He has a staff with the\n"+
           "symbol of Hachiman on it. To kill him would bring the wrath of hachiman\n"+
           "on the wicked wretch.\n");

   mail=clone_object("players/tatsuo/ishikawa/obj/mail");
   staff=clone_object("players/tatsuo/ishikawa/obj/staff");
     move_object(mail,this_object());
     move_object(staff,this_object());
       init_command("wear mail");
       init_command("wield staff");
 return 1;
 }
