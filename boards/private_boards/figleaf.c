inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Figleaf's personal board");
   my_env="players/figleaf/workroom";
}
