#pragma strict_types
#pragma save_types

void deliver()
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
    workroom = "/players/"+ wiz +"/workroom";
    if(!catch(workroom->short()))
    if(!workroom->connected_to_center())
      {
      if(wiz != "padrone")
        {
        tell_room(workroom,"A courier delivers an advertisement to this address.\n");
        move_object(clone_object("/players/nokey/advert"),workroom);
        }
      }
    }
  }

void reset(int arg)
  {
  if(arg) return;
  deliver();
  }

