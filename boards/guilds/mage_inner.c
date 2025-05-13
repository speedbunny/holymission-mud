inherit "/boards/board";

int valid_remove(object who, int no) {
   if(who->query_real_name() == "/guild/master"->query_wiz(5)) return 1; 
   else return ::valid_remove(who, no);  
}

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("The noteboard of the inner circle");
   my_env = "players/saffrin/guild/rooms/inner";
}
