inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Wizard bulletin board");
   my_env = "room/wiz/general";
}
