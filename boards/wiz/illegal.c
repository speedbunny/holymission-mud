inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("The Black board");
   my_env = "room/wiz/illegal";
}
