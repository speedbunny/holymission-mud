#define TO this_object()
#define TPN this_player()->query_name()
#include "/obj/lw.h"
inherit "/std/object";

int query_propery(string str) {
    if(str == "no_teleport" || str == "no_fight") {
        return 1;
    }
    return 0;
}

void _squonk() {
  int j;
  object env, *ob;
  write("The Force bubble bursts and you fall back to the ground.\n\n");
  env=environment(this_object());
  write(env); write("\n");
  ob=all_inventory(this_object());
  tell_room(env, "The bubble's occupant fall out and lands with a thud!\n");
  move_object(TO,"/room/void");
  j=sizeof(ob);
  for(;j>0; j-- ) {
    move_object(ob[j-1], env);
    if(living(ob[j-1]))
      ob[j-1]->look();
  }
  destruct(this_object());
  return;
}

int id(string str) {
  return str == "bubble" || str == "force bubble";
}

int set_long(string str) {
  if(!str) return 0;
  long_desc=str;
  return 1;
}

int long() {
  object *ob;
  object env;  // Will save some processing time.
  int i, j;

  writelw(long_desc);
  if(environment(this_player()) == this_object()) {
    printf("\n");
    env = environment();
    if(env) {
      env->long();
      ob = all_inventory(env);
      j = sizeof(ob);
      for(i = 0; i < j; i++) {
        if(!ob[i]->id("bubble") && !ob[i]->query_invis())
          write(ob[i]->short() + "\n");
      }
    }
  }
  return 1;
}

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  if(clonep())
    call_out("_squonk",600,0);

  set_light(1);
  set_can_get(0);
  set_long("From your vantage point inside the force bubble, you see:\n");
  set_short("Force Bubble");
  set_name("force Bubble");
  set_alias("bubble");
}

void init() {
  ::init();
  add_action("_leave","leave");
}

int _leave(string str) {
  if(!str) {
    notify_fail("Leave what?\n");
    return 0;
  }

  if(str=="bubble") {
    write("You leave the bubble and rejoin the outside world.\n");
    tell_room(environment(this_object()), TPN+" bursts the Force bubble "+
               "and arrives back on the ground,\nready for action.\n");
    move_object(this_player(),environment(this_object()));
    move_object(TO, "/room/void");
    this_player()->look();
    destruct(this_object());
    return 1;
  }
}

