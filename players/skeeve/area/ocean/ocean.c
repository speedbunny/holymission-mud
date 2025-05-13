inherit "room/room";

#include "/players/skeeve/area.h"

int count;
string *fishes =({"herring","perch","cod","tunny","salmon",
             "sea horse","shark","barracuda"});

reset(arg,DEST_DIRS) {
  if (arg) return;
  set_light(1);
  short_desc = "Ocean";
  long_desc =
    "You are standing in the shallow ocean.\n"+
    "You think, maybe there are fishes.\n"+
    "You feel that it might be dangerous to stay here.\n";
  smell="The air smells salty here";
  dest_dir = DEST_DIRS;
  items = ({
      "ocean","Maybe there are fishes in it",
      "water","Maybe there are fishes in it",
      "ground", "Maybe there are many fishes in it",
      "fish", "Maybe you should first search one",
      "fishes","Maybe you should first search one"
    });
  count = 10;
}
    
/* overwrite the standart search routine */
do_ser(str) {
  int i;
  
  if (this_player()->query_ghost()) {
     write("You can't do that in your immaterial state.\n"); 
     return 1; 
  }
  
  if (!random(count)) {
    create_robber(fishes[random(2)+6]);
    return 1;
  }
  
  count--;
  
  /* success of search depends on intelligence of player */
  if (random(11)*3 > this_player()->query_int()) {
    say("You search but find nothing.\n");
    write(capitalize(this_player()->query_name()) +" search but find nothing.\n");
    return 1;
  }
  
  if ( (str == fishes[0]) || (str == fishes[1])
     ||(str == fishes[2]) || (str == fishes[3])
     ||(str == fishes[4])
     ) {
    if (present(str)) {
      write("You found again a "+str+" which you found before.\n");        
    } else {
      say("You find a " + str + ".\n");
      write(capitalize(this_player()->query_name()) +" find a " + str + ".\n");
      move_object(clone_object(MONSTERS+"soup_fish")->config(str),this_object());
    }
    return 1;
  } else if ( (str=="seahorse") 
          ||  (str=="sea horse")
          ||  (str=="sea-horse") ) {
    if (present("sea horse",this_object()))
      write("You found again a sea horse which you found before.\n");        
    else {
      say("You find a sea horse.\n");
      write(capitalize(this_player()->query_name()) +" find a sea horse.\n");
      create_seahorse();
    }
    return 1;
  } else if ((str=="shark") || (str=="barrakuda")) {
    create_robber(str);
    return 1;
  } else if ((str=="ocean") || (str=="fish")
           ||(str=="at ocean") || (str=="in ocean")
           ||(str=="at ground") ) {
    i = random(8);
    if (i<=4) 
      if (present(fishes[i],this_object()))
        write("You found again a " + fishes[i] + " which you found before.\n");        
      else {
        say("You find a " + fishes[i] + ".\n");
        write(capitalize(this_player()->query_name()) +" find a " + fishes[i] + ".\n");
        move_object(clone_object(MONSTERS+"soup_fish")->config(fishes[i]),this_object());
      }
    else if (i=5)
      if (present(fishes[i],this_object()))
        write("You found again a " + fishes[i] + " which you found before.\n");        
      else {
        create_seahorse();
        say("You find a " + fishes[i] + ".\n");
        write(capitalize(this_player()->query_name()) +" find a " + fishes[i] + ".\n");
       }
    else 
      create_robber(fishes[random(2)+6]);
    return 1;
  } else
    return;
}

query_env_name() {
  return "water";
}

create_seahorse() {
   move_object(clone_object(MONSTERS+"seahorse"),this_object());
}

create_robber(str) {
  object fish;

  count += 5;  
  if (!str && (str != "shark") && (str != "barracuda") )
    str = fishes[random(2)+6];
  
  if (!fish=CASTLE->query_monster(str))
    CASTLE->add_monster(str,this_object());
  else
    move_object (fish,this_object());
  tell_room(this_object(),"Attention! A " + str + "!\n");
}
