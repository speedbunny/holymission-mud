inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Town Hall Board");
   my_env = "players/silas/fghant/ktownhall";
}
