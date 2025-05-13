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
  
  write("The Force sphere ruptures and you fall back to the ground.\n\n");

  env = environment(TO);
  ob = all_inventory(TO);
  tell_room(env, "The sphere's occupant falls out and lands with a thud!\n");
  move_object(TO, "/room/void");
  j = sizeof(ob);

  for(;j>0; j-- ) {
    move_object(ob[j-1], env);
    if(living(ob[j - 1]))
      ob[j - 1]->look();
  }

  destruct(TO);
  return;
}

int id(string str) {
  return str == "sphere" || str == "force sphere";
}

int set_long(string str) {
  if(!str) return 0;
  long_desc = str;
  return 1;
}

int long() {
  object *ob;
  object env;  // Will save some processing time.
  int i, j;

  
  if(environment(this_player()) == this_object()) {
    writelw(long_desc + "\n");
    env = environment();
    if(env) {
      env->long();
      ob = all_inventory(env);
      j  = sizeof(ob);
      for(i = 0; i < j; i++) {
        if(!ob[i]->id("sphere") && !ob[i]->query_invis())
          write(ob[i]->short() + "\n");
      }
    }
  }
  else {
    env = TO;
    write("A sphere of force containing:\n");
    ob = all_inventory(env);
    j  = sizeof(ob);
    for(i = 0; i < j; i++) {
      if(!ob[i]->query_invis())
        write(ob[i]->short() + "\n");
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
  set_long("From your vantage point inside the sphere, you see:\n");
  set_short("Force Sphere");
  set_name("Force Sphere");
  set_alias("sphere");
}

void init() {
  ::init();
  add_action("_leave","leave");
}

int _leave(string str) {

  object *ob, env;
  int j;

  if(!str) {
    notify_fail("Leave what?\n");
    return 0;
  }

  if(str == "sphere" && environment(this_player()) == TO) {
    write("You leave the sphere and rejoin the outside world.\n");

    env = environment(TO);

    tell_room(env, TPN + " ruptures the Force sphere "+
               "and arrives back on the ground,\nready for action.\n");
    move_object(TO, "/room/void");

    ob = all_inventory(TO);
    j = sizeof(ob);

    for(; j > 0; j-- ) {
      move_object(ob[j - 1], env);
      if(living(ob[j - 1]))
        ob[j - 1]->look();
    }

    this_player()->look();
    destruct(TO);
    return 1;
  }
  return 0;
}

