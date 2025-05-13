inherit"room/room";

object dummy1;

reset(arg)
{  if(!arg)
   {  if(!dummy1)
      { dummy1=clone_object("/players/beardy/workarea/barberm");
        move_object(dummy1,this_object());
      }

      set_light(1);
      short_desc="This is the Barber's shop";
     long_desc="This is a beautiful little Barber's shop, perhaps you can 'order'\n"+
	        "something in\ here. It is a small nearly tiny room with a huge chain\n"+
	        "in the center. The walls are covered with different coloured hair and\n"+ 
	        "some ears are there too. The barber is standing beside his bloody chair,\n"+
	        "ready to cut you - ops - your hair.\n";
      dest_dir=({"/players/beardy/east_harbour/room/road001","south"});
      property=({"no_teleport","no_steal","no_sneak"});
      smell= "It smells like cut hair.";
      
   }
}

init()
{ add_action("order", "order");
  ::init();
}

order(str)
{ if(!str)
  { write("What do you want to order? Perhaps a new haircut ?\n");
    return 1;
  }
  if(str=="haircut")
  { write("Some time later, you got a nice new hairstyle.\n");
    if(random(3)==1)
    
    { write("But - ops - you lost you ear here...\n");
      this_player()->reduce_hit_point((this_player()->query_hp())/2);
    }
    else
      write("You have been lucky, the barber didn't touch anything than you hair\n");
      
    return 1;
  }
}

