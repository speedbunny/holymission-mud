inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Flame board");
   my_env = "room/player/flame";
}
