inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("MUD advertisement board");
   my_env = "room/player/mudads";
}
