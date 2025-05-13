#pragma strict_types
inherit "obj/board";

void move(object o)
  {
  move_object(this_object(),o);
  }

void reset(int arg)
  {
  ::reset(arg);
  if(arg) return;
  set_name("what to do on Padrone's code");
  set_file("/players/nokey/boards/padr_todo");
  }

int read_msg(string str)
  {
  if ((int)this_player()->query_level() < 30)
    {
    notify_fail("You are not allowed to read notes on this board.\n");
    return 0;
    }
  return (int)::read_msg(str);
  }
