

/* main_shop */

inherit "/room/room";


void reset(int arg) 
{
  ::reset(arg);
  if (arg!=0) return;
     set_light(1);
     short_desc = "In Sleepy's Store";
     long_desc = "This is the Store Room of Sleepy's shop";
}

