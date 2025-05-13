
inherit "/obj/monster";
       

#define OBJ "/players/whisky/seaworld/obj/"
#define TO this_object()

void reset (int arg) 
{
   string *chat_str, *a_chat_str;
  ::reset(arg);

  if (arg) return;


     chat_str = ({ "The sailor is singing about monsters and the sea.\n",
                   "HICKKKKKKK\n",
      "The sailor says: These shlarks, never fffound any fliendier flish.\n",
                  "HICKKKKKKK\n",
      "The sailor says: Isch lovsch schose fline oschlives on the ischland.\n",
      "HICKKKKKKKK\n",
      "The sailor says: Schiss oil iscch fine.\n",
      "HICKKKKKKKKK\n",
      "The sailor says: Butt schisss damsch draschon, dischnt like mesch.\n",
      "The sailor says: Schlimschd the sclandbank and sche bushes HO HO.\n",
      "The sailor shouts: And I schlayed this bigschhhh draschon.\n",
      "The sailor shouts: I schhhllayed themm allll.\n"});
   a_chat_str = ({ "The sailor shouts: Isch kill youuu schtranscher\n",
                    "The sailor hits your arm with his bottle\n",
                    "The sailor shouts: Isch killled oaschersc thann youuu\n",
                    "The sailor hits your head with his bottle\n",
                   "The sailor shouts: Rrrum awaisch youuu fooll\n"});

    set_name("sailor");
    set_alias("drunken sailor");
    set_short("A drunken Sailor");
    set_long("An old friendly looking sailor sitting on a stone\n"+
              "and drinking beer.\n");
    set_gender(1);
    set_race("human");
    set_level(8);
    set_al(100);
    set_whimpy();
    load_chat(20,chat_str);
    load_a_chat(40,a_chat_str);
    
    move_object(clone_object(OBJ+"sailors_sword"),TO);
    move_object(clone_object(OBJ+"jacket"),TO);
    move_object(clone_object("/players/whisky/obj/knock_scroll"),TO);
    move_object(clone_object(OBJ+"rucksack"),TO);
    move_object(clone_object(OBJ+"beer"),TO);
    init_command("wear jacket");
    init_command("wield sword");
}
