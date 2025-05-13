#define TP      this_player()
#define TO      this_object()

inherit "room/room";
object clomb;

reset(arg) {
  ::reset(arg);
  if(!arg) {

        set_light(1);
        short_desc = "The allegiance room of the Dark Side.";     
        long_desc = "\
The blackness of this pentagonal room is oppressive.  The walls around you are \
draped with black velvet material and the only light seems to come from a pedestal \
situated in the centre of the room.  This is where the Dark Jedi come to re-affirm \
their allegiance to the Dark Side, and the evil that radiates from here is smothering.  \
Through the darkness, you can just make some etchings on the wall. \n\n";


        property=({"no_telport","no_fight","no_steal"});
 
        smell="\nThe acrid reek of ozone fills your nostrils.\n";


        dest_dir = ({
            "/players/mangla/guild/borrow",  "west",
        });


         items = ({
             "room", "A darkly decorated pentagonal room",            
             "walls", "Dark velvet drapes hang on the walls.",
             "material", "It is smooth to the touch, very velvety",       
             "velvet", "Black velvet, covering the walls",
             "light", "A dull light eminates from the centre of the room",
             "pedestal", "A large pedestal situated in the centre of the room",
             "evil", "This place seems very evil and untoward",
             "darkness", "Oppressive darkness",
             
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
  add_action("_west","west");
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


_west() {
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
    write("A flash of lightning strikes you from above.\n");
    say(this_player()->query_name() + " is struck by a flash of lightning.\n");
    tell_room(this_object(), "A voice says: You are not WORTHY of the Dark Side!\n");
    this_player()->hit_player(10+random(50));
    return 1;
 }
  if(no > 2500 || no == 2500) {
    tell_room(this_object(), "A flash of lightning brightens up the room!\n");
    write("You pledge your allegiance to the Dark Side of the Force.\n");
    this_player()->set_al(-1-(no/10));
    return 1;
  } 
}


int _read(string str) {

  switch(str) {
    case "plaque" :
    case "engraving" :
    case "sign" : 
    case "etchings" : 
      {
        write("The Dark Side is the powerful side, instilling fear into our \n");
        write("enemies and thwarting those who stand in our way.  Only the  \n");
        write("truly evil can know the full power of the Force, but to join \n");
        write("us will cost you dearly.  Stand on the pedestal, make your   \n");
        write("sacrifice, and pledge your allegiance to the Dark Side.  \n");
        return 1;
       }
    
    default :
      write("What do you want to read?\n");
      return 0;
  }
}



