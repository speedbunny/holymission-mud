inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("LPC board");
   my_env = "room/wiz/lpc";
}
