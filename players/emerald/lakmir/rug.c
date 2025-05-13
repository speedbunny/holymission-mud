/* Uglymouth, 970721: Recoded for use with inheritable door room.
 */
#define TP this_player()
#define TPN this_player()->query_name()

inherit "/obj/thing";

reset(arg) {
  if (arg) return ;
  set_name("rug");
  set_short("A rug");
  set_long("A finely woven rug in an Elven design.  There is a slight\n" +
           "bulge in the middle of it, although you can't pick it up to\n " +
           "see what's under it because it is nailed to the floor.\n " +
           "However, the rug is highly flammable...\n");
  set_can_get(0);
}

object create_key() {
  object key;
  key = clone_object( "/obj/thing" );
  key->set_name( "key" );
  key->set_alias( "crafted key" );
  key->set_alt_name( "rw1" );
  key->set_short("A crafted key");
  key->set_long( "A crafted key. You wonder where it fits...\n" );
  key->set_weight( 3 );
  key->set_value( 10 );
  return key;
}

void init() {
  ::init();
  add_action("_burn","burn");
  add_action("_burn","light");
}

_burn(str) {
  object torch, key;

  switch(str) {
    case "rug with torch" :
      if (torch=present("torch",this_player())) {
        if (!torch->id("lighted_torch")){
          write("Perhaps you ought to light the torch?\n");
          return 1;
        }
      } 
      else {
        write("You need a torch to burn the rug.\n");
        return 1;
      }
      write("You burn the rug with the torch and find a key.\n");
      say(TPN + " burns the rug with a torch.\n");
      move_object( create_key(), environment(this_object()) );
      destruct(this_object());
      return 1;
    case "rug with" :
    case "rug" :
      if(!present("torch",TP)) {
        write("You need a torch to burn the rug.\n");
        return 1;
      }
      notify_fail("Burn rug with what?\n");
      return 0;
    default :
      notify_fail("Burn what?\n");
      return 0;
  }
}

