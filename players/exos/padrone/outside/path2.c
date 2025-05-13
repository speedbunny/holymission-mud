

/* path2.c */

inherit "/room/room";

object squirrel;

void reset(int flag) 
{
    if (!squirrel || !living(squirrel)) {
	squirrel = clone_object("obj/monster");
	squirrel->set_name("squirrel");
	squirrel->set_level(1);
	squirrel->set_ep(60);
	squirrel->set_hp(10);
	squirrel->set_ac(2);
	squirrel->set_wc(4);
	squirrel->set_al(50);
	squirrel->set_short("A squirrel");
	squirrel->set_long("This is a small, furry squirrel.\n" +
			   "It looks very nice and friendly.\n");
	move_object(squirrel, this_object());
    }
    if (flag == 0)
    {
      set_light(1);
      dest_dir = ({
         "players/padrone/outside/path1", "north",
         "players/padrone/outside/crossing", "south",
      });
      short_desc = "On a small path";
      long_desc =
	 "You are on a small path winding through the bushes.\n"+
         "To the north you see a big dark forest and to the west\n"+
         "a big blue lake. The sun is shining on you and there are\n"+
         "several kinds of insects crawling in your pants and biting\n"+
         "you.\n";
     }
}
 
