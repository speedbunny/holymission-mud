#include "std.h"

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
#undef EXTRA_INIT
#define EXTRA_INIT extra_init();

#define TPRNAME (this_player()->query_real_name())

FOUR_EXIT("room/church","church","players/rasta/room/bulletin","board",
          "obj/tick", "tick", 
    "/players/rasta/room/entrance", "east",
	  "Rasta's residence",
"You are in Rasta's one-room shack, built up over a ditch that drains the\n"
+ "sewage of the neighborhood. The air is thick with the smoke of cooking\n"
+ "fires and the stink of urine. Lit only by the occasional flickering oil\n"
+ "lamp in the window this place looks like a desolate war zone of zinc,\n"   
+ "cement, and spit. Looking out of the window by day you see a maze of \n"
+ "sodden shacks, scorched earth, and lush tropic shrubbery.\n"
+ "The Wizard used to operate here in a haze of ganja and hallucinogenic\n"
+ "white rum and when the pressure drops on him he indulges in haphazard,\n"
+ "almost slap-stick violence toward everyone who happens to be around and\n"
+ "unarmed.",1) 


object tracer,camera;
int is_locked;

extra_reset() {
    if (!tracer) {
	tracer = clone_object("/obj/trace");
	move_object(tracer, this_object());
    }
    if (!camera) {
	camera = clone_object("players/herp/obj/camera");
	move_object(camera, this_object());
    }
}

extra_init() {
   add_action("lock","lock");
   add_action("unlock","unlock");
   add_action("fall","fall"); 
   if (TPRNAME!="rasta" && is_locked) {
      tell_object(this_player(),"The room is currently locked. You are moved to the church.\n");
      move_object(this_player(),"room/church");
   }
}
fall() {
object fall_room;

  fall_room=clone_object("/players/herp/falling");
  this_player()->move_player("up the rope",fall_room);
  return 1;
}

lock() {
  if (query_myself()) {
     is_locked=1;
     say("Rasta locked the room.\n"); 
  } 
  return 1;
}

unlock() {
  if (query_myself()) {
      is_locked=0;
      say("Rasta unlocked the room.\n"); 
  } 
  return 1;
}

query_myself() {
  if (TPRNAME!="rasta") {
     write("Only one can do that here.\n");
     return 0;
  }
  return 1;
}

