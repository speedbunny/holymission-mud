inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Love and Friendship board");
   my_env = "players/rasta/room/bulletin";
}
