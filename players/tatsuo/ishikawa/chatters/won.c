/*code by tatsuo for the samurai guild*/
inherit "/obj/monster";

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0] =("Jin San Won says: I am an oriental mystic from long ago.  I once created a\n"+
           "                  a portal of immense power which led to the realms of the\n"+
           "                  powerful, omnipotent, and immortal samurais! It is said that\n"+
           "                  those samurais performing great deeds shall be blessed with\n"+
           "                  the right to enter the Lord of the Immortal Samuria's dwelling\n"+
           "                  It was even rumored that it's exit is on the 5th level of our\n"+
           "                  powerful and great guild. May you be blessed to see it.\n"+
           "                  I was stripped of my magic powers for daring to look upon it\n"+
           "                  May you never suffer my fate!!!!!.\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("Jin San Won");
  set_race("human");
  set_alias("won");
  set_level(100);
   load_chat(2, get_chats());
  set_short("jin san won");
  set_long("Jin San Won is a extremely old man. He's shoulders are bent over\n"+
           "from decades of study. You can see the wisdom of the ages burning\n"+
           "deep within his eyes. He is wearing a dark black velvet robe a symbol\n"+
           "of his position and rank in the oriental wizards. He is said to have\n"+
            "powerful guardians from the nether world to protect him. You can only\n"+
           "hope you may learn from him.\n");

 return 1;
 }
