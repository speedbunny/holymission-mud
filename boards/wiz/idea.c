inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Wizard Idea");
   my_env = "room/wiz/idea";
}
