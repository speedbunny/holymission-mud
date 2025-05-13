
inherit "obj/treasure";
string location;
get() {return 1;}
drop() {return 1;}

 
reset(arg) {
if (arg) return;

  set_id("box");
  set_alias("white box");
  set_weight(0);
  set_value(1);
  set_short("A small white box");
  set_long("This box looks like a copy of one created by Dice.\n"+
	   "The button on it seems to indicate it wants to be pressed.\n"+
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
        this_player()->move_player("X#players/portil/workroom");
       return 1;  }
 else {
       write("You are not powerful enough to use this item!\n");
       return 1;
   }
}

query_auto_load(){ return "players/portil/funobj/transbox:";}
