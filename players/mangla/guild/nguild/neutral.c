#define TP      this_player()
#define TO      this_object()

inherit "room/room";
object clomb;

reset(arg) {
  ::reset(arg);
  if(!arg) {

        set_light(1);
        short_desc = "The Room of Total Neutrality.";     
        long_desc = "\
This non descript room has nothing of any worth in here.  Drab grey tones throughout \
make this room the most lethargic and apathetic place in the Jedi building.  Someone \
has left a lazily scrawled note lying on the floor, and there is a pedestal in the \
centre of the room.\n\n";


        property=({"no_telport","no_fight","no_steal"});
 
        smell="\nThe room smells as boring and non descript as it looks.\n";


        dest_dir = ({
            "/players/mangla/guild/borrow",  "north",
        });


         items = ({
             "room", "A boring grey room",            
             "walls", "Grey, grey, grey.",
             "place", "A boring grey place",       
             "note", "A lazily scrawled note lies on the floor, perhaps you could 'read' it?",
             "pedestal", "A large pedestal situated in the centre of the room",           
        });
    }
}

static climbon() {
  if((clomb)&&(present(clomb,this_object()))) {
    return ". "+clomb->query_name()+" is standing on the table";
  }
}

init() {
  ::init();
  add_action("_sacrifice","sacrifice");
  add_action("_climb","climb");
  add_action("_north","north");
  add_action("_read","read");
  if(TP->query_guild()!=4 &&!TP->query_immortal()) {
        write("You are not one with the force.\n");
        TP->move_player("is moved#players/redsexy/jedi/areas/guild/room");
   }
}

_climb(str) {

   if(!str) {
    notify_fail("Climb what?\n");
    return 0;
  }
   if(TP->query_real_guild()!=4) {
        write("A voice booms: You cannot pledge your allegiance unless you are a jedi!\n");
        return 1;
    }

  if((str=="off")||(str=="down")||(str=="off pedestal")) {
    if(this_player()!=clomb) {
      notify_fail("But you're not standing on the pedestal.\n");
      return 0;
    }
    clomb=0;
    write("You climb off the pedestal.\n");
    say(this_player()->query_name()+" climbs off the pedestal.\n");
    return 1;
  }

  if((clomb)&&(present(clomb,this_object()))) {
    notify_fail("Someone is already on the pedestal.\n");
    return 0;
  }
  clomb=this_player();
  write("You climb on the pedestal.\n");
  say(this_player()->query_name()+" climbs on the pedestal.\n");
  return 1;
}


_north() {
  if(this_player()==clomb) {
    write("You have to climb off the pedestal before you can leave here.\n");
    return 1;
  } 
}

_sacrifice(str) {
  int no;
  if(!str) return;

  if(this_player()!=clomb) {
    write("You have to be on the pedestal to make a sacrifice.\n");
    return 1;
  }
  if(str=="money" || str=="coins") {
    write("But how many coins do you want to sacrifice?\n");
    return 1;
  }
  if(!(no=(str=="1 coin")) && !sscanf(str,"%d coins",no)) return;
  if(this_player()->query_money()<no) {
    write("You don't have that many coins.\n");
    return 1;
  }
  if(no<0) {
    write("Don't be silly.\n");
    return 1;
  }
  this_player()->add_money(-no);
  write("You sacrifice the coins.\n");
  say(this_player()->query_name() + " sacrifices some money.\n");
  
  if(no < 2500) {
    write("Nothing seems to happen.\n");
    say(this_player()->query_name() + " doesn't seem to make anything happen.\n");
    tell_room(this_object(), "A lazy voice speaks: I ain't accepting no low rates.\n");
    return 1;
 }
  if(no > 2500 || no == 2500) {
    tell_room(this_object(), "A sleepy sigh eminates from above.\n");
    write("You feel as boring and grey as the next person.\n");
    this_player()->set_al(1);
    return 1;
  } 
}


int _read(string str) {

  switch(str) {
    case "note" :
    case "words" :
    case "sign" : 
      {
        write("We just can't be bothered with this Empire versus Rebellion crap.\n");
        write("You know the routine. \n");
        return 1;
       }
    
    default :
      write("What do you want to read?\n");
      return 0;
  }
}



