inherit "obj/armour";

object broken;

reset(arg)
{
 ::reset(arg);
 if (!arg) 
 {
  set_name("skates");
  set_short("A pair of skates");
  set_long("They are sharp skates made for figure skating.\n");
  set_value(20);
  set_weight(2);
  set_ac(1);
  set_type("boot");
  call_out("check",50);
 }
}

check() {
  if (able()) {
    if (!environment(this_player())->query_property("on_ice")) {
      write ("Your skates become worthless!\n");
      broken = clone_object("/players/cashimor/objects/broken");
      move_object(broken,this_player());
      destruct (this_object());
      return 1;
    }
  }
  call_out("check",50);
}
init()
{
 ::init();
 add_action("skate","skate");
 add_action("jump","jump");
}

get()
{
 return 1;
}

skate()
{
 if (!able()) return 0;
 if (!environment(this_player())->query_property("on_ice")) return 0;
 say(call_other(this_player(),"query_name")+" skates a little.\n");
 write("You skate a little.\n");

 return 1;
}

jump()
{
 if(!able()) return 0;
 if(!environment(this_player())->query_property("on_ice")) return 0;
 write("You make a fabulous double axle!\n");
 say(call_other(this_player(),"query_name")+" makes a fantastic double axle!\n");
 return 1;
}

able()
{
 if (!(present(this_object(),this_player()))) return 0;
 if (!(this_object()->query_worn(0))) return 0;
 return 1;
}

