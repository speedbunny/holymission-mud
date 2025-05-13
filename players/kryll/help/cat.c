#define TP    this_player()
#define TPN   TP->query_name()
#define TO    this_object()
#define TPRN  TP->query_real_name()
#define ENV   environment
 
inherit "obj/container";
 
// prototypes
status check_loaded();

void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_name("catapult");
  set_alias("big catapult");
  set_max_weight(1000);
  set_short("A big Catapult");
  set_long("This is a big wooden catapult.  It looks like a big shovel "+
             "with a strong rope on it.  There is big iron sign on it.\n");
  set_can_get(0);
  set_weight(1000);
}
 
void init() {
  ::init();
  add_action("do_read","read");
  add_action("do_enter","enter");
  add_action("do_leave","leave");
}
 
status do_read(string str) {
  if(!str && str!="sign") {
    notify_fail("Read what?\n");
    return 0;
  }
 
  write("CatapultVersion2000:\n\n"+
        "TypeEnterCatapultAndWeWillPutYouInThenSayWhichFloor\n"+
        "YouWantToBeShotToWeOfferFloor 1, 2, Or 3\n\n");
  return 1;
}
 
status do_enter(string str) {
  if(str != "catapult") {
    notify_fail("Enter what ?\n");
    return 0;
  }
 
  if((!check_loaded()) && (!present(TPRN, TO))) {
    TP->set_vis();
    write("You enter the catapult.\n");
    say(TPN + " enters the catapult.\n");
    move_object(TP, TO);
    return 1;
  }
 
  if(present(TPRN, TO) ) {
    write("You are already in the catapult.\n");
    return 1;
  }
  write("The catapult only holds one person at a time.\n");
  return 1;
}
 
status do_leave(string str) {
  if(str != "catapult") {
    notify_fail("Leave what ?\n");
    return 0;
  }
 
  if(present(TPRN, TO)) {
    write("You leave the catapult.\n");
    tell_room(ENV(TO), TPN + " leaves the catapult.\n");
    move_object(TP, ENV(TO));
    return 1;
  }
  write("You aren't in the catapult.\n");
  return 1;
}
 
status check_loaded() {
  object *inv;
  int    i, sz;
 
  inv = all_inventory(TO);
  for(i=0, sz=sizeof(inv); i<sz; i++) {
    if(inv[i]->query_player())
      return 1;
  }
  return 0;
}
