inherit "room/room";

reset(arg) {
   if (arg) return;
   set_light(1);
   short_desc="Test room";
   long_desc="This room is used by Shaka for testing monsters, the \n"+
             "walls are covered with blood,the floor is scattered\n"+
             "with severed body parts. in the middle of a clean spot on\n"+
             "the wall hangs a sign with a lever besides it.\n";
   items = ({"walls","they're covered with blood",
             "blood","blood just plain red blood",
             "floor","body parts all over the floor",
             "body parts","severed arms legs etc etc",
             "body","severed arms legs etc etc",
             "parts","severed arms legs etc etc",
             "spot","how remarkable a clean spot between all this blood",
             "wall","covered with blood",
             "sign","their is something written on it",
             "lever","A lever to control something"});
    dest_dir=({"players/shaka/workroom","workroom",});
}

init() {
  ::init();
  add_action("read","read");
  add_action("pull","pull");
}

read(arg)
{
  if (arg=="sign")
   {
    write("A dummy production machine, just pull lever to \n"+
          "create a test dummy.\n");
    say(this_player()->query_name()+" reads the sign.\n");
    return 1;
   }
  notify_fail("Read what?");
  return;
}

pull(arg)
{
  if (arg=="lever")
   {
    write("Click!");
    say("Click!");
    produce();
    return 1;
   }
  notify_fail("Pull what?");
  return ;
}

produce()
{
int i;
  write("You hear machines starting behind the wall!\n");
  say("You hear machines starting behind the wall!\n");
  for (i=1;i<=5;i++) call_out("rattle",i);
  call_out("place_dummy",6);
  return 1;
}

rattle()
{
 write("Tsjak Puff Rattle!\n");
 say("Tsjak Puff Rattle!\n");
 return;
}

place_dummy()
{
 write("The sign claps open and a dummy falls out!\n"+
       "The sign immediatly closes .\n");
 say("The sign claps open and a dummy falls out!\n"+
       "The sign immediatly closes .\n");
 transfer(clone_object("players/shaka/monsters/dummy"),this_object());
 return;
}






