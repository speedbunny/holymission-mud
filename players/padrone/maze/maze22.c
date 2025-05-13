/* In the mirrormaze... */


inherit "/players/padrone/maze/maze";

MAZE_ROOM()
{
    return ({"maze12", 0, "maze21", "maze23"});
}

reset(arg)
{
     ::reset(arg);
     dest_dir = dest_dir + ({"/players/padrone/walker/bedroom","south"});
}

init()
{
   ::init();
   call_out("msg",1);
}

msg()
{
   write("You hear someone whisteling in the south !\n");
}
