inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Mentor wanted board");
   my_env = "room/wiz/mentor";
}
