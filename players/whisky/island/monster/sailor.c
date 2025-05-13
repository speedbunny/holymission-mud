inherit "/obj/monster";

object sword, beer, jacket;
string chat_str, a_chat_str;

reset (arg) {
  ::reset(arg);
  chat_str = ({ "The sailor is singing about monsters and the sea.\n",
                 "HICKKKKKKK\n",
         "The sailor says: These shlarks, never fffound any fliendier flish.\n",
                  "HICKKKKKKK\n",
          "The sailor shouts: I schhhllayed themm allll.\n"});
   a_chat_str = ({ "The sailor shouts: Isch kill youuu schtranscher\n",
                    "The sailor hits your arm with his bottle\n",
                    "The sailor shouts: Isch killled oaschersc thann youuu\n",
                    "The sailor hits your head with his bottle\n",
                   "The sailor shouts: Rrrum awaisch youuu fooll\n"});
  if (arg) return 1;

    set_name("sailor");
    set_alias("drunken sailor");
    set_short("A drunken Sailor");
    set_long("An old friendly looking sailor sitting on a stone\n"+
              "and drinking beer.\n");
    set_race("human");
    set_level(8);
   set_al(100);
  set_whimpy();
    load_chat(20,chat_str);
    load_a_chat(40,a_chat_str);
    
  sword = clone_object("/players/whisky/seaworld/obj/sailors_sword");
  jacket = clone_object("/players/whisky/seaworld/obj/jacket");
  beer = clone_object("/players/whisky/seaworld/obj/beer");
    move_object(sword, this_object());
    move_object(jacket, this_object());
    move_object(beer, this_object());
    init_command("wear jacket");
  init_command("wield sword");
  return 1; }
