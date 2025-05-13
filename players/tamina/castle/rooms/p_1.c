#include "/obj/door.h"
#include "/players/tamina/defs.h"

inherit "room/room";

/*  object obj_1,obj_2;  */

reset(arg) 
{
/*  if (!present("door")) 
 * {
 *  MAKE_DOORS("/players/tamina/castle/rooms/p_1", "east", "/players/tamina/castle/rooms/p_2", "west", "rusty", "key001", "This is an old iron door, with a rusty lock.\n", 1,1,1);
 *  }
 */
   if(arg) return;

     set_light(-2);
     short_desc = "End of passage";
     long_desc = 
   "This is where the passage ends.\n"+ 
   "There is a door facing you, which looks fairly solid, despite\n"+
   "its apparent age.  Or you can return back down the dark corridor\n"+ 
   "to the light of the Throne Room.\n"; 

     dest_dir = ({
   CROOMS + "junction","west",
     });
   
     items = ({
  "door",
"This is a rusty iron door, with an old lock.  You can see a strange "+
"glow emitting from under the rim of the door.  You feel a distinct power "+
"seeping through the door, which sends shivers up your back...\n"+
"The door seems to be securely locked at the moment",
  });

}

init()
{
  ::init();
  AA("_unlock", "unlock");
  AA("_open",   "open");
  AA("_close",  "close");
  AA("_Knock",  "Knock");
}

int _unlock(string str)
{
  if (str == "door")
  {
    write("You cannot unlock the door, since you do not have the correct key.\n");
    say(TPN+" tries to unlock the door.\n");
  
    return 1;
  }
}

int _open(string str)
{
  if (str == "door")
  {
    write("But the door is securely locked !!\n"+
	  "You fail to open the door.\n");
      say(TPN+" fails to open the door.\n");

    return 1;
  }
}

int _close(string str)
{
  if (str == "door")
  {
    write("But the door is not open !!\n");
    say(TPN+" tries to close a door that is not open...\n");
  
    return 1;
  }
}

int _Knock(string str)
{
  if (!str || str == "door")
  {
    write("Your magic fails to work on the iron door...\n");
    say(TPN+" fails to cast a Knock spell on the iron door.\n");

    return 1;
  }
}  
