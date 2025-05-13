#include "/players/ambrose/room.h"
#include "/players/ambrose/defs.h"

void reset(int arg)
 {
  ::reset(arg);
    if(arg)
       return;
      set_light(1);
      short_desc="A windy path down a cliff.";
      long_desc=
     "The path continues along the cliffside ever winding to the valley \n"
     +"floor below.  Looking over the edge makes you realize how high \n"
     +"you are.  The cliff wall along here is covered in more of the \n"
     +"dark stone from the cavern.  Even here in the light it makes the \n"
     +"area look darker.\n";
      property=({"no_teleport"});
      dest_dir=({
                AVAL +"entrance/cliff","up",
                AVAL +"entrance/cliff3","east",
      });
      items=({
      "room","You need to make it into something!",

           });
       smell="Does'nt smell like anything.";
     }
  void init()
  {
   ::init();
    add_action("no_way_out","",1);
    add_action("entrance","enter");
 }

   int entrance(string str)
   {
    if(str=="crack")
      {
        write("You slip into the narrow crack into the darkness beyond.\n");
        say(PNAME+"is suddenly gone.\n");
        MOVEP("enter the crack.#players/ambrose/avalon/portal/portal1");
        return 1;
       }
       write("Enter what?\n");
       return 0;
     }
