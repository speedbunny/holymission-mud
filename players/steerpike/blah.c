inherit "/room/room";

reset(arg)
{
   ::reset(arg);
   if (arg) return;
   set_light(1);
   short_desc="Shower";
   long_desc="You are in a nice warm shower. It is very wet in here.\n";
   dest_dir=({"players/steerpike/workroom", "out"});
}

init()
{
   ::init();
   call_out("wet", 3);
}

wet() { write("You get very wet.\n"); }
