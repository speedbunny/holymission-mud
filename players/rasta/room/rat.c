inherit "room/room";
object tooth;
object rat;
reset(arg)
{
rat = clone_object("obj/monster");
if (!present(rat)) {
rat->set_name("rat");
rat->set_short("A Rat");
rat->set_long("A clear, medium sized rat.\n");
rat->set_race("Woodland creature");
rat->set_hp(20);
rat->set_ep(20);
rat->set_al(0);
rat->set_ac(1);
move_object(rat,this_object());
tooth = clone_object("obj/weapon.c");
tooth->set_name("tooth");
tooth->set_short("A Rat tooth");
tooth->set_long("A dirty yellow rat tooth. I looks quit sharp though. \n");
tooth->set_class(6);
tooth->set_weight(1);
tooth->set_value(10);
rat->init_command("wield tooth");
move_object(tooth,rat);
}
if(!arg)
{
  set_light(1);
   short_desc = "You are outside a church";
   long_desc = "You are in the middle of a clearing. There is a \n"+
                "a small hut here. \n";
   no_castle_flag = 0;
   dest_dir =
   ({
      "players/mad/castle/field1.c","south",
"players/mad/castle/roof1.c","roof",
"players/mad/castle/hut1.c","enter",
   });
   }
}
