inherit "/obj/monster";
   object hook;

  string chats;
 get_chats() {
     if(!chats) {
     chats = allocate(1);
chats[0]=("Crazy Guy says: HA It's MinE! MY kRyll! Go Away!\n");
}
  return chats;

}
 reset(arg){
  ::reset(arg);
  if(arg) return 1;
  set_name("crazy guy");
  set_race("human");
  set_alias("man");
  set_level(11);
   set_alt_name("guy");
   set_gender(1);
   load_chat(2, get_chats());
set_long("An old Crazy Guy, who has lived here for years!\n");
         hook=clone_object("/players/tatsuo/ishikawa/obj/hook");
	move_object(hook, this_object());
init_command("wield hook");
 return 1;
 }
