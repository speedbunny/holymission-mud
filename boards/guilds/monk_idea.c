inherit "/boards/board";

void reset(int arg){
  ::reset(arg);
  if(!arg) {
    set_name("Monk Idea Board");
    my_env="players/sauron/guild/rooms/idea_room";
  }
}
