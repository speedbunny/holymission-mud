inherit "/boards/board";

int valid_remove(object who,int no) {
  if(who->query_real_name()=="/guild/master"->query_wiz(7))
    return 1;
  else
    return ::valid_remove(who,no);
}

void reset(int arg) {
  ::reset(arg);
  if(!arg) {
    set_name("Monk Guild Board");
    my_env="players/whisky/guild/room/c10";
  }
}
