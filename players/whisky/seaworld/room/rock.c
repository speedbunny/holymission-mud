

#define PATH "/players/whisky/seaworld/room/"

inherit "room/room";
#include "/players/whisky/genesis/sys/break_string.h"
#include "/players/whisky/genesis/sys/filter_live.h"

object sailor;
void reset(int arg) 
{
  if (!sailor)
  {
       sailor = clone_object("/players/whisky/seaworld/monster/sailor");
       move_object(sailor,this_object());
  }

if (arg) return;
  set_light(1);
  short_desc = "On a rock";
  long_desc = break_string(
     "You are standing on a big rock in the sea. " +
     "The wind is softly blowing through your hair. " + 
     "An old sailor is sitting here, watching the sea. " +
     "There is a big rope hanging down to the sea, so that you " + 
   "can risk to jump down into the waves.\n",60);

  items = ({  
    "rock","You see a big black rock standing in the sea",
    "rope","You see a long brown rope hanging down to the sea",
    "sea","You see the blue sea and the waves rolling up the rock"});

  dest_dir = ({
    PATH+"path_end", "west",
    "/players/warlord/trans/port4", "up", });
 }

init() {
  ::init();
     add_action("jump","jump");
  }

int jump(string str) 
{
    write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
    write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
    write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
    write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
    write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
    write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
    write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
    write("****  Y o u    a r e    f a l l i n g  ****\n\n\n\n");
    
    this_player()->move_player("down#"PATH+"sw1");
   return 1; 
}
