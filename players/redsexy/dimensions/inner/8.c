inherit "room/room";

void reset(int arg) {     
    if(!arg) {
 
       set_light(1);

  short_desc="A quiet place below the chambers.";
  long_desc="\
Decorated entirely in black, this room is very quiet and calm.  \
The walls and floor are lined with a soft, velvety material, \
and a dim light shines in from the incubator room.  There are no \
decorations here, and it doesn't look as if anyone has ventured \
this way for a while. \n\n";

  dest_dir=({"/players/redsexy/dimensions/inner/chamber","southeast",
          });


  items=({"room","A quiet room decorated in black",
          "walls","The material that lines these walls is soft to the touch",
          "material","It seems to be velvet",
          "light","Light shines in from the incubator room",
          "incubator","That was in the room you just left...",
          "floor","It is carpeted with a velvety material",
         });
   
    }
    ::reset(arg);
}

init() {

  ::init();

if(present("violetchute", this_player())) {
   object violetchute;
   violetchute=present("violetchute", this_player());
   write("You feel you are really helping Sophillicus.\n");
   destruct(violetchute);
   move_object(clone_object("/players/redsexy/dimensions/quest/violetcocoon"), this_object());
  }  
}

