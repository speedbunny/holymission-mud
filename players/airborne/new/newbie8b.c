/* 971014, Uglymouth: uses /room/doorroom.c now + general code upgrade.
 */
#include <doorroom.h>

inherit DOOR_ROOM;

void reset( int arg ) {
  ::reset( arg );
  if( arg ) return;

  set_light( 1 );
  short_desc = "Complete newbie area";
  long_desc = "   Very good! You passed another test. Now we will move "
    + "on to the fun stuff, fighting!\n"
    + "   There are many monsters on Holy Mission, each with its own unique "
    + "qualities. How difficult it is to kill a monster will depend "
    + "greatly on many factors including; your level, your stats, the "
    + "equipment you are using and of course, the monster itself. Some "
    + "monsters have special ways to be defeated.\n"
    + "   The command you will need to use is: kill <monster name>. If "
    + "there are more than one of any particular type of monster, it "
    + "will automatically kill the first one. If you want to kill the "
    + "second one first, you would just add the number 2 afterwards.\n"
    + "   Before going into battle, you should set your wimpy. Wimpy is "
    + "a command that automatically makes you flee a room when you loose "
    + "a certain amount of hit points. This will save you from death, "
    + "most of the time. Don't rely only on wimpy! The command is as "
    + "follows: wimpy <percentage> where the percentage is the percentage "
    + "of hit points you will have left before you run from the room. "
    + "You will have to set your wimpy in order to leave this lesson.\n\n"
    + "     When you are ready, exit lesson 8.\n";
  dest_dir = ({
    "/players/airborne/new/newbie8", "south",
  });
  items = ({
    "door", "dummy door description",
  });
  property = ({
    "no_tport_in",
    "no_tport_out",
    "no_steal",
  });
  no_obvious_msg = "";
}

void init() {
  ::init();
  add_action( "wimpy", "wimpy" );
  add_action( "leave","leave" );
  add_action( "next", "lesson" );
}

int wimpy( string str ) {
  if( !str ) {
    printf( "You have to give the percentage of hp you want to flee at.\n" );
    return 1;
  }
  if( str == "0" ) {
    write( "That will not be useful at all.\n" );
    return 1;
  }
  if( !present( "wimpyobj", this_player() ) ) {
    object obj;
    obj=clone_object( "obj/treasure" );
    obj->set_id( "wimpyobj" );
    obj->set_name( "wimpyobj" );
    obj->set_weight( 0 );
    obj->set_value( 0 );
    transfer( obj, this_player() );
  }
  return 0;
}

int leave() {
  printf( "You stop the lessons and leave.\n"
    + "Please mail Airborne with any comments or sugesstions." );
  this_player()->move_player( "after stopping the lessons#"
    + "players/airborne/new/station");
  return 1;
}

int next( string str ) {
  object ob;

  if( !str ){
    write( "What lesson?\n" );
    return 1;
  }
  if( str != "8" ) {
    printf( "You are not ready for that lesson yet.\n" );
    return 1;
  }
  ob = present( "wimpyobj", this_player() );
  while( ob ) {
    destruct(ob);
    ob = present( "wimpyobj", this_player() );
  }
  this_player()->move_player( "lesson 8#/players/airborne/new/newbie9" );
  return 1;
}
