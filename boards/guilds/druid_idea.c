inherit "/boards/board";

int valid_remove(object who, int no) {
   if(who->query_real_name() == "/guild/master"->query_wiz(2)) return 1; 
   else return ::valid_remove(who, no);  
}

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Druid idea board");
}
