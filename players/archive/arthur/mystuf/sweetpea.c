inherit "/obj/monster";
string chats;
reset(arg){
 ::reset();
set_short("Sweet-Pea the bird");
set_name("Sweet-pea");
set_alias("sweet-pea");
set_alias("bird");
set_long("This is Sweet-pea, one of Tuppences birds.\n");
set_level(1);
load_chat(1, get_chats());
   set_aggressive(0);
   return;
 }
get_chats(){
    if(!chats){
    chats=allocate(2);
chats[0]=("Sweet-pea pecks you.\nOUCH!\n");

chats[1]=("Sweet-pea chirps loudly!\n");
    return chats;
}
}
