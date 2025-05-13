
/* dungeon corridor */

inherit "/room/room";
#include "defs.h"

int a, b, c;
int barrier;

void reset(int flag)
{
     ::reset(flag);
     a = 1 + random(5);
     b = 1 + random(5);
     c = a + b;
     barrier = 1;
     if (flag == 0)
     {
         set_light(0);
         short_desc ="A dungeon corridor";
         long_desc = BS(
          "You are standing on the end of the drawbridge. To the "+
          "south you can see a glowing magic barrier. On the barrier is "+
          "a runed covered inscription.");
         items =
         ({
            "bottom","The bottom is made of fouly, wooden lathes",
            "ceiling","The ceiling id made if red bricks",
            "walls","The walls are made of red bricks",
            "barrier","@@query_barrier@@",
            "inscription","This must be the number of the Beast !\n"+
                          "The number you read is: "+"@@show_number@@"+"\n"+
                          "It might be possible to change the numbers:\n"+
                          "Syntax: move 1 to 2 or 2 to 3 ....",
                          
         });
         dest_dir =
         ({
             PATH+"guard_room","north",
             PATH+"cell1","south",
         });
      }
}

string query_barrier()
{
    if (barrier)
        return "A magic runed covered barrier to the south";
    return "You don't see any barrier here, the way to the south is free";
}

string show_number()
{
    return "1:("+to_string(a)+") 2:("+to_string(b)+") 3:("+to_string(c)+")";
}

void init()
{
     add_action("fcn_move","move");
     ::init();
}

int fcn_move(string arg)
{
   object stick;

   stick = present("small magic stick",this_player());

    if (!arg)
        return 0;
    if (!stick)
    {
        write("Outch, you burn your fingers on the runes !\n");
        return 1;
    }
    switch(arg)
    {
       case "1 to 2":
         if (a < b)
         {
             a = 1; 
             b = b + a;
         }
         a--;
         b++;
         c++; 
         write("The runes changed !\n");
         break;
       case "2 to 1":
         if (b < a)
         {
             b = 1; a = a - b;
         }
         a++;
         c--; 
         b--;
         write("The runes changed !\n");
         break;
       case "2 to 3":
         if (b < c)
         {
             b = 1; c = c + b;
         }
         b--;
         c++;
         a++; 
         write("The runes changed !\n");
         break;
       case "3 to 2":
         if (c < b)
         {
             c = 1; 
             b = b - c; 
         }
         c--;
         b++;
         a--; 
         write("The runes changed !\n");
         break;
       case "1 to 3":
         if (a < c)
         {
             a = 1; 
             c = c + a;
         }
         c++;
         b--;
         a--; 
         write("The runes changed !\n");
         break;
       case "3 to 1":
         if (c < a)
         {
             c = 1; 
             a = a - c;
         }
         c--;
         b++;
         a++; 
         write("The runes changed !\n");
         break;
      default: return 0;
    }
  if (a==6 && b==6 && c==6)
  {
     write("The barrier vanishes !\n");
     destruct(stick);
     barrier = 0;
  }
  printf(show_number()+"\n");
  return 1;
}

int move(string arg)
{

    if (!arg)
        arg = query_verb();

    if (arg == "south" && barrier)
    {
        write("Autch, you run against a magic barrier.\n");            
        return 1;
    }
    return ::move(arg);
}

         


        
