inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("For Those Who Dare to Enter");
   my_env = "players/turbo/rooms/r1";
}
