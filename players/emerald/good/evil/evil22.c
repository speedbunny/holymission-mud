inherit "/room/room";
 
#include "/obj/obj_defs.h"
 
object king;
 
void reset(int arg) {
  if(arg) return;
 
  set_light(0);
  short_desc = "Lion's den";
  long_desc =
    "This room is a small, but very interesting room. It looks as if "+
    "something rather large has lived here for an extremely long time. "+
    "You smell a distinct feline odor here. The walls have large claw "+
    "marks going down them, and a few appear to have teeth marks in them.\n";
 
  items = ({
    "marks","Claw marks",
    "walls","There are twenty-nine walls in this room",
  });

  smell="Male feline";
 
  dest_dir = ({
    "/players/emerald/good/evil/evil8","south",
  });
 
  clone_list = ({
    1,1,"lionprince","/players/emerald/good/obj/lionman",0,
    -1,1,"catsword","/players/emerald/good/obj/catsword",0,
    -1,1,"eye","/players/emerald/good/obj/catseye",0,
  });
 
  ::reset(arg);
}
 
void init() {
  ::init();
 
  add_action("_give","give");
}
 
int _give(string str) {
  object head;
  string what, who;
 
  if(sscanf(str, "%s to %s", what, who) != 2) {
    notify_fail("Give what to whom?\n");
    return 0;
  }
 
  if(what!="head" || !(head = present(what, TP))) {
    notify_fail("You do not have a " + what + ".\n");
    return 0;
  }
 
  king = present(who, TO);
  if(!king || !king->query_npc() || !king->id("lionprince")) {
    return 0;
  }
 
  king->set_who_gave(TPRN);
  write("You give the king's head to the lionprince.\n");
  say(TPN + " gives the king's head to the lionprince.\n");
  tell_room(TO,"\nThe Prince growls: Thank you mortal!\n" +
      "You have NOT solved the quest yet though!\n" +
      "I do not feel like letting you solve it just yet.\n\n" +
      "The Prince roars: You must kill ME first, "+TPN+"!\n"+
      "The Prince roars out a battle charge and throws "+
      "the head at ");
  say(TPN+".\n\n",TP);
  write("you.\n\n");
  TP->hit_player(10);
  destruct(head);
 
  call_out("fight_it",2,TP);
  return 1;
}
 
void fight_it(object who) {
  if(ENV(who)==TO && ENV(king)==TO)
    king->attack_object(who);
}
