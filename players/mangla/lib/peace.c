#include "/sys/defs.h"

int main(string str) {

  int i;
  object *ob,env;

  ob = all_inventory(env=ENV(TP));
  for (i=0; i<sizeof(ob); i++) {
    if (living(ob[i]) && ob[i]->query_attack()) {
      ob[i]->stop_fight();
      ob[i]->stop_fight();
      ob[i]->stop_hunter(1);
      tell_room(env,
                ob[i]->NAME + " suddenly looks very peaceful.\n");
    }
  }

  return 1;
}

