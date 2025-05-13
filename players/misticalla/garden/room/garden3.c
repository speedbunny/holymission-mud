
#define TREE "/players/whisky/tree/room"
 
inherit "room/room";
#include "../garden.h" 
int counter; /* apple counter....giggle */
 
void reset(int arg) 
{
  if (filter_live(TO) < 3)
  {
   CM("ant");
   CM("ant");
   CM("ant");
   CM("ant");
  }
  if (arg) return;
  set_light(1);
  short_desc = "In a beautiful garden";
  no_castle_flag = 0;
  long_desc = BS(
        "This is the western corner of Chantilly's beautiful garden. "
      + "A beautiful apple tree invites you to climb up and to "
      + "'pick' some of the delicious 'apples'. "
      + "To the north a brown fence borders the garden to the forest. "
      + "At the roots of the tree trunk you can see a small hole.");

      items = ({ "fence","You see a big brown garden fence",
           "tree","You see a big old apple tree",
	   "hole","It seems big enough for you to enter" });
      dest_dir = ({ "room/jetty","south",
                     ROOM+"/garden2", "east", });
}

init() {
  add_action("climb","climb");
  add_action("enter","enter");
  add_action("pick","pick");
  ::init();
}

climb(str) {
    object *u;
    int i;

   u = users();
    for (i=0;i<sizeof(u);i++)
{
   if (present("exsoul",u[i]) && !this_player()->query_immortal())
    {
      call_out("remove_lag",1,u[i]);
      call_out("replace_lesslag",2,u[i]);
    }
  }
   if (str=="fence") {
     write("\nYou climb over the garden fence.\n\n");
     this_player()->move_player("over the fence#"+ROOM+"/path1");
     return 1;
  }
  if (str=="tree" || str=="up tree" || str=="up the tree") {

  write("\nYou climb up the apple-tree.\n\n");
  this_player()->move_player("up the apple-tree#"+TREE+"/t5");

  return 1;
}

}
enter(str) {
  if (str=="hole") {
   tell_object(this_player(),"You slip into the hole.\n");
  move_object(this_player(),"/players/whisky/garden/room/mousehole1");
  say(this_player()->query_name() + " slips into the hole.\n");
/* Tatsuo may 5, 95 : Removed gorgurack area, reason posted on inner */
     return 1;
  }
}

 pick(str) {
  object ob;
  if (str!="apple") return;
  if (counter >= 8) {
    write("Sorry, but the tree is empty.\n");
     return 1; }
  else {
   write("You picked an apple.\n");
    say(this_player()->query_name()+ " picked an apple.\n");
  counter++;
  ob=clone_object("players/whisky/garden/obj/apple");
  if (transfer(ob,this_player()))
 {
    move_object(ob,environment(this_player()));
}
  return 1; }
  }

remove_lag(pl)
{
  object os;
  
  os = present("exsoul",pl);
 
  if (os)
  destruct(os);
}

replace_lesslag(pl)
{
  object ns;

  ns =clone_object("/obj/soul");
  move_object(ns,pl);
}
