#define NAME "tuppence"
inherit "room/room";
int lock;

#define CNAME   capitalize(NAME)

// This procedure is called periodically to check for monsters
//    which need to be replaced or other values that need
//    to be reset.

void reset(int arg) {

// Here you call the the reset in the inherited "room/room"
    ::reset(arg);

// First we need some light in here
    set_light(1);
  lock = 0;
// Then lets set a short description in case we are in brief-mode
    short_desc=CNAME + "'s workroom",

// Now the long standard room description
//    change this to fit your style
    long_desc=
              "This is the workroom of "+CNAME+".\n" +

          "Just my workroom, not much to see.\n";
// We need some exits too ... lets set the destination directions
    dest_dir=({
               "room/post", "post",
               "room/church", "church",
               "room/adv_guild", "guild", 
             });

// Item descriptions can be placed in here
    items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
          });

// Properties can be set like the following
    property = ({
                 "no_teleport","no_sneak","no_steal",
               });

//    The replace program will keep the room updated
//    without further function calls
}

init() {
    ::init();
  add_action("_lock","lock");
  if (this_player()->query_real_name() != "tuppence") {
    if (lock == 1) {
      tell_object(this_player(),"Tuppence does not wish to be disturbed right now!\n");
    tell_object(find_player("tuppence"),this_player()->query_real_name()+" tried to enter your workroom.\n");
      move_object(this_player(),"/room/church");
    }
  }
}

_lock() {
  if (lock == 1) {
    write("You unlock your workroom!\n");
    lock = 0;
    return 1;
  }
  if (lock == 0) {
    write("You lock your workroom up!\n");
    lock = 1;
    return 1;
  }
  return 1;
}
