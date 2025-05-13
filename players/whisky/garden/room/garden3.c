
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
        );

      items = ({ "fence","You see a big brown garden fence",
           "tree","You see a big old apple tree",
           });
      dest_dir = ({
                   "players/haplo/ravine/ravine5", "south",
                     ROOM+"/garden2", "east", });
}

init() {
  add_action("climb","climb");
  add_action("pick","pick");
  ::init();
}

climb(str) {
    object *u;
    int i;

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

