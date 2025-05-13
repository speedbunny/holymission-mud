#define TP      this_player()
#define TO      this_object()

inherit "room/room";
object clomb;

reset(arg) {
  ::reset(arg);
  if(!arg) {

        set_light(1);
        short_desc = "The allegiance room of the Light Side.";     
        long_desc = "\
You stand in a brightly illuminated room with walls of white.  The light is almost \
blinding, making your vision blur, but the pedestal standing prominently in the centre \
of the room helps you to focus on your surroundings.  This is the room where the Jedi \
of the Light Side reaffirm their allegiances and the sense of compassion and warmth \
generated in here is overwhelming.  Some words written in chalk below the pedestal \
attract your attention.\n\n";


    property=({"no_telport","no_fight","no_steal"});

    smell="\nThe room smells clean and well kept.\n";



        dest_dir = ({
            "/players/mangla/guild/borrow",  "east",
        });


         items = ({
             "room", "A brilliantly illuminated room",            
             "walls", "The walls are made of marble, white and reflective.",
             "marble", "Imported Mos Eisley marble",       
             "surroundings", "A bright, illuminated room",
             "light", "The light is so intense you can barely see",
             "pedestal", "A large pedestal situated in the centre of the room",
             "words", "Some words written in chalk, perhaps you could 'read' them?",
             "chalk", "Some words written in chalk, perhaps you could 'read' them?",
             
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
  add_action("_east","east");
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


_east() {
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
    write("The rooom trembles a little.\n");
    say(this_player()->query_name() + " does not find the challenge of Light Side easy.\n");
    tell_room(this_object(), "A voice says: I'm sorry, but you must sacrifice more to truly be one with the Light Side.\n");
    return 1;
 }
  if(no > 2500 || no == 2500) {
    tell_room(this_object(), "A rainbow shines upon the room!\n");
    write("You pledge your allegiance to the Light Side of the Force.\n");
    this_player()->set_al(1+(no/10));
    return 1;
  } 
}


int _read(string str) {

  switch(str) {
    case "words" :
    case "chalk" :
    case "sign" : 
    case "etchings" : 
      {
        write("We, the followers of the Light Side of the Force, believe that\n");
        write("hate and anger are negative energies, denying us our full \n");
        write("potential.  We concentrate on self-preservation, and ensure\n");
        write("that every life we take serves a purpose in the greater scheme\n");
        write("of things.  To pledge your allegiance to us is costly, but in  \n");
        write("the battle of good over evil, what price success?\n");
        return 1;
       }
    
    default :
      write("What do you want to read?\n");
      return 0;
  }
}



