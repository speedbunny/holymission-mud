inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("New Layout Discussion");
   my_env = "room/player/new_layout";
}
