
inherit "room/room";
object o1;
object stone;
int counter;
 
reset(arg) 
{
  if (!present("witch",this_object())) {  /* to get only one witch */
       counter=1;
       }
   else {
       counter=5;
       }
       
  if (arg) return;
  set_light(1);
  property = "no_teleport";
  short_desc = "On a strange roof";
  long_desc = 
    "You have now reached the roof of a strange building. "+
    "There are pieces of gingerbread lying around. The aroma "+
    "of the gingerbread is SO strong that you can hardly avoid "+
    "stealing some. If you look up you see the moon shining "+
    "on the roof and gazing down you see the outline of the "+
    "waterchannel and the big wooden door.\n";
  dest_dir = 
    ({
      "/players/whisky/garden/room/waterchannel", "down",
    });
  
  items = 
    ({ 
      "roof","You see a big roof with lots of gingerbread on it",
      "gingerbread","You see a big piece of tasty gingerbread",
      "moon","You see the full moon shining at your face",
      "waterchannel","You see a metal black painted waterchannel",
      "door","You see the contours of a big wooden door"
      });
}
 
init() 
{ 
  ::init(); 
  add_action("take","take"); 
  add_action("take","get");
}
 
take(str) 
{
object bread,witch;
 
 if ( str != "gingerbread"  && str!="bread") return; /* then she can take what she likes */
 
      if (counter > 4)
    {
      write("Sorry, but the roof is empty.\n");
      say(this_player()->query_name()
          +" tries to pick a gingerbread but fails.\n");
      return 1;
    }
    
    bread=clone_object("players/whisky/garden/obj/gingerbread"); /* she will get it */
    if(transfer(bread,this_player())) {
    write("You are carrying too much.\n");
    destruct(bread);
  }

    
  if (counter == 1)
    {
      write("You hear a strange noise coming out from the house.\n");
      say(this_player()->query_name()+ " picks a gingerbread.\n\n");
      say("Suddenly you hear a strange noise coming out from the house.\n");
      counter = counter +1;
      return 1;
    }
 
  if (counter == 2) 
    {
      counter = counter +1;
      write("You can hear a devilish laugher\n");
      say(this_player()->query_name() +" can't stop to pick gingerbread.\n\n");
      say("Suddenly you hear a devilish laugher\n");
      return 1;
    }
 
  if (counter == 3) 
    {
      counter = counter +1;
      write("You pick up another gingerbread.\n");
      say(this_player()->query_name()+" picks up another gingerbread.\n");
      write("The moon hides behind a dark cloud and you can hear the \n"
       +"devilish laugher getting louder and louder.\n");
      say("The moon hides behind a dark cloud and you can hear the \n"
     +"devilish laugher getting louder and louder.\n");
      write("Something in your mind tells you that you should now leave\n"
       +"this place.\n");
      say("Something in your mind tells you that you should leave\n"
     +"this place now.\n");
      return 1;
    }
 
  if (counter == 4) 
    {
      counter = counter + 1;
      write("You picked the last gingerbread.\n\n");
      say(this_player()->query_name()
     +" picks up the last gingerbread.\n"); /* End Moonchild edit */
      write("Suddenly you recognize a dark shadow in the moon "
       +"coming nearer and nearer.\n\n");
      say("Suddenly you recognize a dark shadow in the moon coming "
     +"nearer and nearer.\n\n");
      write("You hear again the devilish laugher and recognize the"
       +" shadow landing on\nthe roof.\n\n");
      say("You hear again the devilish laugher and recognize the "
     +"shadow landing on\nthe roof.\n\n");
      witch=clone_object("players/whisky/garden/monster/witch");
      move_object(witch,this_object());
      write("The evil witch arrives, run away before you die.\n\n");
      say("The evil witch arrives, run away before you die.\n\n");
      return 1;
    }
  
 
  return 1;
}

