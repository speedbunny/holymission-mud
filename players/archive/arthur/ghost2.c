inherit "/obj/monster";
string chats;
reset(arg){
 ::reset();
set_short("This is the ghost of a beautiful dark-haired woman");
set_name("Queen Ravenovia");
set_alias("queen");
set_alias("ravenovia");
set_long("She is angry yet full of despair as she regards you with malice.\n");
set_level(30);
set_ep(1500);
set_wc(25);
  set_ac(6);
set_spell_mess2("The ghost stares deep into your eyes, and you feel your body\n"
 	       "weaken.\n");
set_chance(30);
load_chat(30, get_chats());
set_spell_dam(50);
   set_aggressive(0);
   return;
 }
get_chats(){
    if(!chats){
    chats=allocate(2);
chats[0]=("Ravenovia laments: We know! We know!\n");

chats[1]=("Why do you defile our resting place with your presence?\n");
    return chats;
}
}
