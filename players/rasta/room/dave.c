inherit "room/room";
reset ( arg )
{
string * chat_str;
string * a_chat_str;
object mon;
if ( ! arg ) {
set_light ( 1 );
short_desc="Smokeroom";
long_desc="This is the smoke room, there is smoke everywhere!  You notice that it is very hard to both see and breath.\n";
dest_dir=({ "players/rake/den","south"});
}
if ( ! present ("Dave"))
{
move_object(clone_object("/players/rake/darkcloak"),this_object());
mon=clone_object ("obj/monster");
mon->set_name("dave");
mon->set_alia ("dave");
mon->set_alt_name("dave the smoker");
mon->set_level (7);
mon->set_short("Dave the smoker");
mon->set_long("This is Dave, he smokes and smokes and smoke and smokes!\n");
mon->set_hp (130);
mon->set_wc (10);
mon->set_ac (8);
mon->set_al (20);
mon->set_frog();
mon->set_male(2);
mon->set_ep (2000);
mon->set_random_pick (50);
chat_str=({"Dave blows smoke in your face!\n",
"Dave spits on your shoe!\n",
"Dave punches you in the eye!\n",
"Dave smokes a cigar!\n",
"Dave says....your a butthead!\n"});
a_chat_str=({ "Dave screams...You Butthead!\n",
"Daves says......Take you best shot!\n",
"Dave says........I'm gona get you Sucka!\n"});
mon->load_chat ( 10, chat_str);
mon->load_a_chat (25,a_chat_str);
move_object(mon, this_object());
}
}
