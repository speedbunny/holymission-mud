inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("A floating board");
   my_env = "players/llort/guild/prison/prison";
}
