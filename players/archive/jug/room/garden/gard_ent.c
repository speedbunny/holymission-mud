/*Room description corrected by Silas*/
inherit "room/room";

reset(arg) {
  object ob;
    
  if(arg) return;
  set_light(1);
  short_desc = "Entrance to a wonderful garden";
  long_desc = 
    "You are in the entrance to the wonderful garden of Worlds of Wonder.\n"+
    "You can smell the wonderful fragrances of a hundred different flowers\n"+
    "in the air. Whispers can be heard around you, and in the\n"+
    "distance you can hear the song of a nightingale. You feel that you\n"+
    "could stay here forever ...\n"+
    "A huge golden hedge fence blocks your way to the north and east.\n"+
    "There are many footprints in the dirt, it looks like the towns citizens\n"+
    "come here alot.\n"+
    "There is a sign here, perhaps you should look at it !!!\n";
  dest_dir = ({
    "/players/jug/room/garden/gar_cor1", "west",
    "/players/kelly/rooms/violens", "south",
  });
  items = ({
    "sign", "The sign reads: This is the royal garden belonging to Jug`s castle.\n"+
    "Here NEWBIES can look around for some experience points and other\n"+
    "usable things. But please do not kill the nightingale, she is\n"+
    "the only good monster in here (you will become evil if you kill her).\n"+
    "Hint: ask the gardener for a weapon, maybe he has something for you.\n\n"+
    "W A R N I N G !!!\n\n"+
    "Do NOT enter the garden bed where the gardener cultivates new\n"+
    "species of flowers. If you enter he will ATTACK you !!!",
    "hedge", "The hedge acts as a fence to keep out the wild animals",
    });
  ob = clone_object("players/jug/monster/gardener");
  move_object(ob, this_object());
}

init() {
  ::init();
  add_action("exit_garden", "exit");
}

exit_garden() {
  object ob;
  ob = present("shears", this_player());
  if(ob) {
    destruct(ob);
    write("\nThe shears can only be used in the royal garden of " +
	  "WORLD`S OF WONDER.\n" +
	  "So they go back to the gardener !!!\n\n");
  }
  this_player()->move_player("the royal garden#players/jug/castle");
  return 1;
}
