inherit "room/room";
object ctm;
reset(arg){::reset(arg);
      if(!arg){
       if(!ctm){
       ctm=clone_object("/players/dice/quest/ctm");
       move_object(ctm,this_object());
       }
    if (arg) return;

    set_light(0);
    short_desc = "Tomb";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc = 
        "You are standing in a dark tomb.\n"+
        "You get the unpleasant feeling that you are being watched all\n"+
        "the time. But as you look around you don't see a living thing.\n"+
        "Except for some writing on the wall.\n";
          items = ({
              "letters","Strange writing on the wall, maybe you can read it",
              "tomb","A place where a corpse is put in",
              "gravetomb","A place where a corpse is put in",
              "place","A scary place",
              "dead","They are not walking around, they're dead",
              "writing","Strange letters written in the wall,\n"+
                        "maybe you should read them.",
              "wall","A strange wall indeed",
              "nothing","How can you examine nothing ??",
              });

    smell = "The smell of rotting flesh is strong.";
   }
  }
init(){  
    ::init(); 
    add_action("read","read");
     add_action("up_fail","climb");add_action("up_fail","up");
     add_action("up_fail","u");
   }
read(str){
    if(!str){
     notify_fail("Read what ?\n");
     return 0;
     }
if((str=="wall")||(str=="strange wall")||(str=="writing")||(str=="letters")){
      if(set_light(0) < 1 ){
 notify_fail("It's too dark to read.\n");
 return 0;
  }
     write("You see a strange writing on the wall.\n\n\n"+
           "The letters begin to move as you read them.\n"+
  "You feel the urge to say : Evil spirit let me out, please.\n");
    say(this_player()->query_name()+" reads some strange writing.\n");
     return 1;
     }
  }
up_fail(str){
  if(!str){
  notify_fail("Climb what ?\n");
  return 0;
  }
if((str=="walls")||(str=="up")){
  write("The walls are impossible to climb.\n");
  return 1;
  }
 }
