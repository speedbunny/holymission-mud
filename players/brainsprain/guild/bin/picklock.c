/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+= Picklock +=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=*
 * Uglymouth 970717: Adapted code to allow using inheritable room with doors.
 */
// 201197: Sauron: Bug fix for when the room doesn't have a door in it.
#include <doorroom.h>

int picklock_old_door( object door, object thief, object pl );
int picklock_inheritable_door( string arg, object thief, object pl );
int check_skill( object thief, object pl );

int main(string arg) {
  string          dest, *arr;
  object          pl, door, thief;
  
  thief=this_player();
  if (thief->query_ghost()) {
    write("You could probably move right through that keyhole.\n");
    return 1;
  }
  
  if(thief->query_attack())
    if(present(thief->query_attack(),environment(thief))){
      write("You are much too busy for that right now.\n");
      return 1;
    }

  if (!arg){
    command("help picklock", this_player());
    return 1;
  }
  
  if (!(pl = present("picklock", thief))) {
    write("You don't have a picklock.\n");
    return 1;
  }
  if (pl->query_broken()) {
    /* It was broken ... get the next one */
    pl = next_inventory(pl);
    while (pl) {
      if (pl->id("picklock") && !pl->query_broken())
        break;                /* unbroken */
      pl = next_inventory(pl);
    }
    if (!pl) {
      write("Your picklock is broken.\n");
      return 1;
    }
  }
/* Uglymouth 970718: This prohibits picking locks of gates, trapdoors, etc.
  if (arg != "door" && sscanf(arg, "%s door", dest) != 1){
    write("You can't seem to find a lock in the "+arg+".\n");
    return 1;
  }
*/  
  if (!(door = present(arg, environment(thief)))){
    if( !( arr = environment( thief )->query_doors() ) ||
        member_array( arg, arr ) == -1 ) {
      write("You can't seem to find the door.\n");
      return 1;
    }
    return picklock_inheritable_door( arg, thief, pl );
  }
  if (arg == "door" && door->number_of_doors() != 1) {
    door->which_door();
    return 1;
  }
  return picklock_old_door( door, thief, pl );
}

int picklock_old_door( object door, object thief, object pl ) {
  if (!door->query_locked()) {
    write("You wisely decide not to waste your picklock" +
          " on an unlocked door.\n");
    return 1;
  }
  switch( check_skill( thief, pl ) ) {
    case 0:
      write( "CRACK! You curse as you break the picklock with your "
        + "bumbling fingers.\n" );
      return 1;
    case 1:
      write("You work the wire into the lock and after a few moments of"
        + " careful probing ...\nYou are met with success, but your"
        + "picklock broke.n" );
    break;
    case 2:
      write("You work the wire into the lock and after a few moments of"
        + " careful probing ...\nYou are met with success\n." );
    break;
  }
  door->set_locked(0);
  door->query_partner_door()->set_locked(0);
  return 1;
}

int picklock_inheritable_door( string arg, object thief, object pl ) {
  object env;

  env = environment( thief );
  if( env->query_lock_status( arg ) <= DOOR_UNLOCKED ) {
    write("You wisely decide not to waste your picklock"
      + " on an unlocked door.\n");
    return 1;
  }
  switch( check_skill( thief, pl ) ) {
    case 0:
      write( "CRACK! You curse as you break the picklock with your "
        + "bumbling fingers.\n" );
      return 1;
    case 1:
      write("You work the wire into the lock and after a few moments of"
        + " careful probing ...\nYou are met with success, but your"
        + "picklock broke.n" );
    break;
    case 2:
      write("You work the wire into the lock and after a few moments of"
        + " careful probing ...\nYou are met with success\n." );
    break;
  }
  env->set_lock_status( arg, DOOR_UNLOCKED );
  call_other( env->query_other_door( arg ), "set_lock_status", arg,
    DOOR_UNLOCKED );
  return 1;
}

/* Uglymouth 970718: With inheritable door room, code for checking lock 
     difficulty could be added, if so desired. */
int check_skill( object thief, object pl ) {
  int i;

  i = thief->query_dex() * 100 / 
    "guild/master"->query_levels("guild/master"->query_number("thief"));
  if (random(101) >= i) {
    pl->set_broken();
    return 0;  // failure, picklock broke.
  }
  if (random(101) >= i) {
    pl->set_broken();
    return 1;  // success, picklock broke.
  }
  return 2;  // success, picklock reusable.
}

