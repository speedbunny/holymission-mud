
inherit "obj/treasure";
string location;

 
reset(arg) {
if (arg) return;

  set_id("box");
  set_alias("black box");
  set_weight(0);
  set_value(1);
  set_short("A small black box");
  set_long("This box is about 2 inches cubic, and has a red button\n"+
           "in the center of the top side. Below the button you see\n"+
           "a pair of DICE rolling over and over, always showing 6 x 6.\n"+
           "WARNING: PLAYERS WILL TAKE DAMAGE IF THEY PUSH THIS BUTTON.\n"+
           "ONLY WIZARDS ARE ALLOWED TO USE THIS ITEM!!\n");

  }



init()  {
   ::init();

   add_action("push",   "push");
   add_action("push",   "press");

}

push(str)  {

 if (!str || str!="button") return 0;
  if(this_player()->query_level()>29)  {
        write("You are teleported somewhere else.\n");
        this_player()->move_player("X#players/dice/workroom");
       return 1;  }
 else {
       write("You are not powerful enough to use this item!\n");
       return 1;
   }
}

