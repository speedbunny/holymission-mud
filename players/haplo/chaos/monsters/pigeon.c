inherit "obj/monster";

int count;

reset(arg)
{
 ::reset(arg);
 if(!arg)
 {
  count=0;
  set_name("pigeon");
  set_short("A pigeon");
  set_long("An annoying looking pigeon.\n");
  set_level(random(5)+5);
  set_gender(random(2)+1);
  add_money(random(150)+50);
  set_al(random(100)-random(300));
  set_whimpy(70);
  load_chat(20,({ "Pigeon coos annoyingly.\n",
	"Pigeon flutters its wings irritatingly.\n",
        "Pigeon probably wonders where it is at.\n",
        "Pigeon jumps at a sound nearby.\n",
       }));
  move_object(clone_object("/players/kbl/objs/kblnote"),this_object());
 }
}
heart_beat()
{
  if(count++ > 4)
  {
    random_move();

    count = 0;
  }
  ::heart_beat();
}
