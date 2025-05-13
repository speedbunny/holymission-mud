 
inherit "room/room";

reset(arg) { 
string chats,a_chats;
object creature,pelt,cx;

   tell_room("/players/rasta/room/wind1",
  "You hear strange noises from the west. Shivers run down your spine.\n");
    if (!arg) {
	set_light(0);
dest_dir=({"players/rasta/room/alley1","south",
           "players/rasta/room/wind1","east"});
short_desc="Obscure vault";
  long_desc=
 "Human bones cover the stony soil of this obscure vault.\n"
+ "The sinister twilight makes you shiver.\n";
    }

    if (!chats) {
chats = allocate(4);
chats[0] = "You smell a diabolic stench.\n";
chats[1] = "The stench makes you shiver.\n";
chats[2] = "The creature seems to be hungry.\n";
chats[3] = "The creature eyes you waryly.\n";
    }

    if (!a_chats) {
  a_chats= allocate(3);


a_chats[0] = "The creature rips out your guts.\n";
  a_chats[1] = "Think about what you are doing.\n";
a_chats[2] = "Life is so precious. When you die you don't come back!!!\n";
    }

  if ((creature=present("affliction")) && living (creature)) return;

 creature=clone_object("/obj/monster");
creature->set_name("affliction");
creature->set_alias("creature");
   creature->set_level(30);
 creature->set_hp(500);
  creature->set_sp(500);
  creature->set_ep(777777);
 creature->set_ac(50);
  creature->set_wc(50);
  creature->set_al(-1000);
 
  creature->load_chat(20,chats);

  creature->load_a_chat(80,a_chats);
  creature->set_short("A maldorous affliction");
  creature->set_long("This abominable creature looks *real* dangerous.");
creature->set_aggressive(1);


  cx=clone_object("/obj/treasure");
  cx->set_id("pelt");
  cx->set_short("The malodorous affliction's pelt");
  cx->set_value(900);
 
  move_object(creature,this_object());
  move_object(cx,creature);
  return 1;
}
