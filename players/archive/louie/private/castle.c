#define HOME "/players/louie/workroom"
#define OB_ROOM "/players/moonchild/haunter/moor31"
/* where the obelisk should be in the game */

object obelisk;

int id(string arg)
 { return arg == "castle"; }

string short() 
{ return "A sandstone Obelisk"; }

void long()
 {
  write("This is a portal to Louie's area.  Just type <enter> to go there.\n");
}

void reset(int arg) 
{
  move_object(this_object(), OB_ROOM);
  if(!present("obelisk", environment(this_object())))
    move_object(clone_object("/players/louie/obj/portal1"),
		environment(this_object()));
  move_object(this_object(), HOME);
}  

void init()
{
/*  ::init(); */
    add_action("enter","enter");
  }

int enter()
{
  this_player()->move_player("in a haze#/players/louie/desert/desert1");
  return 1;
}
