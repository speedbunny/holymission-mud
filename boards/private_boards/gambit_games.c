inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("The Video Games Discussion board");
   my_env = "players/gambit/rooms/path";
}
