inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("Haplo's Info Board");
   my_env="players/haplo/workroom";
}
