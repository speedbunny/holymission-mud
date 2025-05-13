/* 230793 Galadriel: load of typos fixed */
inherit "room/room";

#include "/players/tamina/defs.h"

int trap;

void reset(int arg) 
{
  ::reset(arg);
  trap = 0;
  if (arg) return 0;

    set_light(0);
    short_desc = "Dark Cave";
    long_desc =
"The cave turns north here. The floor and walls have been cut and\n"+
"shaped by tools. It is quite different than the natural cave\n"+
"you had been traveling through.  @@chk_pit@@";

    dest_dir = ({
      TFROST + "cave14", "north",
      TFROST + "cave12", "west"
    });

    items = ({
  "dust",
"Just plain and simple dust",
  "walls",
"Just plain and simple walls",
    });
}

id(str) {
  if(::id(str)) return 1;
 return (str == "pit" || str == "floor" || str == "trap");
}

void init() 
{
  add_action("search",  "search");
  add_action("north",   "north");
  add_action("down",    "down");
  add_action("jump",    "jump");
  add_action("my_look", "l");
  add_action("my_look", "look");
  add_action("my_look", "exa");
  add_action("my_look", "examine");
  ::init();
}

string chk_pit()
{
  if (trap) 
    return "There is a large pit in the centre of the room.  "+
           "A small ledge runs around it.\n";
  else
    return "\n";
}

int my_look(string str) 
{
  if (str == "pit" || str == "at pit")
  {
    if (!trap)
    {
      write("You see nothing of interest.\n");
      return 1;
    }
    write("This is a large pit in the center of the room.\n"+
          "A small ledge runs around the edge of it.\n"+
          "It is very deep and to dark to see into.\n");
    say(TPN+" looks at the pit.\n");
    return 1;
  }
  if (str == "ledge" || str == "at ledge")
  {
    if (!trap)
    {
      write("You see nothing of interest.\n");
      return 1;
    }
    write("This is a ledge that runs round the pit.\n"+
	  "You think it will enable you to just go north now.\n");
    say(TPN+" looks at the pit.\n");
    return 1;
  }
  if (str == "floor" || str == "at floor") 
  {
    if (trap) 
    {
      write("You can easily see the pit trap.\n");
      return 1;
    } 
    else if (random(6) >= 3) 
    {
      write("You find a pit trap!!!\n");
      say(TPN+" finds a pit trap!\n");
      trap = 1;
      return 1;
    }  
    else 
    {
      write("All you see is dust.\n");
      say(TPN+" looks at the floor.\n");
      return 1;
    }
  }
}

int search(string str) 
{
  if (str == "floor" || str == "cave")
  {
    if (trap)
    {
      write("You can easily see the pit trap in the room.\n");
      return 1;
    }
    say(TPN+" searches the floor.\n");
    if (random(6) >= 3) 
    {
      write("You find a pit trap!\n");
      say(TPN+" finds a pit trap!\n");
      trap = 1;
      return 1;
    }
    write("You see nothing but dust.\n");
    return 1;
  }
  else
  {
    NFAIL("Search what?\n");
    return 0;
  }
}

int north()
{
  if (!trap) 
  {
    write("As you leave north, you step upon a counterbalanced floor stone.\n");
    say("As "+TPN+" leaves north, "+TP->QPRO+" sets off a trap!!!\n");
    trap = 1;
    call_out("do_move", 3);
    return 1;
  }
}

int down() 
{
  write("You'd have to be crazy to jump in a hole like that!\n"+
        "But if you really want to do it, type 'jump'\n");
  return 1;
}

int jump() 
{
  write("Boy! You really are crazy!\n");
  MPL("into a pit !!#/players/tamina/teds/frost/pit");
  write("You jump\n"+
        "          D\n"+
        "           O\n"+
        "            W\n"+
        "             N\n"+
        "                into the pit!\n\n\n");
  say(TP->QPRO+" lands with a SPLAT!!!\n");

  HIT(100 + random(50));
  return 1;
}
  
int do_move() 
{
  object next, temp;
  next = first_inventory(TO);
  while(next) 
  {
    temp = next_inventory(next);
    if (living(next)) 
    {
      if (!next->query_npc())
      TOBJ(next,"Suddenly the floor opens up and you fall into a deep pit!!!!!\n");
      TRM(TFROST + "pit", next->NAME+" hits the bottom with a thud!\n");
      MPL("suddenly downwards !!#players/tamina/teds/frost/pit");

      next->hit_player(40);
      TOBJ(next,"You hit the bottom with a thud!\n");
    }
    next = temp;
  }
  return 1;
}
