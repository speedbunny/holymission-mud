inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Guild discussion board");
   my_env = "room/wiz/guild";
}
