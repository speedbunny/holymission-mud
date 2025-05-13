#define TP    this_player()
#define TPN   TP->query_name()

inherit "room/room";

void reset(int arg) {     
    if(!arg) {
 
       set_light(1);

  short_desc="The corridor of the dimension halls.";
  long_desc="\
You stand in a corridor of the dimension halls, decorated in black \
and mysteriously quiet.  Legend has it that this is the realm where \
demons train their skills before being born into the world we know as \
the Holy Mission.  Light shines up from a chute in the centre of the room, \
illuminating the glass walls that surround you. \n\n";

  dest_dir=({"/players/redsexy/dimensions/connect/chamber","northeast",
             "/players/redsexy/dimensions/blue/1","southwest",
          });


  items=({"halls","The dimension halls of Sophillicus",
          "chambers","Glass rooms with magical properties where demons train",
          "corridor","You see your own reflection",
          "walls","The walls are made of mirrored glass",
          "light","A mystical light is reflected off the mirrors",
          "glass","Glass from which the chambers are built",
          "chute","A narrow glass chute, big enough for a cocoon",
         });
     }
   
    ::reset(arg);
}

void init(){
   add_action("_put","move"),
   add_action("_put","place"),
   add_action("_put","push"),
   add_action("_put","lay"),
   add_action("_put","drop"),
   add_action("_put","put"),
   ::init();
}

int _put(string str) {
object bluequestob, bluechute;


  switch(str) {
    case "blue cocoon in chute" :
    case "blue cocoon down chute" :
    case "blue coccon into the chute" :
    case "blue cocoon into chute" :
    case "blue cocoon down the chute" :
    case "blue coccon in the chute":
    bluecocoon = present("bluequestob", TP);
    if(bluecocoon) {
        write("You put the blue cocoon into the chute.\n");
        say(TPN + " puts the blue cocoon in the chute.\n");
        bluechute = clone_object("players/redsexy/dimensions/quest/chute");
        transfer(bluechute, this_player());
        bluechute->set_type("blue");
        destruct(bluecocoon);
        return 1;
      }
    case "cocoon in chute" :
    case "cocoon down chute" :
    case "coccon into the chute" :
    case "cocoon into chute" :
    case "cocoon down the chute" :
    case "coccon in the chute":
      write("Which cocoon do you want to put in the chute?\n");
      return 1;
    default :
      write("What do you want to put where?\n");
      return 1;
  }
}

