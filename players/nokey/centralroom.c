/* a central room: connects all workrooms together if the workroom has
the line: int connected_to_center() { return 1; }
in it. An exit TO this room is nice as well of course ;) */
/* Coded by Nokey on Callandor III, transported to HM 060794 */

inherit "/room/room";

#pragma strict_types
#pragma save_types
#define TO tell_object

void set_exits();

int press(string s)
  {
  int a;
  mixed all;
  if(s == "reset" || s == "reset button")
    {
    tell_room(this_object(),this_player()->query_name() +
    " presses the reset button. All exits are now reset.\n");
    set_exits();
    no_obvious_msg = 0;
    all = all_inventory(this_object());
    for(a=0;a<sizeof(all);a++)
      {
      if(living(all[a]))
        move_object(all[a],this_object());
      }
    return 1;
    }
  notify_fail("Press what?\n");
  return 0;
  }

void set_exits()
  {
  int a,b;
  mixed f, temp;
  string wiz, workroom;
  f = get_dir("/players/*");
  b = 0;
  temp = allocate((sizeof(f) -2)*2);
  for(a=2;a<sizeof(f);a++)
    {
    wiz = (string)f[a];
/* seems this takes too long to evaluate :( */
/*
    if (file_size("/players/"+ wiz) == -2)
      {
*/
    workroom = "/players/"+ wiz +"/workroom";
    if(!catch(workroom->short()))
    if(workroom->connected_to_center())
      {
      temp[b] = workroom;
      b++;
      temp[b] = wiz;
      b++;
      }
/*
      }
*/
    }
  dest_dir = allocate(b);
  for(a=0;a<b;a++)
    dest_dir[a] = temp[a];
  }

void reset(int arg)
  {
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Central room";
  long_desc = "This is the central room, which connects all workrooms"+
  " of wizards to one another (if they want to connect to it of "+
  "course).\nThere is a reset button here that will reset all exits.\n";
  set_exits();
  items = ({
            "button","A reset button, activate by 'press reset'",
            "reset button","A reset button, activate by 'press reset'",
          });
  }

void init()
  {
  add_action("press","press");
  add_action("press","push");
  ::init();
  }
