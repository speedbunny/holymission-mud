#include "/room/std.h"
#include "/obj/door.h"

inherit "room/room";

object obj_1,obj_2;
object key; 
object creature;

status searched;
reset(arg)  {
     searched = 0;
     if(!arg)  {
    
     if(!present("door")) {
  
      MAKE_DOORS("/players/texas/rooms/rm03","north",
                 "/players/texas/rooms/rm04","south",
                 "molten-rock",                      
                 "magma",                            
                "A door made from Molten Magma \n",
                 1,1,1);               
		 }
     obj_1->set_closed(1);
     obj_1->set_locked(1);
     obj_1->set_both_status();
   }
if (arg)  return;
  ::reset(arg);
    if(!creature) {
      creature=clone_object("/players/texas/monsters/faragorn");
      move_object(creature,this_object());
    }
    set_light(0);
    short_desc = "You have entered a large pit.";
    long_desc = 
	       "You are standing in one corner of a large pit. In the\n" +
               "of the room is a strange pillar with an inscription\n" +
	       "written on it in some strange language. There are four\n" +
	       "doors, each leads downwards into the unknown. The way\n" +
               "back to the corridor is now sealed off and you realize\n" +
               "the only way out is through one of the doors.\n";

    dest_dir=({
               "/players/texas/rooms/rm06","south",
               "/players/texas/rooms/rm05","east",
             "/players/texas/rooms/rm07","west"
             });
    items = ({
	       "pillar","A large featureless pillar.\n",
	       "inscription","A strange inscription of strange writing\n",
	       "north door","An ancient heavy door made of pure gold ! \n"
            });
    return 1;
   }
init()  {
  ::init();
    add_action("read","read");
    add_action("search","search");
}
int read(string str) {
   if(!str) {
          write("Read what ?\n");
	  return 1;
       }
   if(str!="inscription") {
    	  write("That is not here.\n");
	  return 1;
       }
         write("The inscription is in a language unfamiliar to you but\n" +
	       "you are able to make out the words: 'Beware the doors!'\n"
	      );
	return 1;
}
int search(string str) {
  if(!creature) {
    if(!searched) {
      if(!str) {
        write("search what?\n");
        return 1;
      }
      if(str=="center of floor") {
        if(this_player()->query_int() < 15) { 
           write("You know that something is hidden there, but you just\n" +
	         "dont seem to have the brains to find it. Maybe you \n" +
	         "should study to improve your intelligence.\n");
	 return 1;
      } 
      MAKE_KEY(key,"molten-rock","magma");
      transfer(key,this_player());
      write("You cleverly find the hidden latch and find a key!\n");
      say(this_player()->query_name()+" has found a hidden key!\n");
      searched = 1;
      return 1;
    }
    else {
      write("You search around in vain and decide nothing is here.\n");
      return 1;
    }
  }
     else {
       write("you cannot do that whilst faragorn is present\n");
       return 1;
     }
  }
}
