inherit "/boards/board";

void reset(int tick) {
   ::reset(tick);
   if(tick) return;

   set_name("PK Area Board");
   my_env = "players/saffrin/area/pk/room/d";
}
