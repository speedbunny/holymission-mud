inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Wiz Flame board");
   my_env = "room/wiz/flame";
}
