inherit "/boards/board";

#if 0
#include "/sys/sheriffs.h"

int valid_remove(object who,int no) {
  if(member_array(who->query_real_name(), SHERIFFS) != -1)
    return 1;
  else
    return ::valid_remove(who, no);
}
#endif

void reset(int tick) {
  ::reset(tick);
  if(tick) return;

  set_name("Bulletin board");
  my_env="room/player/sheriff";
}
