#define NAME "tatsuo"
inherit "room/room";

#define CNAME   capitalize(NAME)

// This procedure is called periodically to check for monsters
//    which need to be replaced or other values that need
//    to be reset.

void reset(int arg) {

// Here you call the the reset in the inherited "room/room"
    ::reset(arg);

// First we need some light in here
    set_light(1);
 

// Then lets set a short description in case we are in brief-mode
    short_desc=CNAME + "'s workroom",

// Now the long standard room description
//    change this to fit your style
    long_desc=
         "This is Tatsuo's piece of shit workroom.  There appears to "
        "be only one feature in the entire room.  A large red button on the "
         "north wall reads 'DO NOT PUSH BUTTON'\n";
             

// We need some exits too ... lets set the destination directions
   
// Item descriptions can be placed in here
    items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
          });

// Properties can be set like the following
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });

}

init() {
    ::init();
   
    ;    add_action("_destme","press"); 
    add_action("_destme","push");
}
int _destme(string arg){
   
  if(arg=="button"){ 
  write("\nDumbass.\n\n");
  write("A disintegrator beam shoots from the ceiling into your brain.\n");  write("***** You were disintegrated *****\n");

  destruct(this_player());
  return 1;  
}
}

