inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Dworkin's Board of Many Wonders");
   my_env = "players/dworkin/workroom";
}
