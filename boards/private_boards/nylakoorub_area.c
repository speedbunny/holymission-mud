inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Nylakoorub's area board");
   my_env = "players/nylakoorub/area/rooms/clearing/c020";
}
