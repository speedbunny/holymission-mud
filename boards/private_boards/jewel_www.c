inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Jewel's WWW board");
}
