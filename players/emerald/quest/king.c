
#define TO    this_object()
#define TPN   this_player()->query_name()
#define CLONE clone_object
#define MOVE  move_object
#define TELLR tell_room
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return ;
  set_name("The King");
  set_short("The King");
  set_alias("king");
  set_long("The King of this land.\n"
         + "His treasury is in need of more gold.\n");
  set_gender(1);
  set_race("human");
  set_al(-100);
  set_level(75);
  set_wc(42);
  set_ac(25);
  set_aggressive(0);
  set_no_steal();
  add_money(50+random (51));
  load_chat(30,({
       "The King say: Drat that Alchemist!\n",
       "The King says: Where is the gold?\n",
       "The King says: He was supposed to bring the gold hours ago!\n",
     }) );

}
void init() {
  ::init();

  add_action("_give", "give");
}

int _give(string str) {
  object goldbar;

  switch(str) {
    case "gold to king" :
    case "gold bar to king" :
    case "gold to the king" :
    case "gold bar to the king" :
      goldbar = present("gold",this_player());
      if(!goldbar) {
        write ("Hmmm...  looks like you need to get something.\n");
        return 1;
      }
      write("You give the gold bar to the king.\n");
      say(TPN + " gives the gold to the king.\n");
      write("The King says: Thank you, "+TPN+", you have done very well!\n");
      this_player()->set_quest("goldbar");
      destruct(goldbar);
      return 1;
    case "gold" :
      notify_fail("Give gold to whom?\n");
      return 0;
    default :
      notify_fail("Give what?\n");
      return 0;
  }
}
