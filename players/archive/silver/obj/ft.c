/*
  Coded by Silver Sun 02-19-1995 
  Last edit : Silver Tue 1995-03-14 18:23:50  
*/

#pragma strict_types
#pragma save_types

inherit "/obj/thing";

int _here()
 {
  string fname;
  if(!fname=file_name(environment(this_player())))
   {
    write("Sorry you can't get to that file ! \n");
    return 1;
   }

  fname="/"+fname+".c";
  write(fname+"\n");
  this_player()->more_string(read_file(fname));
  return 1;
 }

void reset(int arg)
 {
  ::reset(arg);
  if(arg) return;
  set_name("ft");
  set_short("ft");
  set_long("try 'here'");
  set_weight(0);
 }

void init()
 {
  ::init();
  add_action("_here","here");
 }
