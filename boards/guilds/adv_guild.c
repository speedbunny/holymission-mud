inherit "/boards/board";

void reset(int tick) {
   ::reset(tick); 
   if(tick) return;

   set_name("Bulletin board"); 
   my_env = "room/adv_guild";   
}
