inherit "/boards/board";

void reset(int arg){
  ::reset(arg);
  if(!arg) {
    set_name("Monk Bug Board");
    my_env="players/sauron/guild/rooms/bug_room";
  }
}
