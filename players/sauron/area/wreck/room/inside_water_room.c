inherit "/room/room";

int i;
object *inv, trigger, pl;

void heart_beat() {
  if(present(trigger,this_object()) && interactive(trigger)) {
    if(!random(6)) {
      tell_room(this_object(),"BULP.....\n");
      inv=all_inventory(this_object());
      for(i=0;i<sizeof(inv);i++) {
        pl=inv[i];
        if(living(pl)) {
          if(!pl->query_immortal()) {
            pl->hit_player(2);
          }
        }
      }
    }
  }
  else set_heart_beat(0);
}

void reset(int arg) {
  if(arg) return;
  enable_commands();
}

void init() {
  ::init();
  if(interactive(this_player())) {
    trigger=this_player();
    tell_room(this_object(),"BULP.....\n");
    set_heart_beat(1);
  }
}